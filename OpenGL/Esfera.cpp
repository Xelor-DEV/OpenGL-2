#include "Esfera.h"

Esfera::Esfera(int r) : radio(r) 
{

}

void Esfera::Draw()
{
    glPushMatrix();
    glutSolidSphere(radio, 20, 20);
    glPopMatrix();
}

int Esfera::calcularVolumen()
{
    return (4 / 3.0) * 3.14159 * radio * radio * radio;
}