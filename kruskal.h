/*
 * Archivo: kruskal.h
 * Autor: Carlos Anaya Ruiz
 * Descripción: Funciones para encontrar el árbol de expansión mínima de un grafo.
 * Fecha: 2024
 * Versión: 1.0
 * 
 * Este archivo define la función compare_weight y la función kruskal_mst, que implementan
 * el algoritmo de Kruskal para encontrar el árbol de expansión mínima de un grafo.
 * 
 * La función compare_weight es un comparador para ordenar aristas por peso.
 * 
 * La función kruskal_mst aplica el algoritmo de Kruskal para encontrar el árbol de expansión
 * mínima de un grafo.
 * 
 * La complejidad de la función compare_weight es O(1).
 * 
 * La complejidad de la función kruskal_mst es O(n log n), donde n es el número de aristas.
*/
#ifndef KRUSKAL_H
#define KRUSKAL_H

#include <vector>
#include <algorithm>
#include "edge.h"
#include "unionFind.h"

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
        int root1 = uf.find(e.src);
        int root2 = uf.find(e.dest);
        if (root1 != root2) {
            mst.push_back(e);
            uf.unionSets(root1, root2);
        }
    }

    return mst;
}

#endif