/**
 * Universidad de La Laguna
 * Ingeniería Informática
 * Computabilidad y Algoritmia
 * Curso 26/27
 * @file automata.h
 * @brief Declaración de la clase automata, que representa al propio autómata
 * @author Alfonso Reyes Núñez Fernández, alu0101784809@ull.edu.es
 * @date 31/10/2026
 */

#ifndef AUTOMATA_H_
#define AUTOMATA_H_

#include <iostream>
#include <map>
#include <set>
#include <string>

#include "grammar.h"
#include "state.h"

class Automata {
 public:
  Automata();
  explicit Automata(const std::string& filename);

  bool LoadFromFile(const std::string& filename);
  Grammar ConvertToGrammar() const;

 private:
  std::set<char> alphabet_;
  std::map<int, State> states_;
  int initial_state_identifier_;
};

#endif  // AUTOMATA_H_