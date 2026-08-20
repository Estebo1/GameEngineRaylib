#pragma once
#include "Entity.h"
class Ship : public Entity
{
public:
	float speed = 20.0f;

	Ship() {
		name = "Ship";
		active = true;
		position = { 400.0f, 300.0f };
		texture = LoadTexture("Ship.png");
	}
	~Ship() {
		UnloadTexture(texture);
	}
	void Update() override {
		if (IsKeyDown(KEY_RIGHT)) {
			position.x += speed;
		}
		if (IsKeyDown(KEY_LEFT)) {
			position.x -= speed;
		}
	}
	void Draw() override {
		if (isActive() || texture.id != 0) {
			DrawTextureEx(texture, position, 0.0f, 1.0f, WHITE);
		}
	}
};

