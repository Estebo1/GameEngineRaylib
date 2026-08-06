
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
		Update();
		Draw();
	}
}

void Engine::Update()
{
	sceneManager.Update();
	if (IsKeyPressed(KEY_A)) {
		printf("A key pressed\n");
		sceneManager.ChangeScene(&menu);
	}
	if (IsKeyPressed(KEY_S)) {
		printf("S key pressed\n");
		sceneManager.ChangeScene(&play);
	}
	sceneManager.Update();
}

void Engine::Draw()
{
	BeginDrawing();

	//ClearBackground(RAYWHITE);

	sceneManager.Draw();

	EndDrawing();
}

void Engine::Shutdown()
{
	sceneManager.ChangeScene(nullptr);
	CloseWindow();
}

}
