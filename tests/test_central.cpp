#include <gtest/gtest.h>
#include "central.h"
#include "punto.h"


TEST(CentralMasCercanaTest, BasicTest) {
    std::vector<Punto> centrales = {Punto(200, 500), Punto(300, 100), Punto(450, 150), Punto(520, 480)};
    Punto nuevaCentral(400, 300);

    int indiceCentral = encontrar_central_cercana(nuevaCentral, centrales);

    ASSERT_EQ(indiceCentral, 2);  // Verifica que la central más cercana sea la de índice 2
    Punto centralCercana = centrales[indiceCentral];
    ASSERT_EQ(centralCercana.get_x(), 450);
    ASSERT_EQ(centralCercana.get_y(), 150);
}