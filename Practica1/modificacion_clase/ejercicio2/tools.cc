// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Contenedores asociativos
// Autor: Alfonso Reyes Núñez Fernández
// Correo: alu0101784809@ull.edu.es
// Fecha: 11/09/2026
// Archivo tools.cc
// Contiene el fichero de implementación, en el que se implementan
// los métodos de la clase tools, herramientas para hacer que
// el main sea más legible y tenga menos líneas de código
// Historial de revisiones
// 11/09/2026 - Creación (primera versión) del código
// 15/09/2026 - Modificación práctica 1 cya

#include "alumno.h"
#include "tools.h"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <string>
#include <vector>

bool Tools::ProcesarArgumentos (int argc, char* argv[]) {
  bool procesar = false;
  if (argc < 2) {
    std::cout << "Modo de empleo: " << argv[0] << " alumno" << "\n";
    std::cout << "Pruebe " << argv[0] << " --help para más información.\n";
    return procesar;
  }
  std::string argumento = argv[1];
  if (argumento == "--help") {
    std::cout << "Descripción:\n" << "  Este programa lee un fichero plano con un listado de calificaciones de\n"
              << "  estudiantes. Si un estudiante se ha presentado a varias recuperaciones,\n"
              << "  se añadirán sus notas y se mostrarán por pantalla.\n\n"
              << "Formato del fichero de entrada:\n"
              << "  Cada línea debe estar compuesta por la identidad del alumno (aluXXXX), \n"
              << "  separadas por : y sus notas separadas en punto flotante.\n\n"
              << "Ejemplo de contenido del fichero:\n"
              << "  alu0122334455 5.25\n"
              << "  alu0101010101 4.75\n"
              << "  alu0101010101 9.25\n"
              << "Asimismo, se puede mirar la máxima nota del alumno si se pone su identidad por pantalla.\n\n"
              << "Ejemplo para buscar la máxima nota: \n"
              << "  alu0101010101 9.25, 4.5, 6.8\n"
              << "Se mostraría por pantalla 9.25\n";

  }
  else {
    procesar = true;
  }
  return procesar;
}

void Tools::InsertarAlumnos (std::map <std::string, Alumno>& alumnos, const std::string& identidad, double nota) {
  auto alumno = alumnos.find (identidad);
  if (alumno != alumnos.end()) {
    alumno -> second.AgregarNota (nota);
  } else {
    alumnos [identidad] = Alumno (identidad, {nota});
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

void Tools::MostrarNotaMaxima (const Alumno& alumno) {
  std::string identidad;
  if (identidad == alumno.GetIdentidad()) {
    std::cout << "La nota máxima del alumno " << alumno.GetIdentidad() << " es " << alumno.EcnontrarMaximaNota () << "\n";
  }
  else {
    std::cout << "No se encontró al alumno " << alumno.GetIdentidad() << "\n";
  } 
}

