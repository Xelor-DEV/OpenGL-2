#pragma once
#include "Figura.h"

class Figura2D : public Figura
{
public:
    virtual int calcularArea() = 0;
    virtual int calcularPer�metro() = 0;
    virtual void cambiarTama�o(int nuevoTama�o) = 0;
};
