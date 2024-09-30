#include "Figura.h"

void Figura::EnableTexture()
{
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_GEN_S);
	glEnable(GL_TEXTURE_GEN_T);
}

void Figura::DisableTexture()
{
	glDisable(GL_TEXTURE_GEN_S);
	glDisable(GL_TEXTURE_GEN_T);
	glDisable(GL_TEXTURE_2D);
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
