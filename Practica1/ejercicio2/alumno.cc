// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Contenedores asociativos
// Autor: Alfonso Reyes Núñez Fernández
// Correo: alu0101784809@ull.edu.es
// Fecha: 11/09/2026
// Archivo alumno.cc
// Contiene el fichero de implementación, en el que se implementan
// los métodos de la clase alumnos (en este caso, los alumnos tienen varias notas)
// Historial de revisiones
// 11/09/2026 - Creación (primera versión) del código

#include "alumno.h"

#include <iostream>
#include <vector>
#include <string>

Alumno::Alumno (const std::string& identidad, const std::vector<double>& notas) :
    identidad_ {identidad}, notas_{notas} {}

std::string Alumno::GetIdentidad () const {
  return identidad_;
}

const std::vector <double>& Alumno::GetNotas () const {
  return notas_;
}

void Alumno::AgregarNota (double nota) {
  notas_.emplace_back (nota);
}

bool Alumno::operator < (const Alumno& estudiante) const {
  return identidad_ < estudiante.identidad_;
}

std::ostream& operator << (std::ostream& salida, const Alumno& alumno) {
  salida << alumno.GetIdentidad() << ":";
  for (const auto& nota : alumno.GetNotas()) {
    salida << " " << nota;
  }
  salida << std::endl;
  return salida;
}