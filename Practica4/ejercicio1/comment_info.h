/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia 2026-2027
 *
 * @file comment_info.h
 * @author Alfonso Reyes Núñez Fernández <alu0101784809@ull.edu.es>
 * @date 30/09/2026
 * @brief Declaración de la clase CommentInfo para almacenar información de comentarios.
 */

#ifndef COMMENT_INFO_H_
#define COMMENT_INFO_H_

#include <string>

/**
 * @class CommentInfo
 * @brief Almacena los datos relativos a un comentario del código HTML.
 */
class CommentInfo {
 public:
  CommentInfo(int start_line, int end_line, const std::string& text,
              bool is_description);

  int start_line() const { return start_line_; }
  int end_line() const { return end_line_; }
  const std::string& text() const { return text_; }
  bool is_description() const { return is_description_; }

 private:
  int start_line_;
  int end_line_;
  std::string text_;
  bool is_description_;
};

#endif  // COMMENT_INFO_H_