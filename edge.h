/*
 * Archivo: edge.h
 * Autor: Mónica Soberón Zubía
 * Descripción: Definición de una clase para representar una arista en un grafo ponderado.
 * Fecha: 2024
 * Versión: 1.1
 * 
 * Este archivo define la clase `Edge`, que representa una arista en un grafo ponderado.
 * 
 * Atributos:
 * - `src`: Nodo de origen de la arista.
 * - `dest`: Nodo de destino de la arista.
 * - `weight`: Peso de la arista.
 * 
 * Métodos:
 * - Constructor que inicializa los atributos de la clase.
 * 
 * Complejidad:
 * - Todas las operaciones de esta clase tienen una complejidad O(1).
 */

#ifndef EDGE_H
#define EDGE_H

/**
 * @brief Clase que representa una arista en un grafo ponderado.
 */
class Edge {
public:
    /**
     * @brief Nodo de origen de la arista.
     */
    int src;

    /**
     * @brief Nodo de destino de la arista.
     */
    int dest;

    /**
     * @brief Peso de la arista.
     */
    int weight;

    /**
     * @brief Constructor de la clase Edge.
     * 
     * @param src Nodo de origen de la arista.
     * @param dest Nodo de destino de la arista.
     * @param weight Peso de la arista.
     */
    Edge(int, int, int);
};

Edge::Edge(int src, int dest, int weight) : src(src), dest(dest), weight(weight) {}

#endif
