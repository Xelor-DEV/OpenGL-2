#pragma once
#include "IncludeGL.h"

class Figura
{
protected:
	GLuint IDTexture;
	char nombre[20];
	int GrosorBorde;
	int Color;
	void EnableTexture();
	void DisableTexture();
public:
	virtual void init();
	virtual void Render();
	virtual void Draw()=0;
};