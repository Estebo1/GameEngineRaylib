#include "Lose.h"

estebo::Lose::Lose()
{}

estebo::Lose::~Lose()
{}

void estebo::Lose::OnEnter()
{
	lose_gui.show();
}

void estebo::Lose::OnExit()
{
	entityManager.Clear();
}

void estebo::Lose::Update()
{
	entityManager.Update();
}

void estebo::Lose::Draw()
{
	lose_gui.draw();
	entityManager.Draw();
}
