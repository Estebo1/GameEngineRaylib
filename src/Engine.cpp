#include "Engine.h"

void Engine::Initialize()
{
	GenerateBalls(10);
}

void Engine::Run()
{
	for (Ball* ball : balls)
	{
		ball->CheckCollision(GetScreenWidth(), GetScreenHeight());
		ball->Move();
	}
	for (Ball* ball : balls)
	{
		ball->Draw();
	}
}

void Engine::Shutdown()
{
	balls.clear();
}

void Engine::GenerateBalls(int ballNumber)
{
	for (int i = 0; i < ballNumber; i++) {
		balls.push_back(new Ball(Ball::RandomPos(), Ball::RandomRadius(), Ball::RandomRadius(), Ball::RandomColor()));
	}
}
