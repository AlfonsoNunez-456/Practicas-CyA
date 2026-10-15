/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia 2026-2027
 *
 * @file attribute_info.h
 * @author Alfonso Reyes Núñez Fernández <alu0101784809@ull.edu.es>
 * @date 30/09/2026
 * @brief Declaración de la clase AttributeInfo para representar un atributo HTML.
 */

#ifndef ATTRIBUTE_INFO_H_
#define ATTRIBUTE_INFO_H_

#include <string>

/**
 * @class AttributeInfo
 * @brief Representa un atributo individual (par clave=valor) de una etiqueta HTML.
 */
class AttributeInfo {
 public:
  AttributeInfo(const std::string& name, const std::string& value);

  const std::string& name() const { return name_; }
  const std::string& value() const { return value_; }

 private:
  std::string name_;
  std::string value_;
};

#endif  // ATTRIBUTE_INFO_H_