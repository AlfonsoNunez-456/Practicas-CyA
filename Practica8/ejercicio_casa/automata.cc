/**
 * Universidad de La Laguna
 * Ingeniería Informática
 * Computabilidad y Algoritmia
 * Curso 26/27
 * @file automata.cc
 * @brief Implementacion de la clase automata
 * @author Alfonso Reyes Núñez Fernández, alu0101784809@ull.edu.es
 * @date 31/10/2026
 */

#include "automata.h"

#include <fstream>
#include <iostream>
#include <regex>  
#include <sstream>

Automata::Automata() : initial_state_identifier_(-1) {}

Automata::Automata(const std::string& filename) : initial_state_identifier_(-1) {
  LoadFromFile(filename);
}

bool Automata::LoadFromFile(const std::string& filename) {
  std::ifstream input_file(filename);
  if (!input_file.is_open()) {
    std::cerr << "Error: No se pudo abrir el fichero del DFA: " << filename << std::endl;
    return false;
  }

  std::string line;

  auto ReadNextLine = [&input_file, &line]() -> bool {
    while (std::getline(input_file, line)) {
      size_t first_char = line.find_first_not_of(" \t\r\n");
      if (first_char == std::string::npos ||
          line.compare(first_char, 2, "//") == 0) {
        continue;
      }
      return true;
    }
    return false;
  };

  if (!ReadNextLine()) return false;
  alphabet_.clear();
  std::stringstream alphabet_ss(line);
  char symbol;
  while (alphabet_ss >> symbol) {
    alphabet_.insert(symbol);
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
  for (int i = 0; i < number_of_states; ++i) {
    if (!ReadNextLine()) {
      std::cerr << "Error: El fichero finalizó antes de leer todos los estados." << std::endl;
      return false;
    }

    std::stringstream state_ss(line);
    int state_id, is_accepting_int, number_of_transitions;
    if (!(state_ss >> state_id >> is_accepting_int >> number_of_transitions)) {
      std::cerr << "Error: Formato de línea de estado inválido." << std::endl;
      return false;
    }

    if (states_.find(state_id) != states_.end()) {
      std::cerr << "Error: El estado con ID " << state_id << " está duplicado en la definición del DFA." << std::endl;
      return false;
    }

    State current_state(state_id, is_accepting_int == 1);

    for (int t = 0; t < number_of_transitions; ++t) {
      char trans_symbol;
      int destination_state_id;
      if (!(state_ss >> trans_symbol >> destination_state_id)) {
        std::cerr << "Error: Formato de transición inválido en el estado " << state_id << "." << std::endl;
        return false;
      }

      if (alphabet_.find(trans_symbol) == alphabet_.end() && trans_symbol != '&') {
        std::cerr << "Error: El símbolo '" << trans_symbol << "' no pertenece al alfabeto en el estado " << state_id << "." << std::endl;
        return false;
      }
      current_state.AddTransition(trans_symbol, destination_state_id);
    }

    states_[state_id] = current_state;
  }

  if (states_.find(initial_state_identifier_) == states_.end()) {
    std::cerr << "Error: El estado inicial " << initial_state_identifier_ << " no existe en la definición de los estados." << std::endl;
    return false;
  }

  return true;
}

Grammar Automata::ConvertToGrammar() const {
  std::set<char> terminals = alphabet_;
  std::set<std::string> non_terminals;
  std::vector<Production> productions;

  for (const auto& pair : states_) {
    non_terminals.insert("S" + std::to_string(pair.first));
  }

  std::string start_symbol = "S" + std::to_string(initial_state_identifier_);

  for (const auto& pair : states_) {
    int state_id = pair.first;
    const State& state = pair.second;
    std::string origin_non_terminal = "S" + std::to_string(state_id);

    for (const auto& transition : state.transitions()) {
      char symbol = transition.first;
      int destination_id = transition.second;
      std::string dest_non_terminal = "S" + std::to_string(destination_id);

      std::string right_hand_side = "";
      if (symbol != '&') {
        right_hand_side += symbol;
      }
      right_hand_side += dest_non_terminal;

      productions.push_back(Production(origin_non_terminal, right_hand_side));
    }

    if (state.is_accepting()) {
      productions.push_back(Production(origin_non_terminal, "&"));
    }
  }

  return Grammar(terminals, non_terminals, start_symbol, productions);
}