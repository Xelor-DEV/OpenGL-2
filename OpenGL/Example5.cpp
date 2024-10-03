#include "Example5.h"
#include <stdio.h>
#include "BMPTextureLoader.h"

Example5::Example5()
{
    _TextureLoader = new BMPTextureLoader();
    texture = ((BMPTextureLoader*)_TextureLoader)->LoadBMP("./Textures/wallBMP.bmp");

    // Inicializa las variables de posición, rotación y escala
    pos = { 0.0f, 0.0f, 0.0f };
    rotation = { 0.0f, 0.0f, 0.0f };
    scale = { 1.0f, 1.0f, 1.0f };

    // Crear instancias de las figuras
    cubo = new Cubo(4);
    pirámide = new Pirámide(2, 2);
    esfera = new Esfera(1);
    cuadrado = new Cuadrado(1);
    triangulo = new Triangulo(2, 2);
    circulo = new Circulo(1); // Crear el objeto circulo
}
void Example5::init()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0);
    glEnable(GL_DEPTH_TEST);
    gluLookAt(5, 5, 5, 0, 0, 0, 0, 1, 0);
    glMatrixMode(GL_MODELVIEW);

}
void Example5::Render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    Example::Draw3DAxis(50);
    DrawShape();
    glFlush();
}
void Example5::KeyboardFunc(unsigned char key, int X, int Y)
{

}
void Example5::Idle()
{

}
void Example5::DrawShape()
{
    //cubo->SetTexture(texture);
    //pirámide->SetTexture(texture);
    //esfera->SetTexture(texture);
    //cuadrado->SetTexture(texture);
    //triangulo->SetTexture(texture);
    circulo->SetTexture(texture);

    //cubo->Render();
    //pirámide->Render();
    //esfera->Render();
    //cuadrado->Render();
    //triangulo->Render();
    circulo->Render();
    
}

void Example5::DrawTriangle(float x, float y, float z)
{
    glBegin(GL_TRIANGLES);
    glTranslatef(x, y, z);
    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, 0.0f); 
    glVertex3f(1.0f, -1.0f, 0.0f); 
    glEnd(); 
}

void Example5::DrawQuad(float x, float y, float z)
{
    glBegin(GL_QUADS); 
    glTranslatef(x, y, z);
    glVertex3f(-1.0f, 1.0f, 0.0f); 
    glVertex3f(1.0f, 1.0f, 0.0f); 
    glVertex3f(1.0f, -1.0f, 0.0f);  
    glVertex3f(-1.0f, -1.0f, 0.0f);
    glEnd();
}

void Example5::DrawCube(float size, float x, float y, float z)
{
    glPushMatrix();
    glTranslatef(x, y, z);
    glutSolidCube(size);
    glPopMatrix();
}

void Example5::DrawSphere(float radius, float x, float y, float z)
{
    glPushMatrix();
    glTranslatef(x, y, z);
    glutSolidSphere(radius, 20, 20);
    glPopMatrix();
}
