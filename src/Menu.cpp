#include "Menu.h"
namespace estebo {

	Menu::Menu() {
	}

	Menu::~Menu() {
	}

	void Menu::OnEnter() {
		menu_gui.show(); 
		listen("start_game");
		Music& menuMusic = ResourceManager::get().GetMusic("menu_theme.mp3");
		menuMusic.looping = true;
		PlayMusicStream(menuMusic);
	}

	void Menu::OnExit() {
		stopListening();
		Music& menuMusic = ResourceManager::get().GetMusic("menu_theme.mp3");
		StopMusicStream(menuMusic);
	}

	void Menu::Update() {
		Music& menuMusic = ResourceManager::get().GetMusic("menu_theme.mp3");
		UpdateMusicStream(menuMusic);
	}

	void Menu::Draw() {
		Texture2D& background = ResourceManager::get().GetTexture("background.png");
		DrawTexture(background, 0, 0, WHITE);
		menu_gui.draw(); 
		DrawFPS(10, 10); 
	}

	void Menu::onEvent(EventData e) {
		if (e.type == "start_game") {
			stopListening();
		}
	}
}
