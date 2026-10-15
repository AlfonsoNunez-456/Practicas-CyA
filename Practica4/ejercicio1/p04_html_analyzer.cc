/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia 2026-2027
 *
 * @file p04_html_analyzer.cc
 * @author Alfonso Reyes Núñez Fernández <alu0101784809@ull.edu.es>
 * @date 30/09/2026
 * @brief Punto de entrada principal para el analizador de expresiones regulares de HTML.
 */

#include <cstdlib>
#include <iostream>

#include "html_analyzer.h"
#include "html_document.h"


void Usage(int argc, char* argv[]) {
  if (argc != 3) {
    std::cerr << "Modo de uso: " << argv[0] << " <fichero_entrada.html> <fichero_salida.txt>\n"
              << "  fichero_entrada.html : Nombre del fichero de entrada HTML a analizar.\n"
              << "  fichero_salida.txt   : Nombre del fichero de salida para guardar el esquema.\n";
    std::exit(EXIT_FAILURE);
  }
}

int main(int argc, char* argv[]) {
  Usage(argc, argv);

  const std::string kInputFilename = argv[1];
  const std::string kOutputFilename = argv[2];

  HtmlAnalyzer analyzer(kInputFilename);
  HtmlDocument document = analyzer.Analyze();
  document.WriteToFile(kOutputFilename);

  return 0;
}