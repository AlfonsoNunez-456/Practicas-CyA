// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Contenedores asociativos
// Autor: Alfonso Reyes Núñez Fernández
// Correo: alu0101784809@ull.edu.es
// Fecha: 10/09/2026
// Archivo tools.h
// Contiene el fichero de cabecera, en el que se definen
// los métodos de la clase tools, herramientas para hacer que
// el main sea más legible y tenga menos líneas de código
// Historial de revisiones
// 10/09/2026 - Creación (primera versión) del código

#include "alumno.h"

#include <iostream>
#include <fstream>
#include <map>
#include <string>

#ifndef TOOLS_H
#define TOOLS_H

/// Clase tools
class Tools {
 public:
  /**
   * @brief Función que comprueba los argumentos
   * @param int argc, número de argumentos
   * @param char* argv[], argumento
   * @return Distintos mensajes por pantalla dependiendo del número de argumentos
   */
  static bool ProcesarArgumentos (int argc, char* argv[]);

  /**
   * @brief Función que inserta los alumnos en un contenedor asociativo ordenado
   * @param std::map<std::string, Alumno>& alumnos, contenedor donde se van a depositar los alumnos
   * @param const std::string& identidad, identidad del alumno 
   * @param double nota, nota del alumno
   */
  static void InsertarAlumnos (std::map <std::string, Alumno>& alumnos, const std::string& identidad, double nota);

  /**
   * @brief Función que comprueba si se ha cargado el fichero
   * @param const std::string& nombre_fichero
   * @param std::map <std::string, Alumno>& alumnos
   */
  static bool ComprobarFichero (const std::string& nombre_fichero, std::map <std::string, Alumno>& alumnos);

  /**
   * @brief Función que muestra por pantalla los alumnos y las calificaciones
   * @param const std::map <std::string, Alumno> alumnos
   */
  static void MostrarPorPantalla (const std::map <std::string, Alumno>& alumnos);

  /**
   * @brief Función que permite insertar alumnos manualmente
   * @param std::mapa <std::string, Alumno>& alumnos
   */
  static void MenuInsercionManual(std::map<std::string, Alumno>& alumnos);
};

#endif //TOOLS_H