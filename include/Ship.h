#pragma once
#include "Entity.h"
#include "Bullet.h"
#include "EventBus.h"
#include <math.h>

class Ship : public Entity, EventListener
{
public:
	float speed = 5.0f;
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

	void Update() override;


	void Draw() override;

	void fire();

	void onEvent(EventData data) override;

};

