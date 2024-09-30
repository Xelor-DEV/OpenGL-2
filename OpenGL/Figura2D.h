#pragma once
#include "Figura.h"

class Figura2D : public Figura
{
public:
    virtual int calcularArea() = 0;
    virtual int calcularPerímetro() = 0;
    virtual void cambiarTamaño(int nuevoTamaño) = 0;
};
