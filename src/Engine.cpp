
#include "Engine.h"
#include "resource_dir.h"	// utility header for SearchAndSetResourceDir
#include "Menu.h"
#include "Play.h"

namespace estebo {
	
	void Engine::Initialize()
	{

		// Tell the window to use vsync and work on high DPI displays
		SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
		// Create the window and OpenGL context
		InitWindow(screenWidth, screenHeight, "Hello Raylib");
		TraceLog(LOG_INFO, "Se inicio raylib");
		// Utility function from resource_dir.h to find the resources folder and set it as the current working directory so we can load from it
		SearchAndSetResourceDir("resources");
		sceneMgr.AddScene("menu", new Menu()); // Register the menu scene
		sceneMgr.AddScene("play", new Play()); // Register the play scene
		sceneMgr.ChangeScene("menu"); // Set the initial scene to the menu

	}

void Engine::Run()
{
	// Main game loop
	while (!WindowShouldClose()) // Detect window close button or ESC key
	{
		Update();
		Draw();
	}
}

void Engine::Update()
{
	sceneMgr.Update(); // Update the current scene
}

void Engine::Draw()
{
	// Draw game objects here
	BeginDrawing();
	// Setup the back buffer for drawing (clear color and depth buffers)
	ClearBackground(BLACK);
	sceneMgr.Draw(); // Draw the current scene
	EndDrawing();
}

void Engine::Shutdown()
{
	//sceneManager.changeScene(nullptr); // Exit the current scene
	// Cleanup and shutdown code here
	CloseWindow();
}

}
