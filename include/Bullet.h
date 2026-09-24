#pragma once
#include "Entity.h"
class Bullet : public Entity
{
public:
	float speed = 10.0f;
	int radius = 3;
	Vector2 velocity = { 0.0f, 0.0f }; 

	Bullet() {
		active = false;
		texture = estebo::ResourceManager::get().GetTexture("bullet.png");
		collider.radius = (texture.width / 2.0f) * 2;
		collider.drawDebug = true;
	};

	void Update() override {
		if (!active) return;

		position.x += velocity.x;
		position.y += velocity.y;

		if (position.y <= 0.0f || position.y >= 600.0f || position.x <= 0.0f || position.x >= 800.0f) {
			active = false;
		}
	}

	void Draw() override {
		if (active) {
			DrawCircleV(position, radius, WHITE);
		}
	}
};