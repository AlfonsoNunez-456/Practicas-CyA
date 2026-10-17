/**
 * Universidad de La Laguna, Grado en Ingeniería Informática
 * Computabilidad y Algoritima
 * Curso 26/27
 * @author Alfonso Reyes Núñez Fernández, alu0101784809@ull.edu.es
 * @date 13/10/2026
 * @file main.cc
 * @brief Fichero cliente de la clase DFA
 */

#include <fstream>
#include <iostream>
#include <string>

#include "dfa.h"

void ShowHelp() {
  std::cout << "Modo de empleo: ./p06_DFA_simulator input.dfa input.txt\n\n"
            << "Descripción:\n"
            << "  Simula el comportamiento de un Autómata Finito Determinista (DFA)\n"
            << "  sobre una serie de cadenas suministradas por un fichero de entrada.\n\n"
            << "Estructura del fichero .dfa:\n"
            << "  - Línea 1: Símbolos del alfabeto (alfanumericos continuos).\n"
            << "  - Línea 2: Número total de estados.\n"
            << "  - Línea 3: Estado de arranque.\n"
            << "  - Siguientes líneas: [ID_Estado] [Aceptación(0|1)] [Simbolo Destino ...]\n"
            << "  - Comentarios permitidos mediante '//'.\n"
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
    std::cout << "Modo de empleo: ./p06_DFA_simulator input.dfa input.txt\n"
              << "Pruebe 'p06_DFA_simulator --help' para más información."
              << std::endl;
    return 1;
  }

  std::string arg1 = argv[1];
  std::string arg2 = argv[2];

  std::string dfa_filename = "";
  std::string input_filename = "";

  if (HasExtension(arg1, ".dfa") && HasExtension(arg2, ".txt")) {
    dfa_filename = arg1;
    input_filename = arg2;
  } else if (HasExtension(arg1, ".txt") && HasExtension(arg2, ".dfa")) {
    dfa_filename = arg2;
    input_filename = arg1;
  } else {
    std::cerr << "Error: Se debe proporcionar un fichero con extensión .dfa y un fichero con extensión .txt." << std::endl;
    return 1;
  }

  DFA dfa_simulator;
  if (!dfa_simulator.LoadFromFile(dfa_filename)) {
    std::cerr << "Error al cargar la especificación del DFA." << std::endl;
    return 1;
  }

  std::ifstream input_file(input_filename);
  if (!input_file.is_open()) {
    std::cerr << "Error: No se pudo abrir el fichero de cadenas: " << input_filename << std::endl;
    return 1;
  }

  std::string test_string;
  while (input_file >> test_string) {
    dfa_simulator.SimulateString(test_string, std::cout);
  }

  return 0;
}