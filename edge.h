#ifndef EDGE_H
#define EDGE_H

class Edge {
public:
    int src;
    int dest;
    int weight;

    Edge(int, int, int);
};

Edge::Edge(int src, int dest, int weight) : src(src), dest(dest), weight(weight) {}

#endif