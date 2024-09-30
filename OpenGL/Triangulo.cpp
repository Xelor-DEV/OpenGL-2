#include "Triangulo.h"

Triangulo::Triangulo(int b, int h) : base(b), altura(h) 
{

}

void Triangulo::Draw()
{
    glBegin(GL_TRIANGLES);
    glVertex3f(0, altura, 0);
    glVertex3f(-base / 2, 0, 0);
    glVertex3f(base / 2, 0, 0);
    glEnd();
}

int Triangulo::calcularArea()
{
    return (base * altura) / 2;
}

int Triangulo::calcularPer�metro()
{
    // Considerando un tri�ngulo equil�tero
    return 3 * base;
}

void Triangulo::cambiarTama�o(int nuevoTama�o)
{
    base = nuevoTama�o;
    altura = nuevoTama�o; // Ajuste proporcional para mantener la forma
}