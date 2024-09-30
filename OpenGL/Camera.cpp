#include "Camera.h"

Camera::Camera()
{
}

void Camera::SetPosition(Vector3 _position)
{
	position = _position;
}

Vector3 Camera::GetPosition()
{
	return Vector3();
}

void Camera::SetDirection(Vector3)
{
}

Vector3 Camera::GetDirection()
{
	return Vector3();
}

void Camera::Init()
{
    position = Vector3(0.0f, 0.0f, 5.0f);
    direction = Vector3(0.0f, 0.0f, -1.0f);
}

void Camera::Update()
{
	gluLookAt(position.x, position.y, position.z, direction.x, direction.y, direction.z, 0, 1, 0);
}

void Camera::LookAt(Vector3)
{
}

void Camera::KeyboardFunc(unsigned char key, int X, int Y)
{
    switch (key)
    {
    case 'w': // Mover hacia adelante
        position = position + Vector3(1, 0, 0);
        break;
    case 's': // Mover hacia atrás
        position = position + Vector3(-1, 0, 0);
        break;
    case 'a': // Girar a la izquierda
    {
        direction = direction + Vector3(0, 0, 1);
    }
    break;
    case 'd': // Girar a la derecha
    {
        direction = direction + Vector3(0, 0, -1);
    }
    }
}