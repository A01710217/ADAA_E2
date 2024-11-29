#ifndef FORDFULKERSON_H
#define FORDFULKERSON_H

#include <vector>
#include <climits>
#include <queue>

using namespace std;

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

#endif
