/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia 2026-2027
 *
 * @file link_info.h
 * @author Alfonso Reyes Núñez Fernández <alu0101784809@ull.edu.es>
 * @date 07/10/2026
 * @brief Implementación de los métodos de la clase LinkInfo.
 */

#include "link_info.h"

#include <string>

LinkInfo::LinkInfo (int line, const std::string& protocol, const std::string& text) :
                line_(line), protocol_(protocol), text_(text) {}