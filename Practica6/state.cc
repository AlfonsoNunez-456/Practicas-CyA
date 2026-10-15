/**
 * Universidad de La Laguna, Grado en Ingeniería Informática
 * Computabilidad y Algoritima
 * Curso 26/27
 * @author Alfonso Reyes Núñez Fernández, alu0101784809@ull.edu.es
 * @date 13/10/2026
 * @file state.cc
 * @brief Implementación de los métodos de la clase State para representar un estado en un DFA
 */

#include "state.h"

State::State() : identifier_(-1), is_accepting_(false) {}

State::State(int identifier, bool is_accepting)
    : identifier_(identifier), is_accepting_(is_accepting) {}

int State::identifier() const {
  return identifier_;
}

bool State::is_accepting() const {
  return is_accepting_;
}

void State::AddTransition(char symbol, int destination_state) {
  transitions_[symbol] = destination_state;
}

bool State::HasTransition(char symbol) const {
  return transitions_.find(symbol) != transitions_.end();
}

int State::GetNextState(char symbol) const {
  auto iterator = transitions_.find(symbol);
  if (iterator != transitions_.end()) {
    return iterator->second;
  }
  return -1;
}