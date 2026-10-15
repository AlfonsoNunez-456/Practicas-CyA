/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia 2026-2027
 *
 * @file tag_info.h
 * @author Alfonso Reyes Núñez Fernández <alu0101784809@ull.edu.es>
 * @date 30/09/2026
 * @brief Declaración de la clase TagInfo para almacenar los datos de una etiqueta.
 */

#ifndef TAG_INFO_H_
#define TAG_INFO_H_

#include <string>

/**
 * @class TagInfo
 * @brief Almacena la información de una etiqueta HTML detectada.
 */
class TagInfo {
 public:
  TagInfo(int line, const std::string& name, bool is_closing);

  int line() const { return line_; }
  const std::string& name() const { return name_; }
  bool is_closing() const { return is_closing_; }

 private:
  int line_;
  std::string name_;
  bool is_closing_;
};

#endif  // TAG_INFO_H_