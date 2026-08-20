#pragma once
#include "Canvas.h"
namespace estebo {
    class MenuGUI : public Canvas {
    public:
        MenuGUI();
        ~MenuGUI() = default;
        void drawGUI() override;
        int playBttnId;
    };

    class PlayGUI : public Canvas {
    public:
        PlayGUI();
        ~PlayGUI() = default;
        void drawGUI() override;
    };
}

