#ifndef KRUSKAL_H
#define KRUSKAL_H

#include <vector>
#include <algorithm>
#include "edge.h"
#include "unionFind.h"

// Comparador para ordenar aristas por peso
//Complejidad: O(1)
bool compareWeight(const Edge& e1, const Edge& e2) {
    return e1.weight < e2.weight;
}

// Función principal para aplicar el algoritmo de Kruskal
//Complejidad: O(n log n)
std::vector<Edge> kruskalMST(std::vector<Edge>& edges, int N) {
    sort(edges.begin(), edges.end(), compareWeight);
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