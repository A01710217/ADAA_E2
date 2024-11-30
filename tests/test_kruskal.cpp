#include <gtest/gtest.h>
#include "kruskal.h"
#include "edge.h"


TEST(KruskalTest, MSTTest) {
    std::vector<Edge> aristas = {
        Edge(0, 1, 10),
        Edge(1, 2, 15),
        Edge(0, 2, 5)
    };
    int N = 3;
    std::vector<Edge> mst = kruskalMST(aristas, N);
    ASSERT_EQ(mst.size(), 2);  // El MST debe tener 2 aristas
    ASSERT_EQ(mst[0].weight, 5); // La arista de menor peso debe estar primero
}