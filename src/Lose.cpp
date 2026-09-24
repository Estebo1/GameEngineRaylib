#include "Lose.h"

estebo::Lose::Lose()
{}

estebo::Lose::~Lose()
{}

void estebo::Lose::OnEnter()
{
	lose_gui.show();
	Music& loseMusic = ResourceManager::get().GetMusic("lose_theme.mp3");
	loseMusic.looping = true;
	PlayMusicStream(loseMusic);
}

void estebo::Lose::OnExit()
{
	entityManager.Clear();
	Music& loseMusic = ResourceManager::get().GetMusic("lose_theme.mp3");
	StopMusicStream(loseMusic);
}

void estebo::Lose::Update()
{
	entityManager.Update();
	Music& loseMusic = ResourceManager::get().GetMusic("lose_theme.mp3");
	UpdateMusicStream(loseMusic);
}

void estebo::Lose::Draw()
{
	lose_gui.draw();
	entityManager.Draw();
}
