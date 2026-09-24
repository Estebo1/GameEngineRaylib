#pragma once
#include "Entity.h"

class AmmoPickup : public Entity {
public:
    AmmoPickup() {
        active = false;
        collider.radius = 8.0f;
        collider.drawDebug = true;
        texture = estebo::ResourceManager::get().GetTexture("enemy.png");

    }

    void Update() override {
        if (!active) return;
        position.y += 0.2f;
        if (position.y > GetScreenHeight()) {
            active = false;
        }
    }

    void Draw() override {
        if (active) {
            DrawCircleV(position, collider.radius, GREEN);
        }
    }
};