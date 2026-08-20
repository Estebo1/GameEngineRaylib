#pragma once
#include "Scene.h"
#include "Ball.h"
#include <vector>
#include "EventBus.h"
#include "Player.h"

namespace estebo {
	class Play : public Scene, EventListener
	{
	public:
		Play();
		~Play();
		void OnEnter() override;
		void OnExit() override;
		void Update() override;
		void Draw() override;
		void onEvent(EventData data) override;

		int playEventId;
		int grabCoin;
		int playerScore;

	private:
		std::vector<Ball*> balls;
		void GenerateBalls(int ballNumber);
		Player* player;
	};
}

