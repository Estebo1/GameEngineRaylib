#include "Ship.h"
#include "GameManager.h"
void Ship::fire() {
	if (GameManager::Get().currentAmmo > 0) {
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
				GameManager::Get().currentAmmo--;
				break;
			}
		}
	}
}
void Ship::onEvent(EventData data)
{
}

void Ship::Draw() {
	if (isActive()) {
		Animator* currentAnim = &idleAnim;
		if (currentState == PlayerState::WALK) currentAnim = &walkAnim;
		else if (currentState == PlayerState::ATTACK) currentAnim = &attackAnim;

		Rectangle source = currentAnim->GetFrameRec();

		if (!facingRight) {
			source.width = -source.width;
		}

		Rectangle dest = {
			position.x,
			position.y,
			abs(source.width) * scale, 
			source.height * scale     
		};

		Vector2 origin = { dest.width / 2.0f, dest.height / 2.0f };
		Color tint = isInvulnerable ? Fade(WHITE, 0.5f) : WHITE;
		DrawTexturePro(currentAnim->GetSprite(), source, dest, origin, 0.0f, tint);
	}
}

void Ship::Update() {
	bool isMoving = false;

	if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
		position.x += speed;
		isMoving = true;
		facingRight = true; 
	}
	if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
		position.x -= speed;
		isMoving = true;
		facingRight = false; 
	}
	if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) {
		position.y -= speed;
		isMoving = true;
	}
	if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) {
		position.y += speed;
		isMoving = true;
	}

	if (attackTimer > 0.0f) {
		attackTimer -= GetFrameTime();
		currentState = PlayerState::ATTACK;
	}
	else {
		if (IsKeyPressed(KEY_SPACE) || IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			fire();
			attackTimer = 0.3f; 
			currentState = PlayerState::ATTACK;
		}
		else if (isMoving) {
			currentState = PlayerState::WALK;
		}
		else {
			currentState = PlayerState::IDLE;
		}
	}

	if (currentState == PlayerState::IDLE) idleAnim.Play();
	else if (currentState == PlayerState::WALK) walkAnim.Play();
	else if (currentState == PlayerState::ATTACK) attackAnim.Play();

	if (invulnerableTimer > 0.0f) {
		invulnerableTimer -= GetFrameTime();
		isInvulnerable = true;
	}
	else {
		isInvulnerable = false;
	}
}