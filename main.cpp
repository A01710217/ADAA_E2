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
#include "unionFind.h"

// Variables globales para memorización y reconstrucción de la ruta
const int MAX = 20; // Máximo número de nodos
int dp[1 << MAX][MAX]; // Memorización para el TSP
int parent[1 << MAX][MAX]; // Para reconstruir la ruta óptima

using namespace std;

//Función para saltar líneas vacías o con solo espacios
void leerLineaValida(ifstream& archivo, string& linea) {
    do {
        getline(archivo, linea);
    } while (archivo && (linea.empty() || std::all_of(linea.begin(), linea.end(), [](unsigned char c) { return std::isspace(c); })));
}

//Función para leer las entradas desde un archivo
void leerEntradasDesdeArchivo(const string& nombreArchivo, 
                              int& N, 
                              vector<vector<int>>& distancias, 
                              vector<vector<int>>& capacidades, 
                              vector<Punto>& centrales, 
                              Punto& nuevaCentral) {
    ifstream archivo(nombreArchivo);

    //Validar si el archivo se abrió correctamente
    if (!archivo.is_open()) {
        cout << "main.cpp" << ": File \"" << nombreArchivo << "\" not found\n";
        exit(-1);  // Salir del programa con un código de error
    }

    string linea;

    // Leer el número de colonias
    leerLineaValida(archivo, linea);
    N = stoi(linea);

    // Leer la matriz de distancias
    distancias.resize(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        leerLineaValida(archivo, linea);
        istringstream stream(linea);
        for (int j = 0; j < N; ++j) {
            stream >> distancias[i][j];
        }
    }

    // Leer la matriz de capacidades
    capacidades.resize(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        leerLineaValida(archivo, linea);
        istringstream stream(linea);
        for (int j = 0; j < N; ++j) {
            stream >> capacidades[i][j];
        }
    }

    // Leer las coordenadas de las centrales
    for (int i = 0; i < N; ++i) {
        leerLineaValida(archivo, linea);
        size_t pos1 = linea.find('(');
        size_t pos2 = linea.find(',');
        size_t pos3 = linea.find(')');
        int x = stoi(linea.substr(pos1 + 1, pos2 - pos1 - 1));
        int y = stoi(linea.substr(pos2 + 1, pos3 - pos2 - 1));
        centrales.emplace_back(x, y);
    }

    // Leer la ubicación de la nueva central
    leerLineaValida(archivo, linea);
    size_t pos1 = linea.find('(');
    size_t pos2 = linea.find(',');
    size_t pos3 = linea.find(')');
    int x = stoi(linea.substr(pos1 + 1, pos2 - pos1 - 1));
    int y = stoi(linea.substr(pos2 + 1, pos3 - pos2 - 1));
    nuevaCentral = Punto(x, y);

    archivo.close();
}


// Comparador para ordenar aristas por peso
//Complejidad: O(1)
bool compareWeight(const Edge& e1, const Edge& e2) {
    return e1.weight < e2.weight;
}

// Función principal para aplicar el algoritmo de Kruskal
//Complejidad: O(n log n)
vector<Edge> kruskalMST(vector<Edge>& edges, int N) {
    //Ordenar las aristas por peso
    sort(edges.begin(), edges.end(), compareWeight);
    //Crear una estructura UnionFind
    UnionFind uf(N);

    //Almacenará el MST resultante
    vector<Edge> mst;

    for (const auto& e : edges) {
        //Encontrar la raíz de cada conjunto
        int root1 = uf.find(e.src);
        int root2 = uf.find(e.dest);
        //Validar si las aristas no forman un ciclo
        if (root1 != root2) {
            //Agregar la arista al MST
            mst.push_back(e);
            //Unir los conjuntos
            uf.unionSets(root1, root2);
        }
    }

    return mst;
}


// Función recursiva para encontrar el costo mínimo de la ruta
//Complejidad: O(2^n * n^2)
int totalCost(int mask, int pos, int n, const vector<vector<int>>& cost) {
    // Caso base: si todas las ciudades han sido visitadas
    if (mask == (1 << n) - 1) {
        return cost[pos][0]; // Regresar al punto de inicio
    }

    // Si ya se calculó este estado, regresamos el valor memorizado
    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int ans = INT_MAX;

    // Probar visitar cada ciudad no visitada
    for (int i = 0; i < n; ++i) {
        if ((mask & (1 << i)) == 0) { // Si la ciudad `i` no ha sido visitada
            int newAns = cost[pos][i] + totalCost(mask | (1 << i), i, n, cost);
            if (newAns < ans) {
                ans = newAns;
                parent[mask][pos] = i; // Guardar la ciudad `i` como próxima en la ruta óptima
            }
        }
    }

    return dp[mask][pos] = ans; // Guardar el resultado en dp
}

