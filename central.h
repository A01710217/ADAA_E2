#ifndef CENTRAL_H
#define CENTRAL_H

#include <vector>
#include "punto.h"

//Función que calcuala la central más cercana a una colonia
//Complejidad: O(n)
int centralMasCercana(const Punto& colonia, const std::vector<Punto>& centrales) {
    //Guardar el índice de la central más cercana
    int indiceCentralMasCercana = 0;
    //Calcular la distancia de la colonia a la primera central
    double distanciaMinima = colonia.distancia(centrales[0]);

    for (int i = 1; i < centrales.size(); i++) {
        //Calcular la distancia de la colonia a cada central
        double distancia = colonia.distancia(centrales[i]);

        //Validar si la distancia es menor a la previamente calculada
        if (distancia < distanciaMinima) {
            //Actualizar la distancia mínima y el índice de la central más cercana
            distanciaMinima = distancia;
            indiceCentralMasCercana = i;
        }
    }

    return indiceCentralMasCercana;
}

#endif