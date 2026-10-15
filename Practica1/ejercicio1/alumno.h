// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Contenedores asociativos
// Autor: Alfonso Reyes Núñez Fernández
// Correo: alu0101784809@ull.edu.es
// Fecha: 10/09/2026
// Archivo alumno.h
// Contiene el fichero de cabecera, en el que se definen
// los métodos de la clase alumno
// Historial de revisiones
// 10/09/2026 - Creación (primera versión) del código

#include <iostream>
#include <string>

#ifndef ALUMNO_H
#define ALUMNO_H

/// Clase alumno
class Alumno {
 public:
  /**
   * @brief Constructor de la clase Alumno
   * @param std::string identidad, id del alumno
   * @param double nota, nota del alumno
   */
  Alumno (const std::string identidad, double nota);

  /// Getters
  std::string GetIdentidad () const;
  double GetNota () const;

  /**
   * @brief Función que se queda con la nota máxima
   * @param double nota, nota, mayor o menor que la inicial
   */
  void MaximaNota (double nota);

  /**
   * @brief Sobrecarga del operador < para la ordenación de los alumnos
   * según su identidad
   * @param const Alumno& estudiante
   */
  bool operator < (const Alumno& estudiante) const;

 private:
  std::string identidad_;
  double nota_;
};

/// Sobrecarga del operador de flujo de salida
std::ostream& operator << (std::ostream& salida, const Alumno& alumno);

#endif //ALUMNO_H