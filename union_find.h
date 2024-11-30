/*
 * Archivo: union_find.h
 * Autor: Carlos Anaya Ruiz
 * Descripción: Implementación de la estructura de datos Union-Find (Conjuntos Disjuntos).
 * Fecha: 2024
 * Versión: 1.1
 * 
 * Este archivo define la clase `UnionFind`, que incluye:
 * - Métodos para encontrar el padre de un conjunto (con compresión de caminos).
 * - Métodos para unir dos conjuntos (unión por rango).
 * 
 * Complejidad:
 * - Las operaciones `FindSet` y `UnionSets` tienen una complejidad amortizada de O(α(n)),
 *   donde α(n) es la inversa de la función de Ackermann.
 * 
 * Dependencias:
 * - Utiliza la biblioteca estándar `<vector>`.
 */

#ifndef UNION_FIND_H
#define UNION_FIND_H

#include <vector>

/**
 * @brief Clase que implementa la estructura de datos Union-Find.
 */
class UnionFind {
private:
    /**
     * @brief Vector que almacena el padre de un conjunto.
     */
    std::vector<int> parent, rank;
public:
    /**
     * @brief Constructor de la clase UnionFind.
     * 
     * @param size Tamaño de la estructura.
     */
    UnionFind(int);

    /**
     * @brief Encuentra el padre de un conjunto.
     * 
     * @param s Elemento del conjunto.
     * @return Padre del conjunto.
     */
    int FindSet(int);

    /**
     * @brief Une dos conjuntos.
     * 
     * @param s1 Elemento del primer conjunto.
     * @param s2 Elemento del segundo conjunto.
     */
    void UnionSets(int s1, int s2);
};

UnionFind::UnionFind(int size) : parent(size), rank(size, 0) {
    for (int i = 0; i < size; ++i) parent[i] = i;
}

int UnionFind::FindSet(int s) {
    if (s != parent[s])
        parent[s] = FindSet(parent[s]);
    return parent[s];
}

void UnionFind::UnionSets(int s1, int s2) {
    int root1 = FindSet(s1);
    int root2 = FindSet(s2);
    if (root1 != root2) {
        if (rank[root1] > rank[root2])
            parent[root2] = root1;
        else if (rank[root1] < rank[root2])
            parent[root1] = root2;
        else {
            parent[root2] = root1;
            rank[root1]++;
        }
    }
}

#endif
