/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia 2026-2027
 *
 * @file tag_info.cc
 * @author Alfonso Reyes Núñez Fernández <alu0101784809@ull.edu.es>
 * @date 30/09/2026
 * @brief Implementación de la clase TagInfo.
 */

#include "tag_info.h"

TagInfo::TagInfo(int line, const std::string& name, bool is_closing)
    : line_(line), name_(name), is_closing_(is_closing) {}