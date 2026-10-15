/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia 2026-2027
 *
 * @file html_document.h
 * @author Alfonso Reyes Núñez Fernández <alu0101784809@ull.edu.es>
 * @date 30/09/2026
 * @brief Declaración de la clase HtmlDocument para representar el documento completo.
 */

#ifndef HTML_DOCUMENT_H_
#define HTML_DOCUMENT_H_

#include <string>
#include <vector>

#include "comment_info.h"
#include "tag_atributes_info.h"
#include "tag_info.h"

/**
 * @class HtmlDocument
 * @brief Modelo de datos estructurado extraído tras procesar un fichero HTML.
 */
class HtmlDocument {
 public:
  explicit HtmlDocument(const std::string& input_filename);

  void set_has_html(bool has_html) { has_html_ = has_html; }
  void set_has_head(bool has_head) { has_head_ = has_head; }
  void set_has_body(bool has_body) { has_body_ = has_body; }
  void set_has_doctype(bool has_doctype) { has_doctype_ = has_doctype; }
  void set_description(const std::string& description) { description_ = description; }

  void AddTag(const TagInfo& tag);
  void AddTagAttributes(const TagAttributesInfo& attributes_info);
  void AddComment(const CommentInfo& comment);

  /**
   * @brief Exporta el resumen estructurado a un fichero de salida.
   * @param output_filename Nombre del archivo de destino.
   */
  void WriteToFile(const std::string& output_filename) const;

 private:
  std::string input_filename_;
  std::string description_;
  bool has_html_{false};
  bool has_head_{false};
  bool has_body_{false};
  bool has_doctype_{false};

  std::vector<TagInfo> tags_;
  std::vector<TagAttributesInfo> attributes_;
  std::vector<CommentInfo> comments_;
};

#endif  // HTML_DOCUMENT_H_