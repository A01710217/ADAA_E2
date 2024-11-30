
/*
 * File: edge.h
 * Project: Integradora_2
 * Author: Monica Soberon Zubia
 * Description: Defines a class to represent an edge in a weighted graph.
 * Version: 1.1
 * Date: 2024
 *
 * Copyright (c) 2024 Monica Soberon Zubia
 * All rights reserved.
 *
 * Redistribution, modification, or use of this file is allowed only
 * under explicit written permission from the author. Unauthorized
 * use is strictly prohibited.
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
