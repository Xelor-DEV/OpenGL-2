#pragma once
#include "Figura2D.h"
class Cuadrado : public Figura2D
{
private:
    int lado;

public:

    Cuadrado() : lado(1) {} 
    Cuadrado(int l);

    void Draw() override;

    int calcularArea() override;

    int calcularPer�metro() override;

    void cambiarTama�o(int nuevoTama�o) override;
};

