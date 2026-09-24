#include "Win.h"

estebo::Win::Win()
{}

estebo::Win::~Win()
{}

void estebo::Win::OnEnter()
{
	win_gui.show();
	Music& winMusic = ResourceManager::get().GetMusic("win_theme.ogg");
	winMusic.looping = true;
	PlayMusicStream(winMusic);
}

void estebo::Win::OnExit()
{
	entityManager.Clear();
	Music& winMusic = ResourceManager::get().GetMusic("win_theme.ogg");
	StopMusicStream(winMusic);
}

void estebo::Win::Update()
{
	entityManager.Update();
	Music& winMusic = ResourceManager::get().GetMusic("win_theme.ogg");
	UpdateMusicStream(winMusic);
}

void estebo::Win::Draw()
{
	win_gui.draw();
	entityManager.Draw();
}
