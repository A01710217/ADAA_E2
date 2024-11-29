#ifndef PUNTO_H
#define PUNTO_H

#include <cmath>

class Punto {
private:
    int x;
    int y;

public:
    Punto(int x = 0, int y = 0); // Constructor con valores predeterminados
    int getX() const;
    int getY() const;
    void setX(int x);
    void setY(int y);
    double distancia(const Punto& p) const;
};

Punto::Punto(int x, int y) : x(x), y(y) {}

int Punto::getX() const {
    return x;
}

int Punto::getY() const {
    return y;
}

void Punto::setX(int x) {
    this->x = x;
}

void Punto::setY(int y) {
    this->y = y;
}

double Punto::distancia(const Punto& p) const {
    return sqrt(pow(x - p.getX(), 2) + pow(y - p.getY(), 2));
}

#endif