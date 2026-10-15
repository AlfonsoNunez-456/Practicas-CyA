/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia 2026-2027
 *
 * @file comment_info.cc
 * @author Alfonso Reyes Núñez Fernández <alu0101784809@ull.edu.es>
 * @date 30/09/2026
 * @brief Implementación de la clase CommentInfo.
 */

#include "comment_info.h"

CommentInfo::CommentInfo(int start_line, int end_line, const std::string& text,
                         bool is_description)
    : start_line_(start_line),
      end_line_(end_line),
      text_(text),
      is_description_(is_description) {}