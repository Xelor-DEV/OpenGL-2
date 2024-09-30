#pragma once
#include "Figura3D.h"
#include "Cuadrado.h"

class Cubo : public Figura3D
{
private:
    Cuadrado cuad[6];
    int lado;

public:
    Cubo(int l);
    void Draw() override;
    int calcularVolumen() override;
};

