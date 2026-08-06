#include "Menu.h"
namespace estebo {
	Menu::Menu()
	{

	}

	Menu::~Menu()
	{}

	void Menu::OnEnter()
	{
		GenerateBalls(10);
	}

	void Menu::OnExit()
	{
		balls.clear();
	}

	void Menu::Update()
	{
		for (Ball* ball : balls)
		{
			ball->CheckCollision(GetScreenWidth(), GetScreenHeight());
			ball->Move();
		}
	}

	void Menu::Draw()
	{
		ClearBackground(RAYWHITE);
		menuGUI.Draw();
		playGUI.Draw();
	}
	void Menu::GenerateBalls(int ballNumber)
	{
		for (int i = 0; i < ballNumber; i++) {
			balls.push_back(new Ball(Ball::RandomPos(), Ball::RandomRadius(), Ball::RandomRadius(), Ball::RandomColor()));
		}
	}
}