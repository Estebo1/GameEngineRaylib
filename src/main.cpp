
//#include "raylib.h"
#include "Engine.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#include "raylib.h"



int main ()
{
	// Tell the window to use vsync and work on high DPI displays

	estebo::Engine engine;
	engine.Initialize();
	engine.Run();
	engine.Shutdown();

	return 0;
}
