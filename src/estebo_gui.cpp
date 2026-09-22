#include "estebo_gui.h"
#include "raylib.h"
#include "raygui.h"
#include "Eventbus.h"
#include "SceneManager.h"


namespace estebo {
    MenuGUI::MenuGUI()
    {
        playBttnId = 0;
        _position = { 800 / 2.0f, 600 / 2.0f }; // Set the initial position of the menu GUI
        // Set the menu GUI to be active by default
    }
    void MenuGUI::drawGUI()
    {
        Rectangle startButtonRect = { _position.x, _position.y, 200, 50 };
        if (GuiButton(startButtonRect, "Start Game"))
        {
            SceneManager::Get().ChangeScene("play");
            EventBus::get().fire("start_game");
        }
        GuiButton(Rectangle{ _position.x, _position.y + 60, 200, 50 }, "Options");
        GuiButton(Rectangle{ _position.x, _position.y + 120, 200, 50 }, "Exit");
    }


    PlayGUI::PlayGUI()
    {
        _position = { 0, 0 };
    }
    void PlayGUI::drawGUI() {

    }
}