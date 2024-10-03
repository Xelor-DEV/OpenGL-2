#include "Figura.h"

void Figura::EnableTexture()
{
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
	glEnable(GL_TEXTURE_GEN_T);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	glBindTexture(GL_TEXTURE_2D, IDTexture);
}

void Figura::DisableTexture()
{
	glDisable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
	glDisable(GL_TEXTURE_GEN_T);
	glDisable(GL_TEXTURE_2D);
	glutSwapBuffers();
}

void Figura::init()
{

}

void Figura::Render()
{
	EnableTexture();
	Draw();
	DisableTexture();
}

void Figura::SetTexture(GLuint idTexture)
{
	IDTexture = idTexture;
}
