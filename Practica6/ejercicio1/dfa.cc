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

#include <cctype>
#include <fstream>
#include <iomanip>
#include <sstream>

DFA::DFA() : initial_state_identifier_(-1) {}

bool DFA::LoadFromFile(const std::string& filename) {
  std::ifstream input_file(filename);
  if (!input_file.is_open()) {
    std::cerr << "Error: No se pudo abrir el fichero del DFA: " << filename << std::endl;
    return false;
  }

  std::string line;

  auto ReadNextLine = [&input_file, &line]() -> bool {
    while (std::getline(input_file, line)) {
      if (line.empty()) continue;
      size_t first_char = line.find_first_not_of(" \t");
      if (first_char != std::string::npos && line.compare(first_char, 2, "//") == 0) {
        continue;
      }
      return true;
    }
    return false;
  };

  if (!ReadNextLine()) {
    return false;
  }
  alphabet_.clear();
  for (char symbol : line) {
    if (!std::isspace(symbol)) {
      alphabet_.insert(symbol);
    }
  }

  if (!ReadNextLine()) {
    return false;
  }
  int number_of_states = std::stoi(line);

  if (!ReadNextLine()) {
    return false;
  }
  initial_state_identifier_ = std::stoi(line);

  states_.clear();
  for (int i = 0; i < number_of_states; ++i) {
    if (!ReadNextLine()) {
      std::cerr << "Error: El fichero finalizó antes de leer todos los estados." << std::endl;
      return false;
    }

    std::stringstream string_stream(line);
    int state_id, is_accepting_int;
    if (!(string_stream >> state_id >> is_accepting_int)) {
      std::cerr << "Error: Formato de línea de estado inválido." << std::endl;
      return false;
    }

    State current_state(state_id, is_accepting_int == 1);

    char transition_symbol;
    int destination_state_id;
    while (string_stream >> transition_symbol >> destination_state_id) {
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