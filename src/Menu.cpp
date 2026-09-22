#include "Menu.h"
namespace estebo {

	Menu::Menu() {
		listen("start_game");
	}

	Menu::~Menu() {
	}

	void Menu::OnEnter() {
		GenerateBalls(10);
		menu_gui.show(); // Show the menu GUI when the menu scene is initialized
	}

	void Menu::OnExit() {
		balls.clear();
		// Code to execute when exiting the menu scene
	}

	void Menu::Update() {
		for (Ball* ball : balls)
		{
			ball->CheckCollision(GetScreenWidth(), GetScreenHeight());
			ball->Update();
		}
		// Update logic for the menu scene
		if (IsKeyPressed(KEY_M)) {
			menu_gui.toggle();
			// Transition to the play scene
		}
	}

	void Menu::Draw() {
		// draw some text using the default font
		DrawText("Menu", 200, 200, 20, WHITE);
		menu_gui.draw(); // draw the main menu GUI
		DrawFPS(10, 10); // draw the FPS in the top left corner
	}

	void Menu::onEvent(EventData e) {
		if (e.type == "start_game") {
			// Transition to the play scene
		}
	}
	void Menu::GenerateBalls(int ballNumber)
	{
		for (int i = 0; i < ballNumber; i++) {
			balls.push_back(new Ball(Ball::RandomPos(), Ball::RandomRadius(), Ball::RandomRadius(), Ball::RandomColor()));
		}
	}
}
