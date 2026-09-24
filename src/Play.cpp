#include "Play.h"
#include "raylib.h"
#include "GameManager.h"
#include "SceneManager.h"
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
		listen("OnVictory");

		ship = new Ship();
		GameManager::Get().Reset();
		ship->SetPosition(400, 300);
		bullets = new Bullet[MAX_AMMO];
		enemies = new Enemy[MAX_ENEMIES];
		pickups = new AmmoPickup[MAX_PICKUPS];
		for (int i = 0; i < MAX_PICKUPS; i++) {
			entityManager.Add(&pickups[i]); 
		}
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
		Music& playMusic = ResourceManager::get().GetMusic("play_theme.ogg");
		playMusic.looping = true;
		PlayMusicStream(playMusic);


	}

	void Play::OnExit()
	{
		entityManager.Clear();
		stopListening();
		Music& playMusic = ResourceManager::get().GetMusic("play_theme.ogg");
		StopMusicStream(playMusic);
	}

	void Play::Update() {
		if (isPaused) return;
		GameManager::Get().Update();
		spawnTimer += GetFrameTime();
		if (spawnTimer >= SPAWN_INTERVAL) {
			spawnTimer = 0.0f;
			//Spawn al azar de los enemigos
			for (int i = 0; i < MAX_ENEMIES; i++) {
				if (!enemies[i].active) {

					int side = GetRandomValue(0, 3);
					float spawnX = 0.0f;
					float spawnY = 0.0f;
					float offset = 40.0f;

					switch (side) {
					case 0:
						spawnX = (float)GetRandomValue(-offset, GetScreenWidth() + offset);
						spawnY = -offset;
						break;
					case 1: 
						spawnX = GetScreenWidth() + offset;
						spawnY = (float)GetRandomValue(-offset, GetScreenHeight() + offset);
						break;
					case 2: 
						spawnX = (float)GetRandomValue(-offset, GetScreenWidth() + offset);
						spawnY = GetScreenHeight() + offset;
						break;
						spawnX = -offset;
						spawnY = (float)GetRandomValue(-offset, GetScreenHeight() + offset);
						break;
					}

					enemies[i].position = { spawnX, spawnY };
					enemies[i].active = true;
					enemies[i].currentState = EnemyState::WALK;
					enemies[i].collider.radius = (enemies[i].walkAnim.GetFrameRec().width * 0.4f) / 2.0f;
					break;
				}
			}
		}

		if (GameManager::Get().score >= 100) {
			EventBus::getInstance().fire("OnVictory");
		}

		CheckCollisions();

		entityManager.Update();

		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			EventData data;
			data.type = "onClick";
			EventBus::getInstance().fire("onClick", data);
		}
		Music& playMusic = ResourceManager::get().GetMusic("play_theme.ogg");
		UpdateMusicStream(playMusic);
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
		if (data.type == "OnPlayerDeath") {
			GameManager::Get().CheckHighScore(); 
			SceneManager::Get().ChangeScene("lose"); 
		}
		if (data.type == "OnVictory") {
			GameManager::Get().CheckHighScore(); 
			SceneManager::Get().ChangeScene("win"); 
		}
		if (data.type == "resume_game") {
			isPaused = false;
		}
		if (data.type == "pause_game") {
			isPaused = true;
		}
		if (data.type == "menu_game") {
			isPaused = false;
		}
	}

	void Play::CheckCollisions()
	{
		//balas con enemigos
		for (int i = 0; i < MAX_AMMO; i++) {
			if (bullets[i].isActive()) {
				for (int enemy = 0; enemy < MAX_ENEMIES; enemy++) {
					if (enemies[enemy].isActive() && enemies[enemy].currentState != EnemyState::DIE && bullets[i].CollidesWith(enemies[enemy])) {
						bullets[i].active = false;
						enemies[enemy].TriggerDeath();
						GameManager::Get().score += 10;

						if (GetRandomValue(1, 100) <= 30) {
							for (int p = 0; p < MAX_PICKUPS; p++) {
								if (!pickups[p].active) {
									pickups[p].position = enemies[enemy].position;
									pickups[p].active = true;
									break;
								}
							}
						}
					}
				}
			}
		}
		for (int i = 0; i < MAX_ENEMIES; i++) {
			if (enemies[i].isActive() && enemies[i].currentState != EnemyState::DIE && enemies[i].CollidesWith(*ship)) {
				if (!ship->isInvulnerable) {
					enemies[i].TriggerAttack();
					GameManager::Get().lives--;
					ship->invulnerableTimer = 2.0f;
					if (GameManager::Get().lives <= 0) {
						EventBus::getInstance().fire("OnPlayerDeath");
					}
				}
			}
		}
		//Pickups  con jugador
		for (int i = 0; i < MAX_PICKUPS; i++) {
			if (pickups[i].active && pickups[i].CollidesWith(*ship)) {
				pickups[i].active = false;
				PlaySound(estebo::ResourceManager::get().GetSound("player_pickup.mp3"));
				GameManager::Get().currentAmmo += 5;
				if (GameManager::Get().currentAmmo > GameManager::Get().maxAmmo) {
					GameManager::Get().currentAmmo = GameManager::Get().maxAmmo;
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