/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia 2026-2027
 *
 * @file attribute_info.cc
 * @author Alfonso Reyes Núñez Fernández <alu0101784809@ull.edu.es>
 * @date 30/09/2026
 * @brief Implementación de la clase AttributeInfo.
 */

#include "atribute_info.h"

AttributeInfo::AttributeInfo(const std::string& name, const std::string& value)
    : name_(name), value_(value) {}