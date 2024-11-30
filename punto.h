
/*
 * Archivo: punto.h
 * Autor: Axel Camacho Villafuerte
 * Descripción: Clase que representa un punto en un plano cartesiano y ofrece operaciones básicas para manipular sus coordenadas.
 * Fecha: 2024
 * Versión: 1.1
 * 
 * Este archivo define la clase Punto, que incluye:
 * - Atributos para las coordenadas x e y.
 * - Métodos para obtener y modificar las coordenadas.
 * - Método para calcular la distancia euclidiana entre dos puntos.
 * 
 * Complejidad:
 * - Todas las operaciones de esta clase tienen una complejidad O(1).
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
    int GetX() const;

    /**
     * @brief Método para obtener la coordenada y del punto.
     * 
     * @return Coordenada y del punto.
     */
    int GetY() const;


    /**
     * @brief Método para calcular la distancia entre dos puntos.
     * 
     * @param p Punto con el que se calculará la distancia.
     * @return Distancia entre los dos puntos.
     */
    double Distancia(const Punto& p) const;
};

Punto::Punto(int x, int y) : x(x), y(y) {}

int Punto::GetX() const {
    return x;
}

int Punto::GetY() const {
    return y;
}

double Punto::Distancia(const Punto& p) const {
    return sqrt(pow(x - p.GetX(), 2) + pow(y - p.GetY(), 2));
}

#endif
