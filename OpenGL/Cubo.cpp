#include "Cubo.h"

Cubo::Cubo(int l) : lado(l)
{
    for (int i = 0; i < 6; ++i)
    {
        cuad[i] = Cuadrado(lado);
    }
}

void Cubo::Draw()
{
    glPushMatrix();

    // Cara frontal
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, lado / 2.0f);  // Mover al frente
    cuad[0].Draw();
    glPopMatrix();

    // Cara trasera
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, -lado / 2.0f); // Mover atrás
    glRotatef(180, 0.0f, 1.0f, 0.0f);       // Rotar 180 grados en Y
    cuad[1].Draw();
    glPopMatrix();

    // Cara superior
    glPushMatrix();
    glTranslatef(0.0f, lado / 2.0f, 0.0f);  // Mover arriba
    glRotatef(-90, 1.0f, 0.0f, 0.0f);      // Rotar -90 grados en X
    cuad[2].Draw();
    glPopMatrix();

    // Cara inferior
    glPushMatrix();
    glTranslatef(0.0f, -lado / 2.0f, 0.0f); // Mover abajo
    glRotatef(90, 1.0f, 0.0f, 0.0f);       // Rotar 90 grados en X
    cuad[3].Draw();
    glPopMatrix();

    // Cara izquierda
    glPushMatrix();
    glTranslatef(-lado / 2.0f, 0.0f, 0.0f); // Mover a la izquierda
    glRotatef(90, 0.0f, 1.0f, 0.0f);       // Rotar 90 grados en Y
    cuad[4].Draw();
    glPopMatrix();

    // Cara derecha
    glPushMatrix();
    glTranslatef(lado / 2.0f, 0.0f, 0.0f); // Mover a la derecha
    glRotatef(-90, 0.0f, 1.0f, 0.0f);      // Rotar -90 grados en Y
    cuad[5].Draw();
    glPopMatrix();

    glPopMatrix();  // Restaurar la matriz original
}

int Cubo::calcularVolumen()
{
    return lado * lado * lado;
}