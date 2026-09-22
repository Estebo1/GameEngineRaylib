#pragma once
#include "Scene.h"
#include "Ball.h"
#include <vector>
#include "EventBus.h"
#include "Player.h"
#include "Ship.h"
#include "EntityManager.h"
#include "Bullet.h"
#include "Enemy.h"

#define MAX_AMMO 30
#define MAX_ENEMIES 30
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

		float spawnTimer = 0.0f;
		float SPAWN_INTERVAL = 2.0f; 

	private:
		EntityManager entityManager;
		
		std::vector<Ball*> balls;
		Ship* ship;
		Bullet* bullets;
		Enemy* enemies;

		void GenerateBalls(int ballNumber);
		void CheckCollisions();
		void SpawnEnemy();

		int eventId_01;
		int eventId_02;
		//int playerScore;
		int grabCoinEvId;
	};
}

