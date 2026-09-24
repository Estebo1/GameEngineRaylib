#include "estebo_gui.h"
#include "raylib.h"
#include "raygui.h"
#include "Eventbus.h"
#include "SceneManager.h"
#include "GameManager.h"

namespace estebo {

    MenuGUI::MenuGUI()
    {
        playBttnId = 0;
        _position = { (800 / 2.0f) - 100, 600 / 2.0f };
        showInstructions = false;
    }

    void MenuGUI::drawGUI()
    {
        if (showInstructions) {

            DrawText("CONTROLES E INSTRUCCIONES", 800 / 2 - MeasureText("CONTROLES E INSTRUCCIONES", 30) / 2, 150, 30, WHITE);

            DrawText(" Usa los botones WASD del teclado para moverte", 150, 230, 20, LIGHTGRAY);
            DrawText(" Usa el Click Izquierdo del mouse para disparar", 150, 270, 20, LIGHTGRAY);
            DrawText(" Presiona ESC o P para pausar el juego.", 150, 310, 20, LIGHTGRAY);
            DrawText(" Sobrevive todo el tiempo que puedas.", 150, 350, 20, LIGHTGRAY);

            Rectangle backButtonRect = { _position.x, 450, 200, 50 };
            if (GuiButton(backButtonRect, "Volver al Menu")) {
                showInstructions = false; 
            }
        }
        else {

            DrawText("Raylib Survivor", 800 / 2 - MeasureText("Raylib Survivor", 50) / 2, 150, 50, WHITE);

            Rectangle startButtonRect = { _position.x, _position.y, 200, 50 };
            if (GuiButton(startButtonRect, "Start Game"))
            {
                SceneManager::Get().ChangeScene("play");
                EventBus::getInstance().fire("start_game");
            }

            Rectangle instructionsButtonRect = { _position.x, _position.y + 60, 200, 50 };
            if (GuiButton(instructionsButtonRect, "Instrucciones")) {
                showInstructions = true;
            }

            Rectangle exitButtonRect = { _position.x, _position.y + 120, 200, 50 };
            if (GuiButton(exitButtonRect, "Exit")) {
                EventBus::getInstance().fire("exit_game");
            }
        }
    }


    PlayGUI::PlayGUI()
    {
        _position = { 0, 0 };
    }
    void PlayGUI::drawGUI() {
        DrawText(TextFormat("SCORE: %04i", GameManager::Get().score), 20, 20, 20, WHITE);
        DrawText(TextFormat("LIVES: %i", GameManager::Get().lives), 20, 50, 20, RED);
        DrawText(TextFormat("AMMO: %i", GameManager::Get().currentAmmo), 20, 80, 20, YELLOW);

        if (IsKeyPressed(KEY_ESCAPE) || IsKeyPressed(KEY_P)) {
            isPaused = !isPaused;
            EventBus::getInstance().fire("pause_game");
        }

        if (isPaused) {
            DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Fade(BLACK, 0.7f));

            DrawText("PAUSED", GetScreenWidth() / 2 - MeasureText("PAUSED", 40) / 2, 150, 40, WHITE);

            Rectangle resumeBtn = { GetScreenWidth() / 2.0f - 100, 250, 200, 50 };
            if (GuiButton(resumeBtn, "Resume")) {
                isPaused = false;
                EventBus::getInstance().fire("resume_game");
            }

            Rectangle menuBtn = { GetScreenWidth() / 2.0f - 100, 320, 200, 50 };
            if (GuiButton(menuBtn, "Return to Menu")) {
                isPaused = false;
                EventBus::getInstance().fire("menu_game");
                SceneManager::Get().ChangeScene("menu");
            }
        }
    }

    LoseGUI::LoseGUI() {
        retryBtnId = 0;
        returnBtnId = 0;
        _position = { 800 / 2.0f, 600 / 2.0f };
    };
    void LoseGUI::drawGUI() {
        DrawText("GAME OVER", GetScreenWidth() / 2 - MeasureText("GAME OVER", 50) / 2, 100, 50, RED);

        DrawText(TextFormat("Final Score: %i", GameManager::Get().score), GetScreenWidth() / 2 - 100, 200, 30, WHITE);
        DrawText(TextFormat("High Score: %i", GameManager::Get().maxScore), GetScreenWidth() / 2 - 100, 240, 30, YELLOW);

        Rectangle retryButtonRect = { _position.x - 100, _position.y, 200, 50 };
        if (GuiButton(retryButtonRect, "Retry Game"))
        {
            SceneManager::Get().ChangeScene("play");
            EventBus::getInstance().fire("start_game");
        }
        Rectangle returnButtonRect = { _position.x - 100, _position.y + 120, 200, 50 };
        if (GuiButton(returnButtonRect, "Return to Menu"))
        {
            SceneManager::Get().ChangeScene("menu");
            EventBus::getInstance().fire("menu_game");
        }
    }
    WinGUI::WinGUI() {
        retryBtnId = 0;
        returnBtnId = 0;
        _position = { 800 / 2.0f, 600 / 2.0f };
    };
    void WinGUI::drawGUI() {
        DrawText("¡VICTORIA!", GetScreenWidth() / 2 - MeasureText("¡VICTORIA!", 50) / 2, 100, 50, GREEN);

        DrawText(TextFormat("Final Score: %i", GameManager::Get().score), GetScreenWidth() / 2 - 100, 200, 30, WHITE);
        DrawText(TextFormat("High Score: %i", GameManager::Get().maxScore), GetScreenWidth() / 2 - 100, 240, 30, YELLOW);

        Rectangle retryButtonRect = { _position.x - 100, _position.y, 200, 50 };
        if (GuiButton(retryButtonRect, "Play Again"))
        {
            SceneManager::Get().ChangeScene("play");
            EventBus::getInstance().fire("start_game");
        }
        Rectangle returnButtonRect = { _position.x - 100, _position.y + 120, 200, 50 };
        if (GuiButton(returnButtonRect, "Return to Menu"))
        {
            EventBus::getInstance().fire("menu_game");
            SceneManager::Get().ChangeScene("menu");
        }
    }
}