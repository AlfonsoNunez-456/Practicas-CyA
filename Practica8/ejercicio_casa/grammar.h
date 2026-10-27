/**
 * Universidad de La Laguna
 * Ingeniería Informática
 * Computabilidad y Algoritmia
 * Curso 26/27
 * @file grammar.h
 * @brief Declaración de la clase grammar, que representa una gramática regular
 * @author Alfonso Reyes Núñez Fernández, alu0101784809@ull.edu.es
 * @date 31/10/2026
 */

#ifndef GRAMMAR_H_
#define GRAMMAR_H_

#include <iostream>
#include <set>
#include <string>
#include <vector>

#include "production.h"

/**
 * @class Grammar
 * @brief Modela una Gramática Regular y permite volcarla a un fichero .gra.
 */
class Grammar {
 public:
  Grammar();
  Grammar(const std::set<char>& terminals,
          const std::set<std::string>& non_terminals,
          const std::string& start_symbol,
          const std::vector<Production>& productions);

  bool ExportToFile(const std::string& filename) const;

 private:
  std::set<char> terminals_;
  std::set<std::string> non_terminals_;
  std::string start_symbol_;
  std::vector<Production> productions_;
};

#endif  // GRAMMAR_H_