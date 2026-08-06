#pragma once
#include "Scene.h"
#include "Ball.h"
#include <vector>
#include "raygui.h"
#include "estebo_gui.h"

namespace estebo {
	class Menu : public Scene
	{
	public:
		MenuGUI menuGUI;
		PlayGUI playGUI;
		Menu();
		~Menu();
		void OnEnter() override;
		void OnExit() override;
		void Update() override;
		void Draw() override;
	private:
		std::vector<Ball*> balls;
		void GenerateBalls(int ballNumber);
	};
}
