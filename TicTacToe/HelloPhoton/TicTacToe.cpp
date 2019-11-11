#include "TicTacToe.h"
#include <iostream>

using namespace std;

void TicTacToe::InitializeBoard()
{
	// draw board
	for (int i = 0; i <= 2; i++) 
	{
		for (int j = 0; j <= 2; j++)
		{		
			int k = (i * 3) + j;
			//initialize images
			boardSprites[k] = new Sprite("../media/board.bmp");
			boardGO[k] = new GameObject(boardSprites[k]);

			//SetPos(x +offset, y ,0)
			boardGO[k]->SetPos(Vector(((i + 1) * offset) + 170, (j + 1) * offset + 30, 0));
			boardGO[k]->SetScale(1.0f);
			
			board[k] = 0;
			cout << board[k] << endl;
		}
	}

	// draw title
	titleSprites = new Sprite("../media/Title.bmp");
	titleGO = new GameObject(titleSprites);
	titleGO->SetPos(Vector(400.0f, 550.0f,0));
	titleGO->SetScale(1.0f);
}

void TicTacToe::DrawTicTacToe()
{
	//draw board
	for (int i = 0; i <= 2; i++) 
	{
		for (int j = 0; j <= 2; j++) 
		{
			int k = (i * 3) + j;
			boardGO[k]->draw();
		}
	}

	//draw title
	titleGO->draw();
}

void TicTacToe::SetPlayer(int player)
{
	if (curPlayer == 0)
	{
		curPlayer = player;
		cout<<curPlayer<<endl;
	}
}

void TicTacToe::PlayersTurn()
{
	turn++;
	if (turn % 2 == 0)
	{
		turn = 0;
	}

	cout << "Player's Turn" << turn << endl;
}

void TicTacToe::SetMousePos(float x, float y)
{
	mousePos[0] = x;
	mousePos[1] = y;
}

void TicTacToe::MouseClick() 
{
	int k;

	for (int i = 0; i <= 2; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			// mousePos[0] = xPos, mousePos[1] = yPos
			if (mousePos[0] >= (((i + 1) * offset) + 170) - middleBox && mousePos[0] <= (((i + 1) * offset) + 170) + middleBox &&
				mousePos[1] >= ((j + 1) * offset) - middleBox && mousePos[1] <= ((j + 1) * offset)+ middleBox)
			{
				k = (i * 3) + j;

				if (board[k] == 0)
				{
					board[k] == 1;
					cout << k << endl;
					DrawXO(k);
				}
			}
		}
	}
}

void TicTacToe::DrawXO(int index)
{
	player1Sprites = new Sprite("../media/Player1.bmp");
	player1GO = new GameObject(player1Sprites);

	board[index] = 1;
	boardGO[index]->SetSprite(player1Sprites);
	boardGO[index]->getSprite();
	canDraw = true;

	/*if (curPlayer == 1 && turn == 0)
	{
		player1Sprites = new Sprite("../media/Player1.bmp");
		player1GO = new GameObject(player1Sprites);

		board[index] == 1;
	}
	else if (curPlayer == 2 && turn == 0)
	{
		player2Sprites = new Sprite("../media/Player2.bmp");
		player2GO = new GameObject(player2Sprites);

		board[index] == 1;
	}

	else if (curPlayer == 1 && turn == 1)
	{
		player1Sprites = new Sprite("../media/Player1.bmp");
		player1GO = new GameObject(player1Sprites);

		board[index] == 2;
	}

	else if (curPlayer == 2 && turn == 1)
	{
		player2Sprites = new Sprite("../media/Player2.bmp");
		player2GO = new GameObject(player2Sprites);

		board[index] == 2;
	}*/

	cout << board[index] << endl;
}

