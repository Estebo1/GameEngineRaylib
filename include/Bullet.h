#pragma once
#include "Entity.h"
class Bullet : public Entity
{
public:
	float speed = 20.0f;
	Color color;
	float radius = 2.0f;
	Bullet() = default;
	
	void Draw() override {
		DrawCircleLinesV(position, radius, WHITE);
	}
	void Update() override {
		if (!active)return;

		position.y -= speed;

		if (position.y <= 0) active = false;
	}
};

