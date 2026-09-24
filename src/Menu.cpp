#include "Menu.h"
namespace estebo {

	Menu::Menu() {
	}

	Menu::~Menu() {
	}

	void Menu::OnEnter() {
		menu_gui.show(); 
		listen("start_game");
	}

	void Menu::OnExit() {
		stopListening();
	}

	void Menu::Update() {

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
