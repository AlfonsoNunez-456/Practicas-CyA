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
  std::cout << "Modo de empleo: ./p08_grammar_generator file1.dfa file2.gra\n"
            << "           o: ./p08_grammar_generator file1.gra file2.dfa\n\n"
            << "Descripción:\n"
            << "  Lee la especificación de un Autómata Finito Determinista (DFA)\n"
            << "  desde un archivo .dfa y genera la Gramática Regular equivalente\n"
            << "  en un archivo .gra.\n"
            << std::endl;
}

bool HasExtension(const std::string& filename, const std::string& extension) {
  if (filename.length() >= extension.length()) {
    return filename.compare(filename.length() - extension.length(), extension.length(), extension) == 0;
  }
  return false;
}

int main(int argc, char* argv[]) {
  if (argc == 2 && std::string(argv[1]) == "--help") {
    ShowHelp();
    return 0;
  }

  if (argc != 3) {
    std::cout << "Modo de empleo: ./p08_grammar_generator input.dfa output.gra\n" << "Pruebe 'p08_grammar_generator --help' para más información." << std::endl;
    return 1;
  }

  std::string arg1 = argv[1];
  std::string arg2 = argv[2];

  std::string dfa_filename = "";
  std::string grammar_filename = "";

  if (HasExtension(arg1, ".dfa") && HasExtension(arg2, ".gra")) {
    dfa_filename = arg1;
    grammar_filename = arg2;
  } else if (HasExtension(arg1, ".gra") && HasExtension(arg2, ".dfa")) {
    dfa_filename = arg2;
    grammar_filename = arg1;
  } else {
    std::cerr << "Error: Se debe proporcionar un fichero con extensión .dfa y un fichero con extensión .gra." << std::endl;
    return 1;
  }

  Automata dfa_simulator;
  if (!dfa_simulator.LoadFromFile(dfa_filename)) {
    std::cerr << "Error al cargar la especificación del DFA." << std::endl;
    return 1;
  }

  Grammar generated_grammar = dfa_simulator.ConvertToGrammar();

  if (!generated_grammar.ExportToFile(grammar_filename)) {
    std::cerr << "Error al guardar el fichero de la gramática." << std::endl;
    return 1;
  }

  std::cout << "Gramática regular generada con éxito en: " << grammar_filename << std::endl;

  return 0;
}