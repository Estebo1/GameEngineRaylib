#pragma once
#include "Scene.h"
#include "EntityManager.h"
#include "estebo_gui.h"

namespace estebo {
	class Win : public Scene
	{
	public:
		Win();
		~Win();
		void OnEnter() override;
		void OnExit() override;
		void Update() override;
		void Draw() override;

		EntityManager entityManager;

	private:
		WinGUI win_gui;
	};
}

