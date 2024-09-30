#pragma once
#include "Figura3D.h"
#include "Triangulo.h"

class Pir�mide : public Figura3D
{
private:
    Triangulo* tri[4];  // 4 tri�ngulos: 1 base y 3 laterales
    int ladoBase;        // Longitud de los lados de los tri�ngulos
    int altura;

public:
    Pir�mide(int baseLado, int h);

    void init() override;
    void Draw() override;
    int calcularVolumen() override;
};

