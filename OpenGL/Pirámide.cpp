#include "Pirámide.h"

Pirámide::Pirámide(int baseLado, int h) : ladoBase(baseLado), altura(h)
{
    // Inicializamos los 4 triángulos
    for (int i = 0; i < 4; ++i) 
    {
        tri[i] = new Triangulo(ladoBase, altura); // Usar new para crear triángulos
    }
}

void Pirámide::init()
{
    // Inicialización de texturas u otras configuraciones necesarias
}

void Pirámide::Draw()
{
    glPushMatrix();

    // Triángulo base
    glPushMatrix();
    glTranslatef(0.0f, -altura / 3.0f, 0.0f);  // Mover la base para estar centrada
    tri[0]->Draw();
    glPopMatrix();

    // Cara lateral 1
    glPushMatrix();
    glTranslatef(0.0f, altura / 2.0f, ladoBase / 2.0f);  // Trasladar hacia adelante
    glRotatef(-60, 1.0f, 0.0f, 0.0f);                    // Rotar hacia el eje Z
    tri[1]->Draw();
    glPopMatrix();

    // Cara lateral 2
    glPushMatrix();
    glTranslatef(-ladoBase / 2.0f, altura / 2.0f, -ladoBase / 4.0f); // Trasladar a la izquierda y atrás
    glRotatef(120, 0.0f, 1.0f, 0.0f);                               // Rotar hacia Y
    tri[2]->Draw();
    glPopMatrix();

    // Cara lateral 3
    glPushMatrix();
    glTranslatef(ladoBase / 2.0f, altura / 2.0f, -ladoBase / 4.0f);  // Trasladar a la derecha y atrás
    glRotatef(-120, 0.0f, 1.0f, 0.0f);                              // Rotar hacia Y en sentido contrario
    tri[3]->Draw();
    glPopMatrix();

    glPopMatrix();  // Restaurar la matriz original
}

int Pirámide::calcularVolumen()
{
    return (ladoBase * ladoBase * altura) / 6;  // Fórmula para el volumen de un tetraedro
}
