#pragma once

#ifndef _TICTACTOE_

#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <GLFW/glfw3.h>
#include <ctime>
#include <list>
#include "Sprite.h"
#include "GameObject.h"
#include "vector.h"

using namespace std;

enum GameState
{
	STARTGAME,
	ENDGAME,
};

class TicTacToe
{
private:
	list<GameObject*>  m_GO;

	GameObject* GO;

	//board
	Sprite* boardSprites[9];
	GameObject* boardGO[9];

	//title
	Sprite* titleSprites;
	GameObject* titleGO;

	//Player 1 sprites
	Sprite* player1Sprites;
	GameObject* player1GO;

	//Player 2 sprites
	Sprite* player2Sprites;
	GameObject* player2GO;

	Sprite* winSprites;
	GameObject* winGO;

	Sprite* loseSprites;
	GameObject* loseGO;

	Sprite* drawSprites;
	GameObject* drawGO;

	int board[9];

	int curPlayer = 0;
	int turn = 0;
	bool endGame = false;
	int results;
	int x, y;
	bool canDraw = false;

	float offset = 120.0f;
	float middleBox = 50.0f;

public:

	int mousePos[2];
	static TicTacToe& instance();

	void InitializeBoard();
	void DrawTicTacToe();
	
	void SetPlayer(int player);
	void PlayersTurn();
	void MouseClick();
	void DrawXO(int index);
	void SetMousePos(float x, float y);

	void Reset();
	void TurnSprites();

	void CheckCondition();
	void UpdateXO();

	void Start();
	void Update();
};

#endif
