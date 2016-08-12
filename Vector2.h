#pragma once
class Vector2
{
public:
	float x, y;
	void add(float a_X, float a_Y);
	void mult(float a_X, float a_Y);
	void div(float a_X, float a_Y);
	void sub(float a_X, float a_Y);
	Vector2();
	~Vector2();
};

