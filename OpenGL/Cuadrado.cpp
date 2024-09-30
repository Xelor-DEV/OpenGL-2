#include "Cuadrado.h"

Cuadrado::Cuadrado(int l) : lado(l)
{

}

void Cuadrado::Draw()
{
    glBegin(GL_QUADS);
    glVertex3f(-lado / 2, -lado / 2, 0);
    glVertex3f(lado / 2, -lado / 2, 0);
    glVertex3f(lado / 2, lado / 2, 0);
    glVertex3f(-lado / 2, lado / 2, 0);
    glEnd();
}

int Cuadrado::calcularArea()
{
    return lado * lado;
}

int Cuadrado::calcularPerímetro()
{
    return 4 * lado;
}

void Cuadrado::cambiarTamaño(int nuevoTamaño)
{
    lado = nuevoTamaño;
}