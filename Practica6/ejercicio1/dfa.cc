/**
 * Universidad de La Laguna, Grado en Ingeniería Informática
 * Computabilidad y Algoritima
 * Curso 26/27
 * @author Alfonso Reyes Núñez Fernández, alu0101784809@ull.edu.es
 * @date 13/10/2026
 * @file dfa.cc
 * @brief Implementación de la clase DFA para representar un Autómata Finito Determinista
 */

#include "dfa.h"

#include <fstream>
#include <iomanip>
#include <regex> 
#include <sstream>

DFA::DFA() : initial_state_identifier_(-1) {}

bool DFA::LoadFromFile(const std::string& filename) {
  std::ifstream input_file(filename);
  if (!input_file.is_open()) {
    std::cerr << "Error: No se pudo abrir el fichero del DFA: " << filename << std::endl;
    return false;
  }

  std::string line;
  const std::regex kCommentOrEmptyRegex(R"(^\s*(?://.*)?$)");

  auto ReadNextLine = [&input_file, &line, &kCommentOrEmptyRegex]() -> bool {
    while (std::getline(input_file, line)) {
      if (std::regex_match(line, kCommentOrEmptyRegex)) {
        continue;
      }
      return true;
    }
    return false;
  };

  if (!ReadNextLine()) return false;
  alphabet_.clear();
  const std::regex kSymbolRegex(R"([a-zA-Z0-9])");
  for (char symbol : line) {
    std::string symbol_str(1, symbol);
    if (std::regex_match(symbol_str, kSymbolRegex)) {
      alphabet_.insert(symbol);
    }
  }

  if (!ReadNextLine()) return false;
  const std::regex kNumberRegex(R"(^\s*(\d+)\s*$)");
  std::smatch match;
  if (!std::regex_match(line, match, kNumberRegex)) {
    std::cerr << "Error: Número total de estados inválido." << std::endl;
    return false;
  }
  int number_of_states = std::stoi(match[1].str());

  if (!ReadNextLine()) return false;
  if (!std::regex_match(line, match, kNumberRegex)) {
    std::cerr << "Error: Estado inicial inválido." << std::endl;
    return false;
  }
  initial_state_identifier_ = std::stoi(match[1].str());

  states_.clear();
  const std::regex kStateHeaderRegex(R"(^\s*(\d+)\s+([01])(?:\s+(.*))?$)");
  const std::regex kTransitionPairRegex(R"((\S)\s+(\d+))");

  for (int i = 0; i < number_of_states; ++i) {
    if (!ReadNextLine()) {
      std::cerr << "Error: El fichero finalizó antes de leer todos los estados." << std::endl;
      return false;
    }

    std::smatch header_match;
    if (!std::regex_match(line, header_match, kStateHeaderRegex)) {
      std::cerr << "Error: Formato de línea de estado inválido." << std::endl;
      return false;
    }

    int state_id = std::stoi(header_match[1].str());

    if (states_.find(state_id) != states_.end()) {
      std::cerr << "Error: El estado con ID " << state_id << " está duplicado en la definición del DFA." << std::endl;
      return false;
    }

    bool is_accepting = (header_match[2].str() == "1");
    State current_state(state_id, is_accepting);

    std::string transitions_part = header_match[3].str();
    auto transitions_begin = std::sregex_iterator(transitions_part.begin(), transitions_part.end(), kTransitionPairRegex);
    auto transitions_end = std::sregex_iterator();

    for (std::sregex_iterator iter = transitions_begin; iter != transitions_end; ++iter) {
      std::smatch trans_match = *iter;
      char transition_symbol = trans_match[1].str()[0];
      int destination_state_id = std::stoi(trans_match[2].str());

      if (alphabet_.find(transition_symbol) == alphabet_.end()) {
        std::cerr << "Error: El símbolo '" << transition_symbol << "' no pertenece al alfabeto en el estado " << state_id << "." << std::endl;
        return false;
      }
      current_state.AddTransition(transition_symbol, destination_state_id);
    }

    states_[state_id] = current_state;
  }

  if (states_.find(initial_state_identifier_) == states_.end()) {
    std::cerr << "Error: El estado inicial " << initial_state_identifier_ << " no existe en la definición de los estados." << std::endl;
    return false;
  }

  for (const auto& pair : states_) {
    const State& state = pair.second;
    for (char symbol : alphabet_) {
      if (state.HasTransition(symbol)) {
        int next_id = state.GetNextState(symbol);
        if (states_.find(next_id) == states_.end()) {
          std::cerr << "Error: Transición hacia un estado inexistente: " << next_id << std::endl;
          return false;
        }
      }
    }
  }

  return true;
}

bool DFA::SimulateString(const std::string& input_string, std::ostream& output_stream) const {
  int current_state_id = initial_state_identifier_;

  output_stream << std::left << std::setw(15) << "Est. Actual" << std::setw(15) << "Entrada" << std::setw(15) << "Nuevo Est." << std::endl;

  if (input_string == "&" || input_string.empty()) {
    bool is_accepted = states_.at(current_state_id).is_accepting();
    output_stream << "Cadena de entrada " << (is_accepted ? "ACEPTADA." : "RECHAZADA.") << "\n" << std::endl;
    return is_accepted;
  }

  for (char symbol : input_string) {
    if (alphabet_.find(symbol) == alphabet_.end()) {
      output_stream << "Símbolo '" << symbol << "' no pertenece al alfabeto." << std::endl;
      output_stream << "Cadena de entrada RECHAZADA.\n" << std::endl;
      return false;
    }

    const State& current_state = states_.at(current_state_id);
    if (!current_state.HasTransition(symbol)) {
      output_stream << "Sin transición definida." << std::endl;
      output_stream << "Cadena de entrada RECHAZADA.\n" << std::endl;
      return false;
    }

    int next_state_id = current_state.GetNextState(symbol);

    output_stream << std::left << std::setw(15) << current_state_id << std::setw(15) << symbol << std::setw(15) << next_state_id << std::endl;

    current_state_id = next_state_id;
  }

  bool is_accepted = states_.at(current_state_id).is_accepting();
  output_stream << "Cadena de entrada " << (is_accepted ? "ACEPTADA." : "RECHAZADA.") << "\n" << std::endl;

  return is_accepted;
}