void TicTacToe::CheckCondition()
{
	//player 1 win 
	if (
		//check horizontal
		board[0] == 1 && board[1] == 1 && board[2] == 1 || board[3] == 1 && board[4] == 1 && board[5] == 1 || board[6] == 1 && board[7] == 1 && board[8] == 1 ||
		//check vertical 
		board[0] == 1 && board[3] == 1 && board[6] == 1 || board[1] == 1 && board[4] == 1 && board[7] == 1 || board[2] == 1 && board[5] == 1 && board[8] == 1 ||
		//check diagonal 
		board[0] == 1 && board[4] == 1 && board[8] == 1 || board[2] == 1 && board[4] == 1 && board[6] == 1
		)
	{
		cout << "You Win" << endl;
		winSprites = new Sprite("../media/YouWin.bmp");
		winGO = new GameObject(winSprites);
		winGO->SetPos(Vector(400.0f, 480.0f, 0));
		winGO->SetScale(1.0f);
		winGO->draw();

		/*if (curPlayer == 1)
		{
			winSprites = new Sprite("../media/YouWin.bmp");
			winGO = new GameObject(winSprites);
			winGO->SetPos(Vector(400.0f, 480.0f, 0));
			winGO->SetScale(1.0f);

			cout << "You Win" << endl;
		}
		else if (curPlayer == 2)
		{
			loseSprites = new Sprite("../media/YouLose.bmp");
			loseGO = new GameObject(winSprites);
			loseGO->SetPos(Vector(400.0f, 480.0f, 0));
			loseGO->SetScale(1.0f);

			cout << "You Lose" << endl;
		}*/
	}
	//if player 2
	else if (
		board[0] == 2 && board[1] == 2 && board[2] == 2 || board[3] == 2 && board[4] == 2 && board[5] == 2 || board[6] == 2 && board[7] == 2 && board[8] == 2 ||
		//check vertical 
		board[0] == 2 && board[3] == 2 && board[6] == 2 || board[1] == 2 && board[4] == 2 && board[7] == 2 || board[2] == 2 && board[5] == 2 && board[8] == 2 ||
		//check diagonal 
		board[0] == 2 && board[4] == 2 && board[8] == 2 || board[2] == 2 && board[4] == 2 && board[6] == 2
		)
	{
		if (curPlayer == 1)
		{
			loseSprites = new Sprite("../media/YouLose.bmp");
			loseGO = new GameObject(winSprites);
			loseGO->SetPos(Vector(400.0f, 480.0f, 0));
			loseGO->SetScale(1.0f);

			cout << "You Lose" << endl;
		}
		else if (curPlayer == 2)
		{
			winSprites = new Sprite("../media/YouWin.bmp");
			winGO = new GameObject(winSprites);
			winGO->SetPos(Vector(400.0f, 480.0f, 0));
			winGO->SetScale(1.0f);

			cout << "You Win" << endl;			
		}
	}

	//if player draw
	else if (
		//check horizontal
		board[0] !=0 && board[1] != 0 && board[2] != 0 || board[3] != 0 && board[4] != 0 && board[5] != 0 || board[6] != 0 && board[7] != 0 && board[8] != 0 ||
		//check vertical 
		board[0] != 0 && board[3] != 0 && board[6] != 0 || board[1] != 0 && board[4] != 0 && board[7] != 0 || board[2] != 0 && board[5] != 0 && board[8] != 0 ||
		//check diagonal 
		board[0] != 0 && board[4] != 0 && board[8] != 0 || board[2] != 0 && board[4] != 0 && board[6] != 0)
	{
		drawSprites = new Sprite("../media/Draw.bmp");
		drawGO = new GameObject(drawSprites);
		drawGO->SetPos(Vector(400.0f, 480.0f, 0));
		drawGO->SetScale(1.0f);
	}
}

TicTacToe& TicTacToe::instance()
{
	static TicTacToe instance;
	return instance;
}

void TicTacToe::TurnSprites()
{
	if (curPlayer == 1 && turn == 0 || curPlayer == 2 && turn == 1)
	{

	}
}

void TicTacToe::UpdateXO()
{
	if (canDraw)
	{
		player1GO->draw();
	}
}

void TicTacToe::Start()
{
	InitializeBoard();	
}

void TicTacToe::Update()
{
	DrawTicTacToe();
	CheckCondition();
	UpdateXO();
}


