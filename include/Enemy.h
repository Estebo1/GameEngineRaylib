#include "Entity.h"

enum class EnemyState { WALK, ATTACK, DIE };

class Enemy : public Entity {
public:
	float speed = 0.8f;
	Entity* target = nullptr;

	float scale = 2.0f;
	bool facingRight = true;
	EnemyState currentState = EnemyState::WALK;

	float attackTimer = 0.0f;
	float dieTimer = 0.0f;

	Animator walkAnim{ "EnemyWalk", 8, 1, 10 };
	Animator attackAnim{ "EnemyAttack", 6, 1, 12 };
	Animator dieAnim{ "EnemyDie", 4, 1, 8 };

	Texture2D walkTex;
	Texture2D attackTex;
	Texture2D dieTex;

	Enemy();
	~Enemy();

	void Update() override;
	void Draw() override;

	void TriggerDeath();
	void TriggerAttack();
};