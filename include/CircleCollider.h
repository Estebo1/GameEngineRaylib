#pragma once
#include "raylib.h"
#include "raymath.h"

namespace estebo {
    class CircleCollider
    {
    public:
		Vector2 center = { 0.0f, 0.0f };
		float radius = 0.0f;
        bool drawDebug = false;
		CircleCollider(float radius = 10.0f) : radius(radius) {}
        bool isActive = true;
        void Update(Vector2 pos) {
            center = pos;
        }
        
        bool CheckCollision(CircleCollider& other) {
            return Vector2Distance(center, other.center) <= (radius + other.radius);
        }

		void DebugDraw(Color color = RED) {
			DrawCircle((int)center.x, (int)center.y, radius, color);
			DrawCircleV(center, radius, color);
		}
    };
} 
