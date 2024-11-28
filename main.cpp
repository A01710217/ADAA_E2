#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

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
    vector<pair<int, int>> centrales = {
        {200, 500},
        {300, 100},
        {450, 150},
        {520, 480}
    };

    //La ubicación de la nueva central
    vector<int> nuevaCentral = {400, 300};

    return 0;
}