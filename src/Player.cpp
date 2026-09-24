#include "Player.h"

void Player::GrabCoin()
{
	EventData data;
	data.type = "grab_coin";
	EventBus::getInstance().fire("grab_coin", data);
}

void Player::EnemyHit()
{
	
}

void Player::PlayerHit()
{
	EventData data;
	data.type = "player_hit";
	data.intVal = 20;
	EventBus::getInstance().fire("player_hit", data);
}
