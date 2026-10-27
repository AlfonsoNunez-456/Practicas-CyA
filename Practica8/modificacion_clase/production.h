/**
 * Universidad de La Laguna
 * Ingeniería Informática
 * Computabilidad y Algoritmia
 * Curso 26/27
 * @file production.h
 * @brief Declaración de la clase production, que representa una regla de producción
 * @author Alfonso Reyes Núñez Fernández, alu0101784809@ull.edu.es
 * @date 31/10/2026
 */

#ifndef PRODUCTION_H_
#define PRODUCTION_H_

#include <string>

/**
 * @class Production
 * @brief Modela una regla de producción de la forma A -> conjunto de terminales y no terminales
 */
class Production {
 public:
  Production();
  Production(const std::string& left, const std::string& right);

  std::string left() const;
  std::string right() const;

 private:
  std::string left_;
  std::string right_;
};

#endif  // PRODUCTION_H_