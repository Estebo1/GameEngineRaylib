#pragma once
#include "raygui.h"
//#include "raylib.h"
namespace estebo {
	class Canvas
	{
	protected:
		Vector2 position;
		Vector2 size;
		bool active = false;

	public:
		//Canvas() = default;
		virtual ~Canvas() = default;
		virtual void Draw() = 0;
		virtual void DrawGUI() = 0;
		void setPosition(float x, float y){ position = { x, y }; };
		void setSize(float width, float height) { size = { width, height }; };
		void show() { active = true; };
		void hide() { active = false; };
		void toggle() { active = !active; };
	};
}
