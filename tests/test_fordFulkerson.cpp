#include <gtest/gtest.h>
#include "ford_fulkerson.h"

TEST(FordFulkersonTest, MaxFlowTest) {
    std::vector<std::vector<int>> capacidades = {
        {0, 10, 10},
        {0, 0, 10},
        {0, 0, 0}
    };
    int flujoMaximo = ford_fulkerson(capacidades, 0, 2);
    ASSERT_EQ(flujoMaximo, 20); // El flujo máximo esperado es 20
}