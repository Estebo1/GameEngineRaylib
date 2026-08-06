
//#include "raylib.h"
#include "Engine.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

int main ()
{
	// Tell the window to use vsync and work on high DPI displays
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

	// Create the window and OpenGL context
	InitWindow(800, 600, "Hello Raylib");

	// Utility function from resource_dir.h to find the resources folder and set it as the current working directory so we can load from it
	SearchAndSetResourceDir("resources");

	estebo::Engine engine;
	engine.Initialize();
	engine.Run();
	engine.Shutdown();

	return 0;
}
