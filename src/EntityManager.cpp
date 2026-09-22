#include "EntityManager.h"

namespace estebo {
	void EntityManager::Add(Entity* entity) {
		if (entity != nullptr)
			entities.push_back(entity);
	}

	void EntityManager::Clear()
	{
		entities.clear();
	}

	void EntityManager::Update() {
		for (Entity* entity : entities) {
			if (entity && entity->active) {
				entity->Update();
				entity->collider.Update(entity->position);
			}
		}
	}

	void EntityManager::Draw() {
		for (Entity* entity : entities) {
			if (entity && entity->active) {
				entity->Draw();
				entity->collider.DebugDraw();
			}
		}
	}
}