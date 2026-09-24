#pragma once
#include "raylib.h"
#include "SceneManager.h"
#include "EventBus.h"

namespace estebo {
	class Engine : public EventListener
	{
	public:
		void Initialize();
		void Run();
		void Update();
		void Draw();
		void Shutdown();
		void onEvent(EventData e) override;


	private:
		SceneManager& sceneMgr = SceneManager::Get();

		int screenWidth = 800;
		int screenHeight = 600;
	};

}