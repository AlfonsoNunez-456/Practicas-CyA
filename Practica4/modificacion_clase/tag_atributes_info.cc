/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia 2026-2027
 *
 * @file tag_attributes_info.cc
 * @author Alfonso Reyes Núñez Fernández <alu0101784809@ull.edu.es>
 * @date 30/09/2026
 * @brief Implementación de la clase TagAttributesInfo.
 */

#include "tag_atributes_info.h"

TagAttributesInfo::TagAttributesInfo(int line, const std::string& tag_name,
                                     const std::vector<AttributeInfo>& attributes)
    : line_(line), tag_name_(tag_name), attributes_(attributes) {}