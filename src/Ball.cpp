#include "Ball.h"

Ball::Ball(Vector2 pos, int radius, int speed, Color color) : pos(pos), radius(radius), color(color) {
	speedX = speed;
	speedY = speed;
}

void Ball::Draw()
{
	DrawCircleV(pos, (float)radius, color);
}

void Ball::Move()
{
	pos.x += (float)speedX;
	pos.y += (float)speedY;
}
void Ball::CheckCollision(int screenWidth, int screenHeight)
{
	if (pos.x - radius < 0) 
	{
		speedX = speedX *-1;
	}
	else if(pos.x + radius > screenWidth)
	{
		speedX = speedX * -1;
	}
	if (pos.y - radius < 0)
	{
		speedY = speedY *-1;
	}
	else if(pos.y + radius > screenHeight)
	{
		speedY = speedY * -1;
	}
}

Vector2 Ball::RandomPos()
{
	return Vector2{ (float)GetRandomValue(0, GetScreenWidth()), (float)GetRandomValue(0, GetScreenHeight()) };
}
int Ball::RandomRadius()
{
	return GetRandomValue(10, 50);
}
Color Ball::RandomColor()
{
	int color = GetRandomValue(0, 3);
	switch (color)
	{
	case 0:
		return RED;
	case 1:
		return GREEN;
	case 2:
		return BLUE;
	default:
		return YELLOW;
	}
}

