/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia 2026-2027
 *
 * @file link_info.h
 * @author Alfonso Reyes Núñez Fernández <alu0101784809@ull.edu.es>
 * @date 07/10/2026
 * @brief Declaración de la clase LinkInfo para representar la información del enlace.
 */

#ifndef LINK_INFO_H_
#define LINK_INFO_H_

#include <string>


/**
 * @brief Class LinkInfo
 */
class LinkInfo {
 public:
  LinkInfo(int line, const std::string& protocol, const std::string& text);

  int line() const { return line_; }
  std::string protocol() const { return protocol_; }
  std::string text() const { return text_; }

 private:
  int line_;
  std::string protocol_;
  std::string text_;
};

#endif  // LINK_INFO_H_
