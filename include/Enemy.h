#pragma once
#include "Entity.h"
class Enemy : public Entity
{
public:
	float speed = 4.0f;
	int radius = 3;
	Enemy() {
		active = false;
		collider.radius = 3;
		texture = estebo::ResourceManager::get().GetTexture("enemy.png");
		collider.radius = texture.width / 2.0f;
		collider.drawDebug = true;
	};


	void Update() override {
		if (!active) return;

		position.y += speed;

		if (position.y >= GetScreenHeight()) {
			active = false;
		}
	}

	void Draw() override {
		if (isActive() || texture.id != 0) {
			Vector2 pos = { position.x - texture.width / 2,position.y - texture.height / 2 };
			DrawTextureEx(texture, pos, 0.0f, 1.0f, WHITE);
		}
	}

};

