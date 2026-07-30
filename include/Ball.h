#pragma once
#include "raylib.h"
class Ball {
public:

	Vector2 pos;
	int radius;
	int speedX;
	int speedY;
	Color color;

	Ball(Vector2 pos, int radius, int speed, Color color);
	void Draw();
	void Move();
	void CheckCollision(int screenWidth, int screenHeight);	
	static Vector2 RandomPos();
	static int RandomRadius();
	static Color RandomColor();
};
