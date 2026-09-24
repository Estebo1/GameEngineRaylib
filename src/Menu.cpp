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
		menu_gui.draw(); 
		DrawFPS(10, 10); 
	}

	void Menu::onEvent(EventData e) {
		if (e.type == "start_game") {
			stopListening();
		}
	}
}
