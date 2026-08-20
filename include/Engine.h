#pragma once
#include "raylib.h"
#include "SceneManager.h"

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
		SceneManager& sceneMgr = SceneManager::Get();

		int screenWidth = 800;
		int screenHeight = 600;
	};

}