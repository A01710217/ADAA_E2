#include <iostream>
#include <vector>
#include <fstream>

//Importar la clase Punto
#include "punto.h"

using namespace std;

//Función que calcuala la central más cercana a una colonia
//Complejidad: O(n)
int centralMasCercana(const Punto& colonia, const vector<Punto>& centrales) {
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

int main(){
    //Entradas de prueba:
    //Un numero entero N que representa el número de colonias en la ciudad
    int N = 4;

    //Una matriz cuadrada de N x N que representa el grafo con las distancias en kilómetros entre las colonias de la ciudad
    vector<vector<int>> distancias = {
        {0, 16, 54, 32},
        {16, 0, 18, 21},
        {45, 18, 0, 7},
        {32, 21, 7, 0}
    };

    //Una matriz cuadrada de N x N que representa las capacidades máximas de flujo de datos entre colonia i y colonia j
    vector<vector<int>> capacidades = {
        {0, 48, 12, 18},
        {52, 0, 42, 32},
        {18, 46, 0, 56},
        {24, 36, 52, 0}
    };

    //Una lista de N pares ordenados de la forma (A,B) que representan la ubicación en un plano coordenado de las centrales
    vector<Punto> centrales = {
        Punto(200, 500),
        Punto(300, 100),
        Punto(450, 150),
        Punto(520, 480)
    };

    //La ubicación de la nueva central
    Punto nuevaCentral(400, 300);

    // Encontrar la central más cercana
    int indiceCentral = centralMasCercana(nuevaCentral, centrales);
    Punto centralCercana = centrales[indiceCentral];

    // Salida
    cout << "4." << endl;
    cout << "(" << centralCercana.getX() << ", " << centralCercana.getY() << ")" << endl;

    return 0;
}