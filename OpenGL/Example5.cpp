#include "Example5.h"
#include <stdio.h>
#include "BMPTextureLoader.h"



Example5::Example5()
{
    

    // Inicializa las variables de posición, rotación y escala
    pos = { 0.0f, 0.0f, 0.0f };
    rotation = { 0.0f, 0.0f, 0.0f };
    scale = { 1.0f, 1.0f, 1.0f };

    // Crear instancias de las figuras
    cubo = new Cubo(1);
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
    _TextureLoader = new BMPTextureLoader();
    texture = ((BMPTextureLoader*)_TextureLoader)->LoadBMP("./Textures/wallBMP.bmp");
}
void Example5::Render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    Example::Draw3DAxis(50);

    // Aplica las transformaciones globales
    glPushMatrix();
    glTranslatef(pos.x, pos.y, pos.z);
    glRotatef(rotation.x, 1.0f, 0.0f, 0.0f);
    glRotatef(rotation.y, 0.0f, 1.0f, 0.0f);
    glRotatef(rotation.z, 0.0f, 0.0f, 1.0f);
    glScalef(scale.x, scale.y, scale.z);

    DrawShape(); // Dibuja las figuras
    glPopMatrix(); // Restaura la matriz original

    glutSwapBuffers(); // Se hace el cambio de buffer
}
void Example5::KeyboardFunc(unsigned char key, int X, int Y)
{
    switch (key)
    {
    case 'A':
        pos.x = pos.x + 1;
        break;
    case 'D':
        pos.x = pos.x - 1;
        break;
    case 'W':
        pos.z = pos.z + 1;
        break;
    case 'S':
        pos.z = pos.z - 1;
        break;
    case 'Q':
        pos.y = pos.z + 1;
        break;
    case 'E':
        pos.y = pos.z - 1;
        break;
    case 'R':
        rotation.x = rotation.x + 1; // Rotación en X
        break;
    case 'T':
        rotation.x = rotation.x - 1; // Rotación en X
        break;
    case 'F':
        rotation.y = rotation.y + 1; // Rotación en Y
        break;
    case 'G':
        rotation.y = rotation.y - 1; // Rotación en Y
        break;
    case 'V':
        rotation.z = rotation.z + 1; // Rotación en Z
        break;
    case 'B':
        rotation.z = rotation.z - 1; // Rotación en Z
        break;
    case 'Z':
        scale.x = scale.x + 0.1f; // Escalar en X
        scale.y = scale.y + 0.1f; // Escalar en Y
        scale.z = scale.z + 0.1f; // Escalar en Z
        break;
    case 'X':
        scale.x = scale.x - 0.1f; // Escalar en X
        scale.y = scale.y - 0.1f; // Escalar en Y
        scale.z = scale.z - 0.1f; // Escalar en Z
        break;
    default:
        break;
    }
}
void Example5::Idle()
{
}
void Example5::DrawShape()
{
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
    glEnable(GL_TEXTURE_GEN_T);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glBindTexture(GL_TEXTURE_2D, texture);

    // Dibuja las figuras
    cubo->Draw();
    pirámide->Draw();
    esfera->Draw();
    cuadrado->Draw();
    triangulo->Draw();
    circulo->Draw(); 


    glDisable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
    glDisable(GL_TEXTURE_GEN_T);
    glDisable(GL_TEXTURE_2D);
    glutSwapBuffers(); //Se hace el cambio de buffer
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
