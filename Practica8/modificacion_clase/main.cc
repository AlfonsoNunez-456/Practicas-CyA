/**
 * Universidad de La Laguna
 * Ingeniería Informática
 * Computabilidad y Algoritmia
 * Curso 26/27
 * @file main.cc
 * @brief Declaración de la clase automata, que representa al propio autómata
 * @author Alfonso Reyes Núñez Fernández, alu0101784809@ull.edu.es
 * @date 31/10/2026
 */

#include <iostream>
#include <string>

#include "automata.h"
#include "grammar.h"

void ShowHelp() {
  std::cout << "Modo de empleo: ./dfa2grammar input.dfa output.gra [alt]\n\n"
            << "Descripción:\n"
            << "  Lee la especificación de un Autómata Finito Determinista (DFA)\n"
            << "  desde un archivo .dfa y genera la Gramática Regular equivalente\n"
            << "  en un archivo .gra.\n\n"
            << "Opciones:\n"
            << "  alt : Genera la representación alternativa agrupando producciones\n"
            << "        por símbolo no terminal (ej. A -> aB | bC | &).\n"
            << std::endl;
}

bool HasExtension(const std::string& filename, const std::string& extension) {
  if (filename.length() >= extension.length()) {
    return filename.compare(filename.length() - extension.length(),
                            extension.length(), extension) == 0;
  }
  return false;
}

int main(int argc, char* argv[]) {
  if (argc == 2 && std::string(argv[1]) == "--help") {
    ShowHelp();
    return 0;
  }

  if (argc < 3 || argc > 4) {
    std::cout << "Modo de empleo: ./dfa2grammar input.dfa output.gra [alt]\n"
              << "Pruebe 'dfa2grammar --help' para más información."
              << std::endl;
    return 1;
  }

  std::string dfa_filename = "";
  std::string grammar_filename = "";
  bool use_alt_format = false;

  for (int i = 1; i < argc; ++i) {
    std::string arg = argv[i];
    if (arg == "alt") {
      use_alt_format = true;
    } else if (HasExtension(arg, ".dfa")) {
      dfa_filename = arg;
    } else if (HasExtension(arg, ".gra")) {
      grammar_filename = arg;
    }
  }

  if (dfa_filename.empty() || grammar_filename.empty()) {
    std::cerr << "Error: Se debe proporcionar un fichero con extensión .dfa "
                 "y un fichero con extensión .gra." << std::endl;
    return 1;
  }

  Automata dfa_simulator;
  if (!dfa_simulator.LoadFromFile(dfa_filename)) {
    std::cerr << "Error al cargar la especificación del DFA." << std::endl;
    return 1;
  }

  Grammar generated_grammar = dfa_simulator.ConvertToGrammar();

  if (!generated_grammar.ExportToFile(grammar_filename, use_alt_format)) {
    std::cerr << "Error al guardar el fichero de la gramática." << std::endl;
    return 1;
  }

  std::cout << "Gramática regular generada con éxito ("
            << (use_alt_format ? "formato alternativo" : "formato estándar")
            << ") en: " << grammar_filename << std::endl;

  return 0;
}