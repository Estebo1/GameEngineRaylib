#pragma once
#include "Entity.h"
#include "Bullet.h"
#include "EventBus.h"
#include <math.h>
enum class PlayerState { IDLE, WALK, ATTACK };

class Ship : public Entity, EventListener
{
public:
	float speed = 2.0f;
	Bullet* bullets = nullptr;
	int maxBullets = 10;
	float invulnerableTimer = 0.0f;
	bool isInvulnerable = false;
	float scale = 2.0f; 
	bool facingRight = true; 
	PlayerState currentState = PlayerState::IDLE;
	float attackTimer = 0.0f;

	Animator idleAnim{ "Idle", 6, 1, 10 };
	Animator walkAnim{ "Walk", 8, 1, 12 };
	Animator attackAnim{ "Attack", 9, 1, 15 };
	Animator hurtAnim{ "Hurt", 4, 1, 15 };
	Animator deathAnim{ "Death",4, 1, 15 };

	Texture2D idleTex;
	Texture2D walkTex;
	Texture2D attackTex;
	Texture2D hurtTex;
	Texture2D deathTex;

	Ship() {
		name = "Ship";
		active = true;
		position = { 400.0f, 300.0f };
		idleTex = estebo::ResourceManager::get().GetTexture("Soldier_Idle.png");
		walkTex = estebo::ResourceManager::get().GetTexture("Soldier_Walk.png"); 
		attackTex = estebo::ResourceManager::get().GetTexture("Soldier_Attack.png"); 
		hurtTex = estebo::ResourceManager::get().GetTexture("Soldier_Hurt.png"); 
		deathTex = estebo::ResourceManager::get().GetTexture("Soldier_Die.png"); 

		idleAnim.AssignSprite(idleTex);
		walkAnim.AssignSprite(walkTex);
		attackAnim.AssignSprite(attackTex);
		hurtAnim.AssignSprite(hurtTex);
		deathAnim.AssignSprite(deathTex);

		collider.radius = (idleAnim.GetFrameRec().width * .2f) / 2.0f;
		collider.drawDebug = false;
	}

	~Ship() {}

	void Update() override;


	void Draw() override;

	void fire();

	void onEvent(EventData data) override;

};

