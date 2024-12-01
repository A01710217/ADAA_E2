
/*
 * Archivo: tsp.h
 * Autor: Carlos Anaya Ruiz
 * Descripción: Funciones para resolver el Problema del Viajante (TSP) utilizando programación dinámica.
 * Fecha: 2024
 * Versión: 1.1
 * 
 * Este archivo define las funciones:
 * - `tsp`: Calcula el costo mínimo de un recorrido que visita todas las ciudades exactamente una vez y regresa al inicio.
 * - `total_cost`: Implementa la lógica principal con memorización para evitar recalcular estados visitados.
 * - `get_route`: Reconstruye e imprime la ruta óptima.
 * 
 * Complejidad:
 * - `total_cost`: O(2^n * n^2), donde n es el número de ciudades.
 * - `get_route`: O(n), donde n es el número de ciudades.
 * - `tsp`: O(2^n * n^2), ya que depende de `total_cost`.
 * 
 * Dependencias:
 * - Utiliza las bibliotecas estándar de C++: `<iostream>`, `<climits>`, `<cstring>`, y `<vector>`.
 * 
 * Uso:
 * - Ideal para resolver problemas de optimización en grafos completos pequeños (hasta 20 nodos debido a la complejidad exponencial).
 */

#ifndef TSP_H
#define TSP_H

#include <iostream>
#include <climits>
#include <cstring>
#include <vector>

using namespace std;

// Variables globales para memorización y reconstrucción de la ruta
/**
 * @brief Máximo número de nodos.
 */
const int MAX = 20; // Máximo número de nodos
/**
 * @brief Tabla de memorización para el TSP.
 */
int dp[1 << MAX][MAX]; // Memorización para el TSP
/**
 * @brief Arreglo para reconstruir la ruta óptima.
 */
int parent[1 << MAX][MAX]; // Para reconstruir la ruta óptima

/**
 * @brief Calcula el costo total de un recorrido que visita todas las ciudades exactamente una vez y regresa al punto de inicio.
 * 
 * @param mask Máscara de visitas.
 * @param pos Ciudad actual.
 * @param n Número de ciudades.
 * @param cost Matriz de costos entre ciudades.
 * @return Costo total del recorrido.
 * 
 * Complejidad: O(2^n * n^2)
 */
int total_cost(int mask, int pos, int n, const vector<vector<int>>& cost) {
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
            int newAns = cost[pos][i] + total_cost(mask | (1 << i), i, n, cost);
            if (newAns < ans) {
                ans = newAns;
                parent[mask][pos] = i; // Guardar la ciudad `i` como próxima en la ruta óptima
            }
        }
    }

    return dp[mask][pos] = ans; // Guardar el resultado en dp
}

/**
 * @brief Reconstruye e imprime la ruta óptima del TSP.
 * 
 * @param mask Máscara de visitas.
 * @param pos Ciudad actual.
 * @param n Número de ciudades.
 * 
 * Complejidad: O(n)
 */
void get_route(int mask, int pos, int n) {
    cout << char('A' + pos) << " "; // Imprimir la ciudad actual
    if (mask == (1 << n) - 1) {
        return; // Caso base: todas las ciudades visitadas
    }

    int nextCity = parent[mask][pos];
    get_route(mask | (1 << nextCity), nextCity, n); // Moverse a la siguiente ciudad
}

/**
 * @brief Calcula el costo mínimo de un recorrido que visita todas las ciudades exactamente una vez y regresa al punto de inicio.
 * 
 * @param cost Matriz de costos entre ciudades.
 * @return Costo mínimo del recorrido.
 * 
 * Complejidad: O(2^n * n^2)
 */
int tsp(const vector<vector<int>>& cost) {
    int n = cost.size();

    // Inicializar la tabla de memorización y reconstrucción
    memset(dp, -1, sizeof(dp));
    memset(parent, -1, sizeof(parent));

    // Iniciar desde la ciudad 0 y con la máscara inicial (solo 0 visitada)
    return total_cost(1, 0, n, cost);
}

#endif
