
#include "Engine.h"
#include "resource_dir.h"	
#include "Menu.h"
#include "Play.h"

namespace estebo {
	
	void Engine::Initialize()
	{

		SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

		InitWindow(screenWidth, screenHeight, "Hello Raylib");
		TraceLog(LOG_INFO, "Se inicio raylib");
		SearchAndSetResourceDir("resources");
		sceneMgr.AddScene("menu", new Menu()); 
		sceneMgr.AddScene("play", new Play()); 
		sceneMgr.ChangeScene("menu"); 
		listen("exit_game");
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
	sceneMgr.Update(); 
}

void Engine::Draw()
{
	BeginDrawing();
	ClearBackground(BLACK);
	sceneMgr.Draw(); 
	EndDrawing();
}

void Engine::Shutdown()
{
	sceneMgr.Shutdown();
	exit(0);
	CloseWindow();
}

void Engine::onEvent(EventData e)
{
	if (e.type == "exit_game") {
		Shutdown();
	}
}

}
