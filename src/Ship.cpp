#include "Ship.h"
void Ship::fire() {
	for (int i = 0; i < maxBullets; i++) {
		if (!bullets[i].active) {
			bullets[i].position.x = position.x;
			bullets[i].position.y = position.y;

			Vector2 mousePos = GetMousePosition();

			float dirX = mousePos.x - position.x;
			float dirY = mousePos.y - position.y;
			float magnitude = sqrt((dirX * dirX) + (dirY * dirY));

			if (magnitude > 0) {
				dirX /= magnitude;
				dirY /= magnitude;
			}
			bullets[i].velocity.x = dirX * bullets[i].speed;
			bullets[i].velocity.y = dirY * bullets[i].speed;
			bullets[i].active = true;
			break;
		}
	}
}
void Ship::onEvent(EventData data)
{
}
void Ship::Draw(){
	if (isActive() || texture.id != 0) {
		Vector2 pos = { position.x - texture.width / 2,position.y - texture.height / 2 };
		DrawTextureEx(texture, pos, 0.0f, 1.0f, WHITE);
	}
}
void Ship::Update() {
	if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
		position.x += speed;
	}
	if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
		position.x -= speed;
	}
	if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) {
		position.y -= speed;
	}
	if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) {
		position.y += speed;
	}
	if (IsKeyPressed(KEY_SPACE) || IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
		fire();
	}
}