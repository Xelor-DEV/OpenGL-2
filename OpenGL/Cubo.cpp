#include "Cubo.h"

Cubo::Cubo(float l) : lado(l)
{
    for (int i = 0; i < 6; ++i)
    {
        cuad[i] = new Cuadrado(lado);
    }
}

void Cubo::Draw()
{
    glPushMatrix();
    glutSolidCube(lado);
    glPopMatrix();
}

float Cubo::calcularVolumen()
{
    return lado * lado * lado;
}