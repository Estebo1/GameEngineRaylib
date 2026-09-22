#include "Play.h"
#include "raylib.h"
#include <iostream>
namespace estebo {
	Play::Play()
	{}

	Play::~Play()
	{}

	void Play::OnEnter()
	{
		listen("onClick");
		ship = new Ship();
		ship->SetPosition(10, 20);
		bullets = new Bullet[MAX_AMMO];
		enemies = new Enemy[MAX_ENEMIES];
		GenerateBalls(1);
	

		for (int i = 0; i < MAX_AMMO; i++)
		{
			entityManager.Add(&bullets[i]);
		}
		for (int i = 0; i < MAX_ENEMIES; i++)
		{
			entityManager.Add(&enemies[i]);
		}

		ship->maxBullets = MAX_AMMO;
		ship->bullets = bullets;

		entityManager.Add(ship);
	}

	void Play::OnExit()
	{
		balls.clear();
		entityManager.Clear();
	}

	void Play::Update()
	{

		for (Ball* ball : balls)
		{
			ball->Update();
		}

		spawnTimer += GetFrameTime();
		if (spawnTimer >= SPAWN_INTERVAL) {
			spawnTimer = 0.0f;

			for (int i = 0; i < MAX_ENEMIES; i++) {
				if (!enemies[i].active) {
					enemies[i].position = { (float)GetRandomValue(0, 800), 5 }; 
					enemies[i].active = true;
					break;
				}
			}
		}
		CheckCollisions();

		entityManager.Update();

		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			EventData data;
			data.type = "onClick";
			EventBus::get().fire("onClick", data);
		}
	}

	void Play::Draw()
	{
		for (Ball* ball : balls)
		{
			ball->Draw();
		}
		entityManager.Draw();
		DrawText("Play", 200, 200, 20, WHITE);
	}

	void Play::onEvent(EventData data) {
		std::cout << "Play scene received event: " << data.type << std::endl;

		if (data.type == "onclick") {
			TraceLog(LOG_INFO, "Play scene received onclick event");
		}
	}

	void Play::GenerateBalls(int ballNumber)
	{
		for (int i = 0; i < ballNumber; i++) {
			balls.push_back(new Ball(Ball::RandomPos(), Ball::RandomRadius(), Ball::RandomRadius(), Ball::RandomColor()));
		}
	}
	void Play::CheckCollisions()
	{
		for (int i = 0; i < MAX_AMMO; i++)
		{
			if (bullets[i].isActive()) {
				for (int enemy = 0; enemy < MAX_ENEMIES; enemy++)
				{
					if (enemies[enemy].isActive()) {
						if (bullets[i].CollidesWith(enemies[enemy])) {
							bullets[i].active = false;
							enemies[enemy].active = false;

						}
					}
				}
			}
		}

		for (int i = 0; i < MAX_ENEMIES; i++)
		{
			if (enemies[i].isActive()) {
				if (enemies[i].CollidesWith(*ship)) {

				}
			}
		}
	}
	void Play::SpawnEnemy()
	{
		for (int i = 0; i < MAX_ENEMIES; i++)
		{
			if(!enemies[i].active)
			{
				enemies[i].position.x = (float)GetRandomValue(0, GetScreenWidth() - enemies[i].texture.width);
				enemies[i].position.y = 0.0f;
				enemies[i].active = true;
				break;
			}
		}
	}
}