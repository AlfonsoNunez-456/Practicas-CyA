// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Contenedores asociativos
// Autor: Alfonso Reyes Núñez Fernández
// Correo: alu0101784809@ull.edu.es
// Fecha: 11/09/2026
// Archivo alumno.h
// Contiene el fichero de cabecera, en el que se definen
// los métodos de la clase alumno
// Historial de revisiones
// 11/09/2026 - Creación (primera versión) del código

#include <iostream>
#include <string>
#include <vector>

#ifndef ALUMNO_H
#define ALUMNO_H

/// Clase alumno
class Alumno {
 public:
  /**
   * @brief Constructor por defecto de la clase alumno
   */
  Alumno () = default;

  /**
   * @brief Constructor de la clase Alumno
   * @param std::string& identidad, id del alumno
   * @param std::vector<double>& nota, notas del alumno 
   */
  Alumno (const std::string& identidad, const std::vector<double>& notas);

  /// Getters
  std::string GetIdentidad () const;
  const std::vector<double>& GetNotas () const;

  /**
   * @brief Función que agrega una sola nota
   * @param double nota
   */
  void AgregarNota (double nota);

  /**
   * @brief Sobrecarga del operador < para la ordenación de los alumnos
   * según su identidad
   * @param const Alumno& estudiante
   */
  bool operator < (const Alumno& estudiante) const;

 private:
  std::string identidad_;
  std::vector<double> notas_;
};

/// Sobrecarga del operador de flujo de salida
std::ostream& operator << (std::ostream& salida, const Alumno& alumno);

#endif //ALUMNO_H