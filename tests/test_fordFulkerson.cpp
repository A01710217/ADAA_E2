#include <gtest/gtest.h>
#include "fordFulkerson.h"

TEST(FordFulkersonTest, MaxFlowTest) {
    std::vector<std::vector<int>> capacidades = {
        {0, 10, 10},
        {0, 0, 10},
        {0, 0, 0}
    };
    int flujoMaximo = fordFulkerson(capacidades, 0, 2);
    ASSERT_EQ(flujoMaximo, 20); // El flujo máximo esperado es 20
}