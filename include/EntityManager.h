#pragma once
#include <vector>
#include "Entity.h"

namespace estebo
{
	class EntityManager
	{
	public:
		std::vector<Entity*> entities;

		EntityManager() = default;
		~EntityManager() = default;

		void Add(Entity* entity);
		void Clear();

		void Update();
		void Draw();
	};
}

