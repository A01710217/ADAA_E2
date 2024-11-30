/**
 * Archivo: unionFind.h
 * Autor: Carlos Anaya Ruiz
 * Descripción: Funciones para implementar la estructura de datos Union-Find.
 * Fecha: 2024
 * Versión: 1.0
 * 
 * Este archivo define la clase UnionFind que implementa la estructura de datos Union-Find.
 * 
 * La clase UnionFind tiene dos atributos: parent y rank, que representan el padre de un conjunto
 * y la altura de un conjunto, respectivamente.
 * 
 * La clase UnionFind tiene un constructor que inicializa los atributos de la estructura.
 * 
 * La clase UnionFind tiene métodos para encontrar el padre de un conjunto y unir dos conjuntos.
 * 
 * La complejidad de la clase es O(alpha(n)), donde alpha(n) es la inversa de la función de Ackermann.
 */
#ifndef UNIONFIND_H
#define UNIONFIND_H

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
    int find(int);

    /**
     * @brief Une dos conjuntos.
     * 
     * @param s1 Elemento del primer conjunto.
     * @param s2 Elemento del segundo conjunto.
     */
    void unionSets(int s1, int s2);
};

UnionFind::UnionFind(int size) : parent(size), rank(size, 0) {
    for (int i = 0; i < size; ++i) parent[i] = i;
}

int UnionFind::find(int s) {
    if (s != parent[s])
        parent[s] = find(parent[s]);
    return parent[s];
}

void UnionFind::unionSets(int s1, int s2) {
    int root1 = find(s1);
    int root2 = find(s2);
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