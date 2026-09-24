#pragma once
#include "Entity.h"
class Enemy : public Entity
{
public:
	float speed = 2.0f;
	int radius = 3;
	Entity* target = nullptr;
	Enemy() {
		active = false;
		collider.radius = 3;
		texture = estebo::ResourceManager::get().GetTexture("enemy.png");
		collider.radius = texture.width / 2.0f;
		collider.drawDebug = true;
	};


	void Update() override {
		if (!active) return;

		if (target != nullptr) {
			float dirX = target->position.x - position.x;
			float dirY = target->position.y - position.y;

			float magnitude = sqrt((dirX * dirX) + (dirY * dirY));

			if (magnitude > 0) {
				dirX /= magnitude;
				dirY /= magnitude;
			}

			position.x += dirX * speed;
			position.y += dirY * speed;
		}
	}

	void Draw() override {
		if (isActive() || texture.id != 0) {
			Vector2 pos = { position.x - texture.width / 2,position.y - texture.height / 2 };
			DrawTextureEx(texture, pos, 0.0f, 1.0f, WHITE);
		}
	}

};

