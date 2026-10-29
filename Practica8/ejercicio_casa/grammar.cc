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

Grammar::Grammar() : start_symbol_("") {}

Grammar::Grammar(const std::set<char>& terminals,
                 const std::set<std::string>& non_terminals,
                 const std::string& start_symbol,
                 const std::vector<Production>& productions)
    : terminals_(terminals),
      non_terminals_(non_terminals),
      start_symbol_(start_symbol),
      productions_(productions) {}

bool Grammar::ExportToFile(const std::string& filename) const {
  std::ofstream output_file(filename);
  if (!output_file.is_open()) {
    std::cerr << "Error: No se pudo crear el fichero de salida " << filename << std::endl;
    return false;
  }

  output_file << "Número de terminales: " << terminals_.size() << "\n";
  output_file << "Terminales:\n";
  for (char symbol : terminals_) {
    output_file << symbol << "\n";
  }

  output_file << "Número de no terminales: " << non_terminals_.size() << "\n";
  output_file << "No terminales:\n";
  for (const auto& symbol : non_terminals_) {
    output_file << symbol << "\n";
  }

  output_file << "Símbolo incial: " << start_symbol_ << "\n";

  output_file << "Número de normas de producción: " << productions_.size() << "\n";
  output_file << "Normas de producción:\n";
  for (const auto& production : productions_) {
    output_file << production.left() << " -> " << production.right() << "\n";
  }

  return true;
}