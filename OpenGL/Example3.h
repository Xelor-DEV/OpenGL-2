#pragma once
#include "Example.h"
#include "Camera.h"
#include "IncludeGL.h"
class Example3 : public Example
{
	Camera* camera;
public:
	Example3();

	virtual void init()override;
	virtual void Render()override;
	virtual void KeyboardFunc(unsigned char key, int X, int Y)override;
	virtual void Idle()override;
	void DrawCube(float size, float x, float y, float z);
	void DrawSphere(float radius, float x, float y, float z);
	void DrawCone(float base, float height, float x, float y, float z);
};

