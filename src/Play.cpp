#include "Play.h"
#include "raylib.h"

namespace estebo {
	Play::Play()
	{}

	Play::~Play()
	{}

	void Play::OnEnter()
	{
		GenerateBalls(1);
		listen("grab_coin");
		listen("enemu_hit");
		listen("algo");
	}

	void Play::OnExit()
	{
		balls.clear();
	}

	void Play::Update()
	{
		for (Ball* ball : balls)
		{
			ball->CheckCollision(GetScreenWidth(), GetScreenHeight());
			ball->Move();
		}
		if (IsKeyPressed(KEY_A)) {
			player->PlayerHit();
		}
	}

	void Play::Draw()
	{
		ClearBackground(BLACK);

		for (Ball* ball : balls)
		{
			ball->Draw();
		}
		DrawText("Play", 200, 200, 20, WHITE);
	}

	void Play::onEvent(EventData data)
	{
		if (data.type == "grab_coin") {
			TraceLog(LOG_INFO, "Se agarro moneda");
		}
		if (data.type == "enemy_hit") {

		}
		if (data.type == "player_hit") {
			TraceLog(LOG_INFO, "Se agarro moneda");
		}
	}

	void Play::GenerateBalls(int ballNumber)
	{
		for (int i = 0; i < ballNumber; i++) {
			balls.push_back(new Ball(Ball::RandomPos(), Ball::RandomRadius(), Ball::RandomRadius(), Ball::RandomColor()));
		}
	}
}