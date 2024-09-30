#include "Example3.h"
Example3::Example3()
{
	camera = new Camera();
}

void Example3::init()
{

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClearDepth(1.0);
	camera->Init();
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_MODELVIEW);

}

void Example3::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	camera->Update();

    Draw3DAxisWithGrid(50, 1, 50);

    DrawCube(1.0f, -2.0f, 0.0f, 0.0f);
    DrawSphere(0.5f, 2.0f, 0.0f, 0.0f);
    DrawCone(0.5f, 1.0f, 0.0f, 2.0f, 0.0f);

	glFlush();
}

void Example3::KeyboardFunc(unsigned char key, int X, int Y)
{
    camera->KeyboardFunc(key, X, Y);
}

void Example3::Idle()
{

}

void Example3::DrawCube(float size, float x, float y, float z) {
    glPushMatrix();
    glTranslatef(x, y, z);
    glColor3f(1.0f, 0.0f, 0.0f);
    glutSolidCube(size);
    glPopMatrix();
}

void Example3::DrawSphere(float radius, float x, float y, float z) {
    glPushMatrix();
    glTranslatef(x, y, z);
    glColor3f(0.0f, 1.0f, 0.0f);
    glutSolidSphere(radius, 20, 20);
    glPopMatrix();
}

void Example3::DrawCone(float base, float height, float x, float y, float z) {
    glPushMatrix();
    glTranslatef(x, y, z);
    glColor3f(0.0f, 0.0f, 1.0f);
    glutSolidCone(base, height, 20, 20);
    glPopMatrix();
}
