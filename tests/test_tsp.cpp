#include <gtest/gtest.h>
#include "tsp.h"


TEST(TSPTest, CostTest) {
    std::vector<std::vector<int>> distancias = {
        {0, 10, 15},
        {10, 0, 35},
        {15, 35, 0}
    };
    int costoMinimo = tsp(distancias);
    ASSERT_EQ(costoMinimo, 60);  // Valor esperado basado en las distancias
}