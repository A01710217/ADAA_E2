#include <iostream>
#include <vector>
#include <algorithm> // Para std::sort

using namespace std;

// Estructura para representar una arista
struct Edge {
    int src, dest, weight;
};

// Comparador para ordenar aristas por peso
bool compareWeight(const Edge& e1, const Edge& e2) {
    return e1.weight < e2.weight;
}

// Clase para encontrar conjuntos con Union-Find
class UnionFind {
private:
    vector<int> parent, rank;
public:
    UnionFind(int size) : parent(size), rank(size, 0) {
        for (int i = 0; i < size; ++i) parent[i] = i;
    }

    int find(int s) {
        if (s != parent[s])
            parent[s] = find(parent[s]);
        return parent[s];
    }

    void unionSets(int s1, int s2) {
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
};

// Función principal para aplicar el algoritmo de Kruskal
vector<Edge> kruskalMST(vector<Edge>& edges, int N) {
    sort(edges.begin(), edges.end(), compareWeight);
    UnionFind uf(N);

    vector<Edge> mst; // Almacenará el MST resultante

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

int main() {
    int N; // Número de nodos
    cin >> N;
    vector<Edge> edges;

    // Leer la matriz de adyacencia y convertirla en una lista de aristas
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int weight;
            cin >> weight;
            if (weight != 0) {
                edges.push_back({i, j, weight});
            }
        }
    }

    vector<Edge> mst = kruskalMST(edges, N);

    // Imprimir el MST
    cout << "Edges in MST:\n";
    for (const auto& e : mst) {
        cout << "(" << char('A' + e.src) << ", " << char('A' + e.dest) << ")" << endl;
    }

    return 0;
}
