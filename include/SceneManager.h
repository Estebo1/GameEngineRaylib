#pragma once
#include "Scene.h"
namespace estebo {
	class SceneManager
	{
	private:
		Scene* currentScene = nullptr;

		public:
			SceneManager() = default;
			~SceneManager() = default;
			void ChangeScene(Scene* scene);
			void Update();
			void Draw();
	};
}
