#pragma once
#include "Figura3D.h"
#include "Triangulo.h"

class Pirámide : public Figura3D
{
private:
    Triangulo* tri[4];  // 4 triángulos: 1 base y 3 laterales
    int ladoBase;        // Longitud de los lados de los triángulos
    int altura;

public:
    Pirámide(int baseLado, int h);

    void init() override;
    void Draw() override;
    int calcularVolumen() override;
};

