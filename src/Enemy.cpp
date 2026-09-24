#include "Enemy.h"
#include <math.h>

Enemy::Enemy() {
	name = "Enemy";
	active = false; 

	walkTex = estebo::ResourceManager::get().GetTexture("Orc_Walk.png");
	attackTex = estebo::ResourceManager::get().GetTexture("Orc_Attack.png");
	dieTex = estebo::ResourceManager::get().GetTexture("Orc_Death.png");

	walkAnim.AssignSprite(walkTex);
	attackAnim.AssignSprite(attackTex);
	dieAnim.AssignSprite(dieTex);

	collider.radius = (walkAnim.GetFrameRec().width * .4f) / 2.0f;
	collider.drawDebug = false;
}

Enemy::~Enemy() {}

void Enemy::TriggerDeath() {
	if (currentState == EnemyState::DIE) return; 

	currentState = EnemyState::DIE;
	dieTimer = 0.5f; 
	collider.radius = 0.0f; 
	
}

void Enemy::TriggerAttack() {
	if (currentState == EnemyState::DIE) return;

	currentState = EnemyState::ATTACK;
	attackTimer = 0.4f; 
}

void Enemy::Update() {
	if (!active) return;

	if (currentState == EnemyState::DIE) {
		dieTimer -= GetFrameTime();
		dieAnim.Play();

		if (dieTimer <= 0.0f) {
			active = false;
			collider.radius = (walkAnim.GetFrameRec().width * scale) / 2.0f;
		}
		return; 
	}

	if (currentState == EnemyState::ATTACK) {
		attackTimer -= GetFrameTime();
		attackAnim.Play();

		if (attackTimer <= 0.0f) {
			currentState = EnemyState::WALK; 
		}
		return; 
	}

	if (currentState == EnemyState::WALK) {
		walkAnim.Play();

		if (target != nullptr) {
			float dirX = target->position.x - position.x;
			float dirY = target->position.y - position.y;

			float magnitude = sqrt((dirX * dirX) + (dirY * dirY));
			if (magnitude > 0) {
				dirX /= magnitude;
				dirY /= magnitude;
			}

			position.x += dirX * speed;
			position.y += dirY * speed;

			if (dirX > 0) facingRight = true;
			else if (dirX < 0) facingRight = false;
		}
	}
}

void Enemy::Draw() {
	if (!active) return;

	Animator* currentAnim = &walkAnim;
	if (currentState == EnemyState::ATTACK) currentAnim = &attackAnim;
	else if (currentState == EnemyState::DIE) currentAnim = &dieAnim;

	Rectangle source = currentAnim->GetFrameRec();

	if (!facingRight) {
		source.width = -source.width;
	}
	Rectangle dest = {position.x,position.y,abs(source.width) * scale,source.height * scale};
	Vector2 origin = { dest.width / 2.0f, dest.height / 2.0f };
	DrawTexturePro(currentAnim->GetSprite(), source, dest, origin, 0.0f, WHITE);
}