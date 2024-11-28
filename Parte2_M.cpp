#include <iostream>
#include <vector>
#include <climits>  // Para INT_MAX
#include <cstring>  // Para memset

using namespace std;

// Variables globales para memorización y reconstrucción de la ruta
const int MAX = 20; // Máximo número de nodos
int dp[1 << MAX][MAX]; // Memorización para el TSP
int parent[1 << MAX][MAX]; // Para reconstruir la ruta óptima

// Función recursiva para encontrar el costo mínimo de la ruta
int totalCost(int mask, int pos, int n, const vector<vector<int>>& cost) {
    // Caso base: si todas las ciudades han sido visitadas
    if (mask == (1 << n) - 1) {
        return cost[pos][0]; // Regresar al punto de inicio
    }

    // Si ya se calculó este estado, regresamos el valor memorizado
    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int ans = INT_MAX;

    // Probar visitar cada ciudad no visitada
    for (int i = 0; i < n; ++i) {
        if ((mask & (1 << i)) == 0) { // Si la ciudad `i` no ha sido visitada
            int newAns = cost[pos][i] + totalCost(mask | (1 << i), i, n, cost);
            if (newAns < ans) {
                ans = newAns;
                parent[mask][pos] = i; // Guardar la ciudad `i` como próxima en la ruta óptima
            }
        }
    }

    return dp[mask][pos] = ans; // Guardar el resultado en dp
}

// Función para reconstruir la ruta óptima
void getRoute(int mask, int pos, int n) {
    cout << char('A' + pos) << " "; // Imprimir la ciudad actual
    if (mask == (1 << n) - 1) return; // Caso base: todas las ciudades visitadas

    int nextCity = parent[mask][pos];
    getRoute(mask | (1 << nextCity), nextCity, n); // Moverse a la siguiente ciudad
}

// Función principal para resolver el TSP
int tsp(const vector<vector<int>>& cost) {
    int n = cost.size();

    // Inicializar la tabla de memorización y reconstrucción
    memset(dp, -1, sizeof(dp));
    memset(parent, -1, sizeof(parent));

    // Iniciar desde la ciudad 0 y con la máscara inicial (solo 0 visitada)
    return totalCost(1, 0, n, cost);
}

int main() {
    int n; // Número de ciudades
    cin >> n;

    vector<vector<int>> cost(n, vector<int>(n));

    // Leer la matriz de costos
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> cost[i][j];
        }
    }

    int result = tsp(cost);

    //cout << "Costo minimo con regreso: " << result << " km" << endl;

    cout << "Ruta Optima: ";
    getRoute(1, 0, n); // Reconstruir e imprimir la ruta desde la ciudad 0
    cout << "A" << endl; // Regresar a la ciudad inicial

    return 0;
}