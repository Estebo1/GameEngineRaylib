#pragma once
#include "Scene.h"
#include "Ball.h"
#include <vector>

namespace estebo {
	class Play : public Scene
	{
	public:
		Play();
		~Play();
		void OnEnter() override;
		void OnExit() override;
		void Update() override;
		void Draw() override;
	private:
		std::vector<Ball*> balls;
		void GenerateBalls(int ballNumber);
	};
}

