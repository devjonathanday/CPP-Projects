#pragma once

enum STATES { MAINMENU, PLAYERSELECT, GAME, GAMEOVER };

class GameState
{
private:
	GameState();
	GameState(GameState const&);  // prevents external use
	void operator=(GameState const&); // prevents external use
	int state;

public:
	int getState();
	void setState(int newState);
	static GameState& GetInstance();
	~GameState();
};