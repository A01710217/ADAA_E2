/*
 * SonarQube, open source software quality management tool.
 * Copyright (C) 2008-2013 SonarSource
 * http://github.com/SonarOpenCommunity/sonar-cxx
 *
 * SonarQube is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * SonarQube is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
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
