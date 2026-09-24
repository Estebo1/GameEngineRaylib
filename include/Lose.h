#pragma once
#include "Scene.h"
#include "EntityManager.h"
#include "estebo_gui.h"

namespace estebo {
	class Lose : public Scene
	{
	public:
		Lose();
		~Lose();
		void OnEnter() override;
		void OnExit() override;
		void Update() override;
		void Draw() override;

		EntityManager entityManager;

	private:
		LoseGUI lose_gui;
	};
}

