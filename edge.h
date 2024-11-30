/*
 * Archivno: edge.h
 * Autor: Mónica Soberón Zubía
 * Descripción: Funciones para definir una arista en un grafo ponderado.
 * Fecha: 2024
 * Versión: 1.0
 * 
 * Este archivo define la una clase Edge que representa una arista en un grafo ponderado.
 * La clase tiene tres atributos: src, dest y weight, que representan el nodo de origen, 
 * el nodo de destino y el peso de la arista, respectivamente.
 * 
 * La clase Edge tiene un constructor que inicializa los atributos de la arista.
 * 
 * La complejidad de la clase es O(1).
 * 
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