// Función para reconstruir la ruta óptima
//Complejidad: O(n)
void getRoute(int mask, int pos, int n) {
    cout << char('A' + pos) << " "; // Imprimir la ciudad actual
    if (mask == (1 << n) - 1) return; // Caso base: todas las ciudades visitadas

    int nextCity = parent[mask][pos];
    getRoute(mask | (1 << nextCity), nextCity, n); // Moverse a la siguiente ciudad
}

// Función principal para resolver el TSP
//Complejidad: O(2^n * n^2)
int tsp(const vector<vector<int>>& cost) {
    int n = cost.size();

    // Inicializar la tabla de memorización y reconstrucción
    memset(dp, -1, sizeof(dp));
    memset(parent, -1, sizeof(parent));

    // Iniciar desde la ciudad 0 y con la máscara inicial (solo 0 visitada)
    return totalCost(1, 0, n, cost);
}


// Función para realizar una búsqueda en anchura (BFS) y encontrar si existe un camino de aumento
//Complejidad: O(n)
bool bfs(const vector<vector<int>>& residualGraph, int source, int sink, vector<int>& parent) {
    int V = residualGraph.size();
    vector<bool> visited(V, false);
    queue<int> q;
    q.push(source);
    visited[source] = true;
    parent[source] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < V; ++v) {
            if (!visited[v] && residualGraph[u][v] > 0) {  // Revisa si el nodo v no fue visitado y si es alcanzable desde u
                if (v == sink) {
                    parent[v] = u;
                    return true;
                }
                q.push(v);
                visited[v] = true;
                parent[v] = u;
            }
        }
    }
    return false;
}

// Función para aplicar el algoritmo de Ford-Fulkerson para encontrar el flujo máximo desde s a t
//Complejidad: O(n^2 * m)
int fordFulkerson(vector<vector<int>> graph, int source, int sink) {
    int u, v;
    int V = graph.size();
    vector<vector<int>> residualGraph = graph;  // Grafo residual donde residualGraph[u][v] indica capacidad residual de u a v
    vector<int> parent(V);  // Almacenar el camino
    int maxFlow = 0;  // Flujo máximo inicialmente es 0

    // Aumenta el flujo mientras haya un camino de aumento
    while (bfs(residualGraph, source, sink, parent)) {
        // Encontrar la capacidad residual mínima de las aristas a lo largo del camino llenado por BFS
        int pathFlow = INT_MAX;
        for (v = sink; v != source; v = parent[v]) {
            u = parent[v];
            pathFlow = min(pathFlow, residualGraph[u][v]);
        }

        // Actualizar las capacidades residuales de las aristas y las aristas inversas a lo largo del camino
        for (v = sink; v != source; v = parent[v]) {
            u = parent[v];
            residualGraph[u][v] -= pathFlow;
            residualGraph[v][u] += pathFlow;
        }

        maxFlow += pathFlow;
    }
    return maxFlow;
}


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

int main(int argc, char* argv[]){
    int N; //Un numero entero N que representa el número de colonias en la ciudad
    vector<vector<int>> distancias; //Una matriz cuadrada de N x N que representa el grafo con las distancias en kilómetros entre las colonias de la ciudad
    vector<vector<int>> capacidades; //Una matriz cuadrada de N x N que representa las capacidades máximas de flujo de datos entre colonia i y colonia j

    vector<Punto> centrales; //Una lista de N pares ordenados de la forma (A,B) que representan la ubicación en un plano coordenado de las centrales
    Punto nuevaCentral; //La ubicación de la nueva central

    // Leer datos desde el archivo
    leerEntradasDesdeArchivo("./Entradas/Entrada01.txt", N, distancias, capacidades, centrales, nuevaCentral);

    // 1. Calcular el MST
    vector<Edge> aristas;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            aristas.push_back(Edge(i, j, distancias[i][j]));
        }
    }

    vector<Edge> mst = kruskalMST(aristas, N);

    // 2. Calcular el costo mínimo del TSP
    int costoMinimo = tsp(distancias);

    // 3. Calcular el flujo máximo
    int source = 0;
    int sink = N - 1;
    int flujoMaximo = fordFulkerson(capacidades, source, sink);

    // 4. Encontrar la central más cercana
    int indiceCentral = centralMasCercana(nuevaCentral, centrales);
    Punto centralCercana = centrales[indiceCentral];

    // Salida
    cout << "1." << endl;
    for (const auto& e : mst) {
        cout << "(" << char('A' + e.src) << ", " << char('A' + e.dest) << ")" << endl;
    }

    cout << endl;

    cout << "2." << endl;
    getRoute(1, 0, N); // Reconstruir e imprimir la ruta desde la ciudad 0
    cout << "A" << endl; // Regresar a la ciudad inicial

    cout << endl;

    cout << "3." << endl;
    cout << flujoMaximo << endl;

    cout << endl;

    cout << "4." << endl;
    cout << "(" << centralCercana.getX() << ", " << centralCercana.getY() << ")" << endl;

    return 0;
}
