#ifndef UNIONFIND_H
#define UNIONFIND_H

#include <vector>

class UnionFind {
private:
    std::vector<int> parent, rank;
public:
    UnionFind(int);

    int find(int);

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