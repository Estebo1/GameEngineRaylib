#pragma once
#include "raylib.h"
#include <string>
#include "CircleCollider.h"
#include "ResourceManager.h"

class Entity
{
public: 
	std::string name = "";
	Vector2 position = { 0.0f, 0.0f};
	bool showCollider = false;
	bool active = true;
	Texture2D texture;
	estebo::CircleCollider collider;

	Entity() = default;
	virtual ~Entity() = default;

	virtual void Update() {};
	virtual void Draw() {
		if (texture.id == 0) {
			TraceLog(LOG_WARNING, "Entity texture is null. Cannot draw.");
			return;
		}
		DrawTextureEx(texture, position, 0.f, 1.f, WHITE);
	};

	void DrawDebug() {
		if (active && collider.drawDebug) {
			collider.DebugDraw();
		}
	}
	void SetPosition(float x, float y) { position.x = x, position.y = y; }
	void SetPosition(Vector2 pos) { position = pos; }
	bool isActive() const { return active; }
	bool CollidesWith(Entity& other) {
		return collider.CheckCollision(other.collider);
	}
	
};

