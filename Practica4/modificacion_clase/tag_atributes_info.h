/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia 2026-2027
 *
 * @file tag_attributes_info.h
 * @author Alfonso Reyes Núñez Fernández <alu0101784809@ull.edu.es>
 * @date 30/09/2026
 * @brief Declaración de la clase TagAttributesInfo para agrupar atributos por etiqueta.
 */

#ifndef TAG_ATTRIBUTES_INFO_H_
#define TAG_ATTRIBUTES_INFO_H_

#include <string>
#include <vector>

#include "atribute_info.h"

/**
 * @class TagAttributesInfo
 * @brief Agrupa los atributos asociados a una etiqueta en una línea concreta.
 */
class TagAttributesInfo {
 public:
  TagAttributesInfo(int line, const std::string& tag_name,
                    const std::vector<AttributeInfo>& attributes);

  int line() const { return line_; }
  const std::string& tag_name() const { return tag_name_; }
  const std::vector<AttributeInfo>& attributes() const { return attributes_; }

 private:
  int line_;
  std::string tag_name_;
  std::vector<AttributeInfo> attributes_;
};

#endif  // TAG_ATTRIBUTES_INFO_H_