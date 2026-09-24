#pragma once
#include "Scene.h"
#include "Ball.h"
#include <vector>
#include "raylib.h"
#include "raygui.h"
#include "EntityManager.h"
#include "estebo_gui.h"
#include "EventBus.h"

namespace estebo {
    class Menu : public Scene, public EventListener 
    {
        MenuGUI menu_gui;
        int playEventId;
    public:
        Menu();
        ~Menu();
        void OnEnter() override;
        void OnExit() override;
        void Update() override;
        void Draw() override;
        void onEvent(EventData data) override;
    private:
    };
}
