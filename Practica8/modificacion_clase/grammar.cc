/**
 * Universidad de La Laguna
 * Ingeniería Informática
 * Computabilidad y Algoritmia
 * Curso 26/27
 * @file grammar.cc
 * @brief Implementación de la clase grammar
 * @author Alfonso Reyes Núñez Fernández, alu0101784809@ull.edu.es
 * @date 31/10/2026
 */

#include "grammar.h"

#include <fstream>
#include <map>

Grammar::Grammar() : start_symbol_("") {}

Grammar::Grammar(const std::set<char>& terminals,
                 const std::set<std::string>& non_terminals,
                 const std::string& start_symbol,
                 const std::vector<Production>& productions)
    : terminals_(terminals),
      non_terminals_(non_terminals),
      start_symbol_(start_symbol),
      productions_(productions) {}

bool Grammar::ExportToFile(const std::string& filename, bool use_alternative_format) const {
  std::ofstream output_file(filename);
  if (!output_file.is_open()) {
    std::cerr << "Error: No se pudo crear el fichero de salida " << filename << std::endl;
    return false;
  }

  output_file << terminals_.size() << "\n";
  for (char symbol : terminals_) {
    output_file << symbol << "\n";
  }

  output_file << non_terminals_.size() << "\n";
  for (const auto& symbol : non_terminals_) {
    output_file << symbol << "\n";
  }

  output_file << start_symbol_ << "\n";

  if (use_alternative_format) {
    std::vector<std::string> order;
    std::map<std::string, std::vector<std::string>> grouped_productions;

    for (const auto& production : productions_) {
      const std::string& left = production.left();
      if (grouped_productions.find(left) == grouped_productions.end()) {
        order.push_back(left);
      }
      grouped_productions[left].push_back(production.right());
    }

    output_file << grouped_productions.size() << "\n";
    for (const auto& left : order) {
      output_file << left << " -> ";
      const auto& rights = grouped_productions[left];
      for (size_t i = 0; i < rights.size(); ++i) {
        output_file << rights[i];
        if (i + 1 < rights.size()) {
          output_file << " | ";
        }
      }
      output_file << "\n";
    }
  } else {
    output_file << productions_.size() << "\n";
    for (const auto& production : productions_) {
      output_file << production.left() << " -> " << production.right() << "\n";
    }
  }

  return true;
}
