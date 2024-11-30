
/*
 * Archivo: ford_fulkerson.h
 * Autor: Carlos Anaya Ruiz
 * Descripción: Implementación de funciones para encontrar el flujo máximo entre dos nodos 
 *              usando el algoritmo de Ford-Fulkerson.
 * Fecha: 2024
 * Versión: 1.1
 * 
 * Este archivo define dos funciones principales:
 * - `bfs`: Realiza una búsqueda en anchura (BFS) para encontrar un camino de aumento.
 * - `ford_fulkerson`: Implementa el algoritmo de Ford-Fulkerson para calcular el flujo máximo
 *   entre un nodo fuente y un nodo sumidero.
 * 
 * Complejidad:
 * - `bfs`: O(n), donde n es el número de nodos.
 * - `ford_fulkerson`: O(n^2 * m), donde n es el número de nodos y m es el número de aristas.
 * 
 * Dependencias:
 * - Utiliza las bibliotecas estándar de C++: `<vector>`, `<climits>`, y `<queue>`.
 * 
 * Uso:
 * - Ideal para problemas de flujo máximo en redes dirigidas con capacidades no negativas.
 */

#ifndef FORD_FULKERSON_H
#define FORD_FULKERSON_H

#include <vector>
#include <climits>
#include <queue>

using namespace std;

/**
 * @brief Realiza una búsqueda en anchura (BFS) para encontrar un camino de aumento.
 * 
 * @param residualGraph Grafo residual representado como una matriz de adyacencia.
 * @param source Nodo fuente.
 * @param sink Nodo sumidero.
 * @param parent Vector para almacenar el camino encontrado.
 * @return true si existe un camino de aumento, false en caso contrario.
 * 
 * Complejidad: O(n), donde n es el número de nodos.
 */
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

/**
 * @brief Implementa el algoritmo de Ford-Fulkerson para encontrar el flujo máximo entre dos nodos.
 * 
 * @param graph Grafo representado como una matriz de adyacencia, donde cada elemento representa la capacidad.
 * @param source Nodo fuente.
 * @param sink Nodo sumidero.
 * @return Flujo máximo entre el nodo fuente y el nodo sumidero.
 * 
 * Complejidad: O(n^2 * m), donde n es el número de nodos y m es el número de aristas.
 */
int ford_fulkerson(vector<vector<int>> graph, int source, int sink) {
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

#endif
