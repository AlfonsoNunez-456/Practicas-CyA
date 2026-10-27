/**
 * Universidad de La Laguna
 * Ingeniería Informática
 * Computabilidad y Algoritmia
 * Curso 26/27
 * @file state.cc
 * @brief Implementación de la clase state
 * @author Alfonso Reyes Núñez Fernández, alu0101784809@ull.edu.es
 * @date 31/10/2026
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
  transitions_.push_back({symbol, destination_state});
}

const std::vector<std::pair<char, int>>& State::transitions() const {
  return transitions_;
}