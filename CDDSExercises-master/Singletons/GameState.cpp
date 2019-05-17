#include"GameState.h"

GameState::GameState() {}
GameState::~GameState() {}
GameState::GameState(GameState const&) {}
void GameState::operator=(GameState const&) {}
int GameState::getState()
{
	return state;
}
void GameState::setState(int newState)
{
	state = newState;
}
GameState& GameState::GetInstance()
{
	static GameState instance;
	return instance;
}
