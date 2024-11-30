/*
 * Archivo: central.h
 * Autor: Axel Camacho Villafuerte
 * Descripción: Funciones para encontrar la central más cercana a una colonia.
 * Fecha: 2024
 * Versión: 1.0
 *
 * Este archivo define la función encontrar_central_cercana, que recibe las 
 * coordenadas de una colonia y un vector con las coordenadas de las centrales, 
 * y devuelve el índice de la central más cercana a la colonia.
 * 
 * La función recorre el vector de centrales y calcula la distancia de la colonia
 * a cada central, guardando el índice de la central con la menor distancia.
 * 
 * La complejidad de la función es O(n), donde n es el número de centrales.
 * 
 */

#ifndef CENTRAL_H
#define CENTRAL_H

#include <vector>
#include "punto.h"

// Función que calcula la central más cercana a una colonia
// Complejidad: O(n)
/**
 * @brief Encuentra el índice de la central más cercana a una colonia.
 * 
 * @param colonia Coordenadas de la colonia.
 * @param centrales Vector con las coordenadas de las centrales.
 * @return Índice de la central más cercana.
 */
int encontrar_central_cercana(const Punto& colonia, const std::vector<Punto>& centrales) {
    if (centrales.empty()) {
        throw std::invalid_argument("El vector de centrales está vacío.");
    }

    // Guardar el índice de la central más cercana
    int indice_central_mas_cercana = 0;

    // Calcular la distancia de la colonia a la primera central
    double distancia_minima = colonia.distancia(centrales[0]);

    for (size_t i = 1; i < centrales.size(); i++) {
        // Calcular la distancia de la colonia a cada central
        double distancia = colonia.distancia(centrales[i]);

        // Validar si la distancia es menor a la previamente calculada
        if (distancia < distancia_minima) {
            // Actualizar la distancia mínima y el índice de la central más cercana
            distancia_minima = distancia;
            indice_central_mas_cercana = i;
        }
    }

    return indice_central_mas_cercana;
}

#endif // CENTRAL_H

