#include "Play.h"

estebo::Play::Play()
{}

estebo::Play::~Play()
{}

void estebo::Play::OnEnter()
{
	GenerateBalls(1);
}

void estebo::Play::OnExit()
{
	balls.clear();
}

void estebo::Play::Update()
{
	for (Ball* ball : balls)
	{
		ball->CheckCollision(GetScreenWidth(), GetScreenHeight());
		ball->Move();
	}
}

void estebo::Play::Draw()
{
	ClearBackground(BLACK);

	for (Ball* ball : balls)
	{
		ball->Draw();
	}
}

void estebo::Play::GenerateBalls(int ballNumber)
{
	for (int i = 0; i < ballNumber; i++) {
		balls.push_back(new Ball(Ball::RandomPos(), Ball::RandomRadius(), Ball::RandomRadius(), Ball::RandomColor()));
	}
}
