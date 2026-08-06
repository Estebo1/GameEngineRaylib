#pragma once
#include "Canvas.h"
#include "raygui.h"
namespace estebo {
	class MenuGUI : public Canvas
	{
	public:
		MenuGUI()
		{
			position = { 100, 100 };
			size = { 200, 50 };
		}
		~MenuGUI() = default;
		void Draw() override;
		void DrawGUI() override;
	};
	class  PlayGUI : public Canvas
	{
	public:
		PlayGUI()
		{
			position = { 100, 200 };
			size = { 200, 50 };
		}
		~PlayGUI() = default;
		void Draw() override;
		void DrawGUI() override;
	};
}

