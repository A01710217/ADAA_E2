/*
 * Archivo: central.h
 * Autor: Axel Camacho Villafuerte
 * Descripción: Este archivo contiene la implementación de funciones para encontrar 
 *              la central más cercana a una colonia, utilizando las coordenadas 
 *              proporcionadas.
 * Fecha: 2024
 * Versión: 1.1
 *
 * Detalles:
 * - Define la función `encontrar_central_cercana`, que calcula el índice de la
 *   central más cercana a una colonia usando coordenadas cartesianas.
 * - Incluye verificaciones para manejar errores como vectores vacíos.
 * 
 * Complejidad:
 * - Función principal: O(n), donde n es el número de centrales.
 * 
 * Dependencias:
 * - Requiere la clase `Punto` definida en "punto.h".
 */

#ifndef CENTRAL_H
#define CENTRAL_H

#include <vector>
#include "punto.h"

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
    double distancia_minima = colonia.Distancia(centrales[0]);

    for (size_t i = 1; i < centrales.size(); i++) {
        // Calcular la distancia de la colonia a cada central
        double distancia = colonia.Distancia(centrales[i]);

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
