/*
 * Archivo: punto.h
 * Autor: Axel Camacho Villafuerte
 * Descripción: Funciones para definir un punto en un plano cartesiano.
 * Fecha: 2024
 * Versión: 1.0
 * 
 * Este archivo define la clase Punto que representa un punto en un plano cartesiano.
 * 
 * La clase tiene dos atributos: x y y, que representan las coordenadas del punto.
 * 
 * La clase Punto tiene un constructor que inicializa los atributos del punto.
 * 
 * La clase Punto tiene métodos para obtener y modificar las coordenadas del punto, y para calcular la distancia entre dos puntos.
 * 
 * La complejidad de la clase es O(1).
 */

#ifndef PUNTO_H
#define PUNTO_H

#include <cmath>

/**
 * @brief Clase que representa un punto en un plano cartesiano.
 */
class Punto {
private:
    /**
     * @brief Coordenada x del punto.
     */
    int x;
    /**
     * @brief Coordenada y del punto.
     */
    int y;

public:
    /**
     * @brief Constructor de la clase Punto.
     * 
     * @param x Coordenada x del punto.
     * @param y Coordenada y del punto.
     */
    Punto(int x = 0, int y = 0); // Constructor con valores predeterminados

    /**
     * @brief Método para obtener la coordenada x del punto.
     * 
     * @return Coordenada x del punto.
     */
    int get_x() const;

    /**
     * @brief Método para obtener la coordenada y del punto.
     * 
     * @return Coordenada y del punto.
     */
    int get_y() const;

    /**
     * @brief Método para modificar la coordenada x del punto.
     * 
     * @param x Nueva coordenada x del punto.
     */
    void set_x(int x);

    /**
     * @brief Método para modificar la coordenada y del punto.
     * 
     * @param y Nueva coordenada y del punto.
     */
    void set_y(int y);

    /**
     * @brief Método para calcular la distancia entre dos puntos.
     * 
     * @param p Punto con el que se calculará la distancia.
     * @return Distancia entre los dos puntos.
     */
    double distancia(const Punto& p) const;
};

Punto::Punto(int x, int y) : x(x), y(y) {}

int Punto::get_x() const {
    return x;
}

int Punto::get_y() const {
    return y;
}

void Punto::set_x(int x) {
    this->x = x;
}

void Punto::set_y(int y) {
    this->y = y;
}

double Punto::distancia(const Punto& p) const {
    return sqrt(pow(x - p.get_x(), 2) + pow(y - p.get_y(), 2));
}

#endif