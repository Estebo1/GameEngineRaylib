#pragma once
#include "EventBus.h"
class Player : public EventListener
{
public:
	void GrabCoin();
	void EnemyHit();
	void PlayerHit();

	void onEvent(EventData data) override;
};

