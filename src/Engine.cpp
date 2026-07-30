
#include "Engine.h"

namespace estebo {

void Engine::Initialize()
{
	sceneManager.ChangeScene(&menu);
}

void Engine::Run()
{
	while (!WindowShouldClose())
	{
		sceneManager.Update();
		sceneManager.Draw();
	}
}

void Engine::Update()
{
	sceneManager.Update();
	if (IsKeyPressed(KEY_A)) {
		sceneManager.ChangeScene(&menu);
	}
	if (IsKeyPressed(KEY_S)) {
		sceneManager.ChangeScene(&play);
	}
}

void Engine::Draw()
{
	BeginDrawing();

	ClearBackground(BLACK);
	sceneManager.Draw();
	EndDrawing();
}

void Engine::Shutdown()
{
	sceneManager.ChangeScene(nullptr);
	CloseWindow();
}

}
