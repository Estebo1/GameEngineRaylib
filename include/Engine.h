#pragma once
#include "SceneManager.h"
#include "Menu.h"
#include "Play.h"
#include "raylib.h"
#include "resource_dir.h"

namespace estebo {
	class Engine
	{
	public:
		void Initialize();
		void Run();
		void Update();
		void Draw();
		void Shutdown();
	private:
		SceneManager sceneManager;
		Menu menu;
		Play play;
	};

}