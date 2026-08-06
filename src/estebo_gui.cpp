#include "estebo_gui.h"

void estebo::MenuGUI::Draw()
{
	if (active) {
		DrawGUI();
	}
}

void estebo::MenuGUI::DrawGUI()
{
	GuiButton(Rectangle{ 350, 250, 100, 50 }, "Play");
}

void estebo::PlayGUI::Draw()
{
	if (active) {
		DrawGUI();
	}
}

void estebo::PlayGUI::DrawGUI()
{
	GuiButton(Rectangle{ 350, 250, 100, 50 }, "Back");
}
