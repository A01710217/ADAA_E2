
/*
 * Archivo: main.cpp
 * E2. Actividad Integradora 2
 * Autores: 
 *      Axel Camacho Villafuerte
 *      Mónica Soberón Zubía
 *      Carlos Anaya Ruiz
 * Descripción: Archivo principal del proyecto E2. 
 *              Este programa realiza diversas operaciones sobre un grafo:
 *              - Calcula el Árbol de Expansión Mínima (MST) usando el algoritmo de Kruskal.
 *              - Encuentra el costo mínimo del Problema del Viajante (TSP).
 *              - Calcula el flujo máximo usando el algoritmo de Ford-Fulkerson.
 *              - Determina la central más cercana a una nueva ubicación.
 * 
 * Entrada:
 * - El programa lee los datos desde un archivo de texto, por defecto: "Entradas/Entrada01.txt".
 * 
 * Salida:
 * - Resultados de las operaciones en la terminal:
 *   1. Las aristas del MST.
 *   2. La ruta del TSP.
 *   3. El flujo máximo entre el nodo fuente y el nodo sumidero.
 *   4. Las coordenadas de la central más cercana.
 * 
 * Compilación:
 * - Utiliza el comando: `g++ main.cpp -o main`.
 * 
 * Ejecución:
 * - Ejecuta el programa con: `./main`.
 * 
 * Fecha: 2024
 * Versión: 1.1
 */

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream> // Para procesar líneas
#include <algorithm> // Para std::sort
#include <queue>   // Para std::queue
#include <climits>  // Para INT_MAX
#include <cstring>  // Para memset

//Importar la clase Punto
#include "punto.h"
//Importar la clase Edge
#include "edge.h"
//Importar la clase UnionFind
#include "union_find.h"

//Importar la función para calcular el flujo máximo
#include "ford_fulkerson.h"
//Importar la función para calcular el costo mínimo del TSP
#include "tsp.h"
//Importar la función para calcular el MST
#include "kruskal.h"
//Importar la función para encontrar la central más cercana
#include "central.h"

using namespace std;

//Función para saltar líneas vacías o con solo espacios
void leer_linea_valida(ifstream& archivo, string& linea) {
    do {
        getline(archivo, linea);
    } while (archivo && (linea.empty() || std::all_of(linea.begin(), linea.end(), [](unsigned char c) { return std::isspace(c); })));
}

//Función para leer las entradas desde un archivo
void leer_archivos(const string& nombreArchivo, 
                              int& N, 
                              vector<vector<int>>& distancias, 
                              vector<vector<int>>& capacidades, 
                              vector<Punto>& centrales, 
                              Punto& nuevaCentral) {
    ifstream archivo(nombreArchivo);

    //Validar si el archivo se abrió correctamente
    if (!archivo.is_open()) {
        cout << "main.cpp" << ": File \"" << nombreArchivo << "\" not found\n";
        exit(-1);  //Salir del programa con un código de error
    }

    string linea;

    //Leer el número de colonias
    leer_linea_valida(archivo, linea);
    N = stoi(linea);

    //Leer la matriz de distancias
    distancias.resize(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        leer_linea_valida(archivo, linea);
        istringstream stream(linea);
        for (int j = 0; j < N; ++j) {
            stream >> distancias[i][j];
        }
    }

    //Leer la matriz de capacidades
    capacidades.resize(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        leer_linea_valida(archivo, linea);
        istringstream stream(linea);
        for (int j = 0; j < N; ++j) {
            stream >> capacidades[i][j];
        }
    }

    //Leer las coordenadas de las centrales
    for (int i = 0; i < N; ++i) {
        leer_linea_valida(archivo, linea);
        size_t pos1 = linea.find('(');
        size_t pos2 = linea.find(',');
        size_t pos3 = linea.find(')');
        int x = stoi(linea.substr(pos1 + 1, pos2 - pos1 - 1));
        int y = stoi(linea.substr(pos2 + 1, pos3 - pos2 - 1));
        centrales.emplace_back(x, y);
    }

    //Leer la ubicación de la nueva central
    leer_linea_valida(archivo, linea);
    size_t pos1 = linea.find('(');
    size_t pos2 = linea.find(',');
    size_t pos3 = linea.find(')');
    int x = stoi(linea.substr(pos1 + 1, pos2 - pos1 - 1));
    int y = stoi(linea.substr(pos2 + 1, pos3 - pos2 - 1));
    nuevaCentral = Punto(x, y);

    archivo.close();
}

int main(){
    int N; //Un numero entero N que representa el número de colonias en la ciudad
    vector<vector<int>> distancias; //Una matriz cuadrada de N x N que representa el grafo con las distancias en kilómetros entre las colonias de la ciudad
    vector<vector<int>> capacidades; //Una matriz cuadrada de N x N que representa las capacidades máximas de flujo de datos entre colonia i y colonia j

    vector<Punto> centrales; //Una lista de N pares ordenados de la forma (A,B) que representan la ubicación en un plano coordenado de las centrales
    Punto nuevaCentral; //La ubicación de la nueva central

    // Leer datos desde el archivo
    leer_archivos("./Entradas/Entrada01.txt", N, distancias, capacidades, centrales, nuevaCentral);

    // 1. Calcular el MST
    vector<Edge> aristas;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            aristas.push_back(Edge(i, j, distancias[i][j]));
        }
    }

    vector<Edge> mst = kruskal_mst(aristas, N);

    // 2. Calcular el costo mínimo del TSP
    int costoMinimo = tsp(distancias);

    // 3. Calcular el flujo máximo
    int source = 0;
    int sink = N - 1;
    int flujoMaximo = ford_fulkerson(capacidades, source, sink);

    // 4. Encontrar la central más cercana
    int indiceCentral = encontrar_central_cercana(nuevaCentral, centrales);
    Punto centralCercana = centrales[indiceCentral];

    // Salida
    cout << "1." << endl;
    for (const auto& e : mst) {
        cout << "(" << char('A' + e.src) << ", " << char('A' + e.dest) << ")" << endl;
    }

    cout << endl;

    cout << "2." << endl;
    get_route(1, 0, N); // Reconstruir e imprimir la ruta desde la ciudad 0
    cout << "A" << endl; // Regresar a la ciudad inicial

    cout << endl;

    cout << "3." << endl;
    cout << flujoMaximo << endl;

    cout << endl;

    cout << "4." << endl;
    cout << "(" << centralCercana.GetX() << ", " << centralCercana.GetY() << ")" << endl;

    return 0;
}
