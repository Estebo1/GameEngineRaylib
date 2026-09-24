#pragma once
#include "raylib.h"

class GameManager {
public:
    int lives = 3;
    int score = 0;
    int maxScore = 0;
    int currentAmmo = 10;
    int maxAmmo = 10;

    float ammoRechargeTimer = 0.0f;
    float ammoRechargeTime = 1.5f; 

    static GameManager& Get() {
        static GameManager instance;
        return instance;
    }
    void CheckHighScore() {
        if (score > maxScore) {
            maxScore = score;
        }
    }
    void Reset() {
        lives = 3;
        score = 0;
        currentAmmo = maxAmmo;
        ammoRechargeTimer = 0.0f;
    }

    void Update() {
        if (currentAmmo < maxAmmo) {
            ammoRechargeTimer += GetFrameTime();
            if (ammoRechargeTimer >= ammoRechargeTime) {
                currentAmmo++;
                ammoRechargeTimer = 0.0f;
            }
        }
    }
};