#pragma once
#include "Entity.h"
#include <vector>

class EntityManager
{
public:
	std::vector<Entity*> entitites;

	EntityManager() = default;

	void Add(Entity* entity) {
		if (entity != nullptr) {
			entitites.push_back(entity);
		}
	}
	void Update() {
		for (Entity* entity : entitites) {
			if (entity && entity->isActive()) {
				entity->Update();
			}
		}
	}
	void Draw() {
		for (Entity* entity : entitites) {
			if (entity && entity->isActive()) {
				entity->Draw();
			}
		}
	}
	void Clear() {
		entitites.clear();
	}
};


