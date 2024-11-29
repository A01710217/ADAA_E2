#include <gtest/gtest.h>
#include "edge.h"
#include "unionFind.h"
#include "punto.h"
#include <vector>
#include "fordFulkerson.h"
#include "tsp.h"
#include "kruskal.h"
#include "central.h"

// Test para Kruskal
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

// Test para TSP
TEST(TSPTest, CostTest) {
    std::vector<std::vector<int>> distancias = {
        {0, 10, 15},
        {10, 0, 35},
        {15, 35, 0}
    };
    int costoMinimo = tsp(distancias);
    ASSERT_EQ(costoMinimo, 60);  // Valor esperado basado en las distancias
}

// Test para Ford-Fulkerson
TEST(FordFulkersonTest, MaxFlowTest) {
    std::vector<std::vector<int>> capacidades = {
        {0, 10, 10},
        {0, 0, 10},
        {0, 0, 0}
    };
    int flujoMaximo = fordFulkerson(capacidades, 0, 2);
    ASSERT_EQ(flujoMaximo, 20); // El flujo máximo esperado es 20
}

// Test para encontrar la central más cercana
TEST(CentralMasCercanaTest, BasicTest) {
    std::vector<Punto> centrales = {Punto(200, 500), Punto(300, 100), Punto(450, 150), Punto(520, 480)};
    Punto nuevaCentral(400, 300);

    // Ejecutar la función para encontrar la central más cercana
    int indiceCentral = centralMasCercana(nuevaCentral, centrales);

    // Verificar que el índice de la central más cercana es el correcto
    ASSERT_EQ(indiceCentral, 2);  // Verifica que la central más cercana sea la de índice 2
    Punto centralCercana = centrales[indiceCentral];
    ASSERT_EQ(centralCercana.getX(), 450);  // Verifica la coordenada X de la central más cercana
    ASSERT_EQ(centralCercana.getY(), 150);  // Verifica la coordenada Y de la central más cercana
}


int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();  // Ejecutar todas las pruebas
}
