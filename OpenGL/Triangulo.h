#pragma once
#include "Figura2D.h"
class Triangulo :
    public Figura2D
{
private:
    int base;
    int altura;

public:
    Triangulo(int b, int h);

    void Draw() override;
    int calcularArea() override;
    int calcularPerímetro() override;
    void cambiarTamaño(int nuevoTamaño) override;
};

