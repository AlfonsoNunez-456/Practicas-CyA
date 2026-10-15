/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia 2026-2027
 *
 * @file html_document.cc
 * @author Alfonso Reyes Núñez Fernández <alu0101784809@ull.edu.es>
 * @date 30/09/2026 (modificación realizada el 07/10/2026)
 * @brief Implementación de los métodos de la clase HtmlDocument.
 */

#include "html_document.h"

#include <fstream>
#include <iostream>

HtmlDocument::HtmlDocument(const std::string& input_filename)
    : input_filename_(input_filename) {}

void HtmlDocument::AddTag(const TagInfo& tag) {
  tags_.push_back(tag);
}

void HtmlDocument::AddTagAttributes(const TagAttributesInfo& attributes_info) {
  attributes_.push_back(attributes_info);
}

void HtmlDocument::AddComment(const CommentInfo& comment) {
  comments_.push_back(comment);
}

void HtmlDocument::WriteToFile(const std::string& output_filename) const {
  std::ofstream out_file(output_filename);
  if (!out_file.is_open()) {
    std::cerr << "Error: No se pudo crear el archivo de salida "
              << output_filename << std::endl;
    return;
  }

  out_file << "PROGRAM: " << input_filename_ << "\n";
  out_file << "DESCRIPTION:\n";
  if (!description_.empty()) {
    out_file << description_ << "\n";
  }
  out_file << "\n";

  out_file << "STRUCTURE:\n";
  out_file << "HTML: " << (has_html_ ? "True" : "False") << "\n";
  out_file << "HEAD: " << (has_head_ ? "True" : "False") << "\n";
  out_file << "BODY: " << (has_body_ ? "True" : "False") << "\n";
  out_file << "DOCTYPE: " << (has_doctype_ ? "HTML5" : "False") << "\n\n";

  out_file << "TAGS:\n";
  for (const auto& tag : tags_) {
    out_file << "[Line " << tag.line() << "] "
             << (tag.is_closing() ? "/" : "") << tag.name() << "\n";
  }
  out_file << "\n";

  out_file << "ATTRIBUTES:\n";
  for (const auto& attr_group : attributes_) {
    out_file << "[Line " << attr_group.line() << "] " << attr_group.tag_name() << "\n";
    for (const auto& attr : attr_group.attributes()) {
      out_file << attr.name() << " = \"" << attr.value() << "\"\n";
    }
    out_file << "\n";
  }

  out_file << "COMMENTS:\n";
  for (const auto& comment : comments_) {
    if (comment.start_line() == comment.end_line()) {
      out_file << "[Line " << comment.start_line() << "] ";
    } else {
      out_file << "[Line " << comment.start_line() << "-" << comment.end_line() << "] ";
    }

    if (comment.is_description()) {
      out_file << "DESCRIPTION\n";
    } else {
      out_file << "\n";
    }
    out_file << "<!--" << comment.text() << "-->\n\n";
  }
}

void HtmlDocument::SaveToFile (const std::string& output_filename) const{
  std::ofstream file(output_filename);
  if (!file.is_open()) {
    std::cerr << "Error, no se pudo abrir el fichero de salida " << output_filename << '\n';
    return;
  }
  file << "LINKS:\n";
  for (const auto& link : links_) {
    file << "[Line " << link.line() << "]\n";
    file << "PROTOCOL: " << (link.protocol().empty() ? "NONE" : link.protocol()) << "\n";
    file << "TEXT: " << link.text() << "\n";
  }
  file.close();
}
