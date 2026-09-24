#pragma once
#include "Canvas.h"
namespace estebo {
    class MenuGUI : public Canvas {
    public:
        MenuGUI();
        ~MenuGUI() = default;
        void drawGUI() override;
        int playBttnId;
        bool showInstructions = false;
    };

    class PlayGUI : public Canvas {
    public:
        int score = 0;
        bool isPaused = false;
        PlayGUI();
        ~PlayGUI() = default;
        void drawGUI() override;
    };
    class LoseGUI : public Canvas {
    public:
        LoseGUI();
        ~LoseGUI() = default;

        void drawGUI() override;
        int retryBtnId;
        int returnBtnId;
    };
    class WinGUI : public Canvas {
    public:
        WinGUI();
        ~WinGUI() = default;

        void drawGUI() override;
        int retryBtnId;
        int returnBtnId;
    };
}

