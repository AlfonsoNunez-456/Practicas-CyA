/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia 2026-2027
 *
 * @file html_analyzer.h
 * @author Alfonso Reyes Núñez Fernández <alu0101784809@ull.edu.es>
 * @date 30/09/2026 (modificación realizada el 07/10/2026)
 * @brief Declaración de la clase HtmlAnalyzer para realizar el análisis del documento.
 */

#ifndef HTML_ANALYZER_H_
#define HTML_ANALYZER_H_

#include <string>
#include <vector>

#include "html_document.h"

/**
 * @class HtmlAnalyzer
 * @brief Realiza el análisis del fichero HTML utilizando expresiones regulares.
 */
class HtmlAnalyzer {
 public:
  explicit HtmlAnalyzer(const std::string& input_filename);

  /**
   * @brief Analiza el fichero HTML configurado y genera un objeto HtmlDocument.
   * @return Objeto HtmlDocument cargado con la información extraída.
   */
  HtmlDocument Analyze();

 private:
  void ProcessStructure(const std::string& content, HtmlDocument& document);
  void ProcessComments(const std::string& content, HtmlDocument& document);
  void ProcessTagsAndAttributes(const std::vector<std::string>& lines, HtmlDocument& document);
  int CountLinesUpTo(const std::string& content, size_t position) const;
  void ProcessLinks(const std::vector<std::string>& lines, HtmlDocument& document);

  std::string input_filename_;
};

#endif  // HTML_ANALYZER_H_