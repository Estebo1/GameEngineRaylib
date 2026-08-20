#pragma once
#include "raylib.h"
#include <string>
class Entity
{
public: 
	std::string name = "";
	Vector2 position = { 0.0f, 0.0f};
	bool active = true;
	Texture2D texture;

	Entity() = default;
	virtual ~Entity() = default;

	virtual void Update() {};
	virtual void Draw() {};

	void SetPosition(float x, float y) { position.x = x, position.y = y; }
	void SetPosition(Vector2 pos) { position = pos; }
	bool isActive() const { return active; }
};

