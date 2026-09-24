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
		isPaused = false;
		listen("onClick");
		listen("OnPlayerDeath");
		listen("pause_game");
		listen("resume_game");
		listen("menu_game");
		ship = new Ship();
		ship->SetPosition(10, 20);
		bullets = new Bullet[MAX_AMMO];
		enemies = new Enemy[MAX_ENEMIES];
		for (int i = 0; i < MAX_ENEMIES; i++)
		{
			enemies[i].target = ship;
			entityManager.Add(&enemies[i]);
		}	

		for (int i = 0; i < MAX_AMMO; i++)
		{
			entityManager.Add(&bullets[i]);
		}

		ship->maxBullets = MAX_AMMO;
		ship->bullets = bullets;

		entityManager.Add(ship);

		play_gui.show();

	}

	void Play::OnExit()
	{
		entityManager.Clear();
		stopListening();
	}

	void Play::Update()
	{
		if (isPaused) return;

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
			EventBus::getInstance().fire("onClick", data);
		}
	}

	void Play::Draw()
	{
		play_gui.draw();
		entityManager.Draw();
	}

	void Play::onEvent(EventData data) {
		std::cout << "Play scene received event: " << data.type << std::endl;

		if (data.type == "onclick") {
			TraceLog(LOG_INFO, "Play scene received onclick event");
		}

		if (data.type == "resume_game") {
			isPaused = false;
		}
		if (data.type == "pause_game") {
			isPaused = true;
		}
		if (data.type == "menu_game") {
			isPaused = false;
			OnExit();
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