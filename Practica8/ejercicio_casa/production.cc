/**
 * Universidad de La Laguna
 * Ingeniería Informática
 * Computabilidad y Algoritmia
 * Curso 26/27
 * @file production.cc
 * @brief Implementación de la clase Production
 * @author Alfonso Reyes Núñez Fernández, alu0101784809@ull.edu.es
 * @date 31/10/2026
 */

#include "production.h"

Production::Production() : left_(""), right_("") {}

Production::Production(const std::string& left, const std::string& right)
    : left_(left), right_(right) {}

std::string Production::left() const {
  return left_;
}

std::string Production::right() const {
  return right_;
}