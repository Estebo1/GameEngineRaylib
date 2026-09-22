#pragma once
#include "Entity.h"
class Bullet : public Entity
{
public:
	float speed = 10.0f;
	int radius = 3;
	Bullet() {
		active = false;
		texture = estebo::ResourceManager::get().GetTexture("bullet.png");
		collider.radius = (texture.width / 2.0f) * 2;
		collider.drawDebug = true;
	};


	void Update() override {
		if (!active) return;

		position.y -= speed;

		if (position.y <= 0.0f) {
			active = false;
		}
	}

	void Draw() override {
		DrawCircleV(position, radius, WHITE);
	}
};

