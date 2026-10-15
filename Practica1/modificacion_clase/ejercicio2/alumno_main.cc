// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Contenedores asociativos
// Autor: Alfonso Reyes Núñez Fernández
// Correo: alu0101784809@ull.edu.es
// Fecha: 11/09/2026
// Archivo alumno_main.cc
// Contiene el programa principal
// Historial de revisiones
// 11/09/2026 - Creación (primera versión) del código

#include <iostream>
#include <string>
#include <map>

#include "alumno.h"
#include "tools.h"

int main (int argc, char* argv[]) {
  if (!Tools::ProcesarArgumentos(argc, argv)) {
    return 1;
  }
  std::map <std::string, Alumno> resultados;
  if (!Tools::ComprobarFichero (argv[1], resultados)) {
    return 2;
  }
  Tools::MostrarPorPantalla (resultados);
  Tools::MenuInsercionManual (resultados);
  return 0;
}