/*
 * Archivo: edge.h
 * Autor: Monica Soberon Zubia
 * Descripcion: Definicion de una clase para representar una arista en un grafo ponderado.
 * Fecha: 2024
 * Version: 1.1
 * 
 * Este archivo define la clase Edge, que representa una arista en un grafo ponderado.
 * 
 * Atributos:
 * - src: Nodo de origen de la arista.
 * - dest: Nodo de destino de la arista.
 * - weight: Peso de la arista.
 * 
 * Metodos:
 * - Constructor que inicializa los atributos de la clase.
 * 
 * Complejidad:
 * - Todas las operaciones de esta clase tienen una complejidad O(1).
 * 
 * Copyright (c) 2024, Monica Soberon Zubia
 * Todos los derechos reservados.
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
