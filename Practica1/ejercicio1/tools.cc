// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Contenedores asociativos
// Autor: Alfonso Reyes Núñez Fernández
// Correo: alu0101784809@ull.edu.es
// Fecha: 10/09/2026
// Archivo tools.cc
// Contiene el fichero de implementación, en el que se implementan
// los métodos de la clase tools, herramientas para hacer que
// el main sea más legible y tenga menos líneas de código
// Historial de revisiones
// 10/09/2026 - Creación (primera versión) del código

#include "alumno.h"
#include "tools.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <map>

bool Tools::ProcesarArgumentos (int argc, char* argv[]) {
  bool procesar = false;
  if (argc != 2) {
    std::cout << "Modo de empleo: " << argv[0] << "\n";
    std::cout << "Pruebe " << argv[0] << " --help para más información.\n";
    return procesar;
  }
  std::string argumento = argv[1];
  if (argumento == "--help") {
    std::cout << "Descripción:\n" << "  Este programa lee un fichero plano con un listado de calificaciones de\n"
              << "  estudiantes. Si un estudiante se ha presentado a varias recuperaciones,\n"
              << "  solo se conservará su calificación MÁXIMA.\n\n"
              << "Formato del fichero de entrada:\n"
              << "  Cada línea debe estar compuesta por la identidad del alumno (aluXXXX)\n"
              << "  y su nota en punto flotante, separadas por un espacio.\n\n"
              << "Ejemplo de contenido del fichero:\n"
              << "  alu0122334455 5.25\n"
              << "  alu0101010101 4.75\n"
              << "  alu0101010101 9.25\n";
  }
  else {
    procesar = true;
  }
  return procesar;
}

void Tools::InsertarAlumnos (std::map <std::string, Alumno>& alumnos, const std::string& identidad, double nota) {
  auto alumno = alumnos.find (identidad);
  if (alumno == alumnos.end()) {
    alumnos.emplace(identidad, Alumno (identidad, nota));
  } else {
    alumno -> second.MaximaNota(nota);
  }
}

bool Tools::ComprobarFichero (const std::string& nombre_fichero, std::map <std::string, Alumno>& alumnos) {
  bool comprobar = false;
  std::ifstream fichero (nombre_fichero);
  if (!fichero.is_open()) {
    std::cerr << "No se pudo abrir el nombre del fichero de entrada '" << nombre_fichero << "'.\n";
  } else {
    std::string identidad;
    double nota;
    while (fichero >> identidad >> nota) {
      InsertarAlumnos (alumnos, identidad, nota);
    }
    fichero.close();
    comprobar = true;
  }
  return comprobar;
}

void Tools::MostrarPorPantalla (const std::map <std::string, Alumno>& alumnos) {
  for (const auto& [identidad_alumno, alumno] : alumnos) {
    std::cout << alumno;
  }
}

void Tools::MenuInsercionManual(std::map<std::string, Alumno>& alumnos) {
  char opcion;
  std::cout << "¿Desea insertar un alumno de forma individual? (s/n): ";
  while (std::cin >> opcion && (opcion == 's' || opcion == 'S')) {
    std::string identidad;
    double nota;
    std::cout << "Ingrese la identidad y la nota (ej. alu0199999999 8.5): ";
    if (std::cin >> identidad >> nota) {
      InsertarAlumnos(alumnos, identidad, nota);
      MostrarPorPantalla(alumnos);
    }
    std::cout << "¿Desea insertar otro alumno? (s/n): ";
  }
}