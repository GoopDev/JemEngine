#include "Vector2.h"

void Vector2::add(float a_X, float a_Y)
{
	x += a_X;
	y += a_Y;
}

void Vector2::div(float a_X, float a_Y)
{
	x /= a_X;
	y /= a_Y;
}

void Vector2::sub(float a_X, float a_Y)
{
	x -= a_X;
	y -= a_Y;
}

void Vector2::mult(float a_X, float a_Y)
{
	x *= a_X;
	y *= a_Y;
}

Vector2::Vector2()
{
}


Vector2::~Vector2()
{
}
