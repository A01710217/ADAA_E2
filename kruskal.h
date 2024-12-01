/*
 * Archivo: kruskal.h
 * Autor: Monica Soberon Zubia
 * Descripción: Implementación del algoritmo de Kruskal para encontrar el árbol de expansión mínima (MST) de un grafo.
 * Fecha: 2024
 * Versión: 1.1
 * 
 * Este archivo define dos funciones principales:
 * - `compare_weight`: Comparador para ordenar aristas por peso.
 * - `kruskal_mst`: Implementa el algoritmo de Kruskal para encontrar el MST de un grafo.
 * 
 * Complejidad:
 * - `compare_weight`: O(1), ya que realiza una simple comparación entre pesos de las aristas.
 * - `kruskal_mst`: O(n log n), donde n es el número de aristas. Esto incluye el tiempo de ordenamiento y la unión de conjuntos disjuntos.
 * 
 * Dependencias:
 * - Incluye "edge.h" para la representación de aristas.
 * - Incluye "unionFind.h" para la estructura de conjuntos disjuntos (Union-Find).
 * - Utiliza las bibliotecas estándar de C++: `<vector>` y `<algorithm>`.
 * 
 * Uso:
 * - Ideal para resolver problemas que requieren encontrar el árbol de expansión mínima de un grafo conexo y ponderado.
 */

#ifndef KRUSKAL_H
#define KRUSKAL_H

#include <vector>
#include <algorithm>
#include "edge.h"
#include "union_find.h"

/**
 * @brief Comparador para ordenar aristas por peso.
 * 
 * @param e1 Arista 1.
 * @param e2 Arista 2.
 * @return true si el peso de la arista 1 es menor que el peso de la arista 2, false en caso contrario.
 * 
 * Complejidad: O(1)
 */
bool compare_weight(const Edge& e1, const Edge& e2) {
    return e1.weight < e2.weight;
}

/**
 * @brief Aplica el algoritmo de Kruskal para encontrar el árbol de expansión mínima de un grafo.
 * 
 * @param edges Vector con las aristas del grafo.
 * @param N Número de nodos del grafo.
 * @return Vector con las aristas del árbol de expansión mínima.
 * 
 * Complejidad: O(n log n), donde n es el número de aristas.
*/
std::vector<Edge> kruskal_mst(std::vector<Edge>& edges, int N) {
    sort(edges.begin(), edges.end(), compare_weight);
    UnionFind uf(N);
    std::vector<Edge> mst;

    for (const auto& e : edges) {
        int root1 = uf.FindSet(e.src);
        int root2 = uf.FindSet(e.dest);
        if (root1 != root2) {
            mst.push_back(e);
            uf.UnionSets(root1, root2);
        }
    }

    return mst;
}

#endif
