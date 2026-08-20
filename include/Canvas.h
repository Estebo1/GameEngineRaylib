#pragma once
#include "raygui.h"
//#include "raylib.h"
namespace estebo {
    class Canvas
    {
    public:
        Vector2 _position;
        Vector2 _size;
        bool _isActive;

        virtual ~Canvas() = default;
        void draw() { if (_isActive) drawGUI(); }
        virtual void drawGUI() = 0;
        void show() { _isActive = true; }
        void hide() { _isActive = false; }
        void toggle() { _isActive = !_isActive; }
        bool isActive() { return _isActive; }
    };
}
