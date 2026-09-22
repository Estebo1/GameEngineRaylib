#pragma once
#include "Entity.h"
#include "Bullet.h"

class Ship : public Entity
{
public:
	float speed = 20.0f;
	Bullet* bullets = nullptr;
	int maxBullets = 10;

	Ship() {
		name = "Ship";
		active = true;
		position = { 400.0f, 300.0f }; 
		texture = estebo::ResourceManager::get().GetTexture("ship.png");
		collider.radius = texture.width / 2.0f; 
		collider.drawDebug = true;
	}

	~Ship() {}

	void Update() override {
		if (IsKeyDown(KEY_RIGHT)) {
			position.x += speed;
		}
		if (IsKeyDown(KEY_LEFT)) {
			position.x -= speed;
		}
		if (IsKeyDown(KEY_UP)) {
			position.y -= speed;
		}
		if (IsKeyDown(KEY_DOWN)) {
			position.y += speed;
		}
		if (IsKeyPressed(KEY_SPACE)) {
			fire();
		}
	}


	void Draw() override {
		if (isActive() || texture.id != 0) {
			Vector2 pos = { position.x - texture.width / 2,position.y - texture.height / 2 };
			DrawTextureEx(texture, pos, 0.0f, 1.0f, WHITE);
		}
	}

	void fire() {
		for (int i = 0; i < maxBullets; i++) {
			if (!bullets[i].active) {
				bullets[i].position.x = position.x;
				bullets[i].position.y = position.y;
				bullets[i].active = true;
				break;
			}
		}
	}
};

