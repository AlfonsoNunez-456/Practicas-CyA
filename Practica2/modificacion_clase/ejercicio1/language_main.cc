/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 2: Cadenas y lenguajes
 * Nombre: Alfonso Reyes Núñez Fernández
 * Correo: alu0101784809@ull.edu.es
 * Fecha: 19/09/2026
 *
 * @file language_main.cc
 * @brief Programa principal
 */

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "alphabet.h"
#include "language.h"
#include "string_spec.h"
#include "symbol.h"

void ShowHelp() {
  std::cout << "Modo de empleo: ./p02_strings filein.txt fileout.txt opcode\n"
            << "Códigos de operación (opcode):\n"
            << "  1: Alfabeto asociado a cada cadena.\n"
            << "  2: Longitud de cada cadena.\n"
            << "  3: Inversa de cada cadena.\n"
            << "  4: Conjunto de prefijos.\n"
            << "  5: Conjunto de sufijos.\n"
            << "  6: Validación de la cadena sobre el alfabeto.\n"
            << "  7: Concatenación de una cadena puesta por comandos. \n";
}

int main(int argc, char* argv[]) {
  if (argc == 2 && std::string(argv[1]) == "--help") {
    ShowHelp();
    return 0;
  }
  if (argc < 4) {
    std::cout << "Modo de empleo: " << argv[0] << " filein.txt fileout.txt opcode\n"
              << "Pruebe '" << argv[0] << " --help' para más información.\n";
    return 1;
  }
  const std::string kInputFilename = argv[1];
  const std::string kOutputFilename = argv[2];
  const int kOpcode = std::stoi(argv[3]);
  std::ifstream input_file(kInputFilename);
  std::ofstream output_file(kOutputFilename);
  if (!input_file.is_open() || !output_file.is_open()) {
    std::cerr << "Error: No se pudo abrir uno de los ficheros.\n";
    return 1;
  }
  std::string line;
  while (std::getline(input_file, line)) {
    if (line.empty()) continue;
    std::istringstream iss(line);
    std::string str_seq;
    std::string alpha_seq;
    iss >> str_seq >> alpha_seq;
    Alphabet alphabet;
    for (char c : alpha_seq) {
      alphabet.Insert(Symbol(c));
    }
    StringSpec str(str_seq, alphabet);
    switch (kOpcode) {
      case 1:
        output_file << str << ": " << str.alphabet() << "\n";
        break;
      case 2:
        output_file << str.Length() << "\n";
        break;
      case 3:
        output_file << str << " -> " << str.Reverse() << "\n";
        break;
      case 4:
        output_file << str.Prefixes() << "\n";
        break;
      case 5:
        output_file << str.Suffixes() << "\n";
        break;
      case 6:
        output_file << (str.IsValid() ? "OK" : "ERROR") << "\n";
        break;
      case 7:
        if (argc != 5) {
          std::cerr << "Se debe introducir una cadena por parámetros para concatenar.\n";
          return 3;
        }
        else {
          const std::string concatena = argv[4];
          output_file << str.Concatenar (concatena) << "\n";
        }
        break;
      default:
        std::cerr << "Error: Código de operación no válido.\n";
        return 2;
    }
  }
  return 0;
}