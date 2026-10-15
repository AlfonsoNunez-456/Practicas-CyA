// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Contenedores asociativos
// Autor: Alfonso Reyes Núñez Fernández
// Correo: alu0101784809@ull.edu.es
// Fecha: 10/09/2026
// Archivo alumno.cc
// Contiene el fichero de implementación, en el que se implementan
// los métodos de la clase alumno
// Historial de revisiones
// 10/09/2026 - Creación (primera versión) del código

#include "alumno.h"

#include <iostream>
#include <algorithm>
#include <string>

Alumno::Alumno (const std::string identidad, double nota) :
    identidad_{identidad}, nota_{nota} {}

std::string Alumno::GetIdentidad () const {
  return identidad_;
}

double Alumno::GetNota () const {
  return nota_;
}

void Alumno::MaximaNota (double nota) {
  nota_ = std::max (nota, nota_);
}

bool Alumno::operator < (const Alumno& estudiante) const {
  return identidad_ < estudiante.identidad_;
}

std::ostream& operator << (std::ostream& salida, const Alumno& alumno) {
  salida << alumno.GetIdentidad() << ' ' << alumno.GetNota() << std::endl;
  return salida;
}