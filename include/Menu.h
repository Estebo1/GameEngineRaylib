#pragma once
#include "Scene.h"
#include "Ball.h"
#include <vector>

namespace estebo {
	class Menu : public Scene
	{
	public:
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
