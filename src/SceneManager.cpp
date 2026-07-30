#include "SceneManager.h"
namespace estebo{
	void SceneManager::ChangeScene(Scene* scene)
	{
		if (currentScene) {
			currentScene->OnExit();
		}
		currentScene = scene;

		if (currentScene)
		{
			currentScene->OnEnter();
		}
	}

	void SceneManager::Update()
	{
		if (currentScene) {
			currentScene->Update();
		}
	}

	void SceneManager::Draw()
	{
		if (currentScene) {
			currentScene->Draw();
		}
	}
}