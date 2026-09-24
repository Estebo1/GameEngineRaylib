#include "Win.h"

estebo::Win::Win()
{}

estebo::Win::~Win()
{}

void estebo::Win::OnEnter()
{
	win_gui.show();
}

void estebo::Win::OnExit()
{
	entityManager.Clear();
}

void estebo::Win::Update()
{
	entityManager.Update();
}

void estebo::Win::Draw()
{
	win_gui.draw();
	entityManager.Draw();
}
