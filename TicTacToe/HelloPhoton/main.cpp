#include <iostream>
#include <list>
#include "MyPhoton.h"

#include <windows.h>
#include <GL/GLU.h>
#include <GLFW/glfw3.h>

#include "Application.h"
#include "GameObject.h"
#include "Sprite.h"

using namespace std;

const int RESOLUTION_X = 800;
const int RESOLUTION_Y = 600;

GameObject* GO;

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

Sprite* resetSprites;
GameObject* resetGO;

Sprite* yourTurnSprites;
Sprite* otherTurnSprites;
GameObject* playerTurnsGO;

float offset = 120.0f;
float middleBox = 50.0f;

int curPlayer = 0;
int turn = 0;

int mousePos[2];
int board[9] = { 0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f};

bool canDraw = false;

//set game status
bool startGame = false;

void SetMousePos(int x, int y)
{
	mousePos[0] = x;
	mousePos[1] = y;
}

void SetPlayer()
{
	if (MyPhoton::getInstance().setPlayer == 1)
	{
		curPlayer = 1;
	}

	else if(MyPhoton::getInstance().setPlayer == 2)
	{
		curPlayer = 2;
	}
}

void PlayersTurn()
{
	if (MyPhoton::getInstance().canMove == true)
	{
		playerTurnsGO->SetSprite(yourTurnSprites);
	}
	else if(MyPhoton::getInstance().canMove == false)
	{
		playerTurnsGO->SetSprite(otherTurnSprites);
	}
}


void DrawXO(int index)
{	
	if (board[index] == 1)
	{
		boardGO[index]->SetSprite(player1Sprites);
		//board[index] = 1;
	}

	else if (board[index] == 0)
	{
		boardGO[index]->SetSprite(boardSprites[index]);
		//board[index] = 0;
	}

	else if (board[index] == 2)
	{
		boardGO[index]->SetSprite(player2Sprites);		
		//board[index] = 2;
	}	
}

void Reset()
{
	for (int i = 0; i < 9; i++)
	{
		board[i] = 0;
		board[0] = 0;
		DrawXO(i);
		MyPhoton::getInstance().setData(board, curPlayer);
		board[i] = MyPhoton::getInstance().storeData[i];
	}
}

void CheckCondition()
{
	//player 1 win 
	if (
		//check horizontal
		board[0] == 1 && board[1] == 1 && board[2] == 1 || 
		board[3] == 1 && board[4] == 1 && board[5] == 1 || 
		board[6] == 1 && board[7] == 1 && board[8] == 1 ||
		//check vertical 
		board[0] == 1 && board[3] == 1 && board[6] == 1 || 
		board[1] == 1 && board[4] == 1 && board[7] == 1 || 
		board[2] == 1 && board[5] == 1 && board[8] == 1 ||
		//check diagonal 
		board[0] == 1 && board[4] == 1 && board[8] == 1 ||
		board[2] == 1 && board[4] == 1 && board[6] == 1
		)
	{
		if (curPlayer == 1)
		{
			winGO->draw();
		}
		else if (curPlayer == 2)
		{
			loseGO->draw();
		}
	}
	//if player 2
	else if (
		board[0] == 2 && board[1] == 2 && board[2] == 2 || 
		board[3] == 2 && board[4] == 2 && board[5] == 2 || 
		board[6] == 2 && board[7] == 2 && board[8] == 2 ||
		//check vertical 
		board[0] == 2 && board[3] == 2 && board[6] == 2 || 
		board[1] == 2 && board[4] == 2 && board[7] == 2 || 
		board[2] == 2 && board[5] == 2 && board[8] == 2 ||
		//check diagonal 
		board[0] == 2 && board[4] == 2 && board[8] == 2 || 
		board[2] == 2 && board[4] == 2 && board[6] == 2
		)
	{
		if (curPlayer == 1)
		{
			loseGO->draw();
		}
		else if (curPlayer == 2)
		{
			winGO->draw();
		}
	}

	//if player draw
	else if (
		//check horizontal
		board[0] != 0 && board[1] != 0 && board[2] != 0 && 
		board[3] != 0 && board[4] != 0 && board[5] != 0 && 
		board[6] != 0 && board[7] != 0 && board[8] != 0 &&
		//check vertical 
		board[0] != 0 && board[3] != 0 && board[6] != 0 && 
		board[1] != 0 && board[4] != 0 && board[7] != 0 && 
		board[2] != 0 && board[5] != 0 && board[8] != 0 &&
		//check diagonal 
		board[0] != 0 && board[4] != 0 && board[8] != 0 && 
		board[2] != 0 && board[4] != 0 && board[6] != 0)
	{
		drawGO->draw();
	}
}

void MouseClick()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int k = (i * 3) + j;

			//check board
			// mousePos[0] = xPos, mousePos[1] = yPos
			if (mousePos[0] >= ((i + 1) * offset) + 170 - middleBox &&
				mousePos[0] <= ((i + 1) * offset) + 170 + middleBox &&
				mousePos[1] >= (j + 1) * offset - middleBox &&
				mousePos[1] <= (j + 1) * offset + middleBox&&MyPhoton::getInstance().canMove)
			{
				std::cout << "Click in box" << std::endl;

				if (board[k] == 0)
				{
					if (curPlayer == 1)
					{
						std::cout << "player 1 set" << std::endl;
						board[k] = 1;
						DrawXO(k);						
						MyPhoton::getInstance().setData(board, curPlayer);	
						
					}
					else if (curPlayer == 2)
					{
						std::cout << "player 2 set" << std::endl;
						board[k] = 2;
						DrawXO(k);					
						MyPhoton::getInstance().setData(board, curPlayer);		
					}
					PlayersTurn();
				}				
			}	

			//check reset button
			else if (mousePos[0] >= 650.0f && mousePos[0] < 800.0f && mousePos[1] >= 200.0f && mousePos[1] < 300.0f)
			{
				cout << mousePos[0] << ", " << mousePos[1] << endl;
				board[k] = 0;
				board[0] = 0;
				DrawXO(k);
				MyPhoton::getInstance().setData(board, curPlayer);
				board[k] = MyPhoton::getInstance().storeData[k];
				PlayersTurn();
			}
		}
	}
}

void InitializeBoard()
{
	// draw title
	titleSprites = new Sprite("../media/Title.bmp");
	titleGO = new GameObject(titleSprites);
	titleGO->SetPos(Vector(400.0f, 550.0f, 0));
	titleGO->SetScale(1.0f);

	//set player 1 sprites
	player1Sprites = new Sprite("../media/Player1.bmp");
	player1GO = new GameObject(player1Sprites);

	//set player 2 sprites
	player2Sprites = new Sprite("../media/Player2.bmp");
	player2GO = new GameObject(player2Sprites);

	drawSprites = new Sprite("../media/Draw.bmp");
	drawGO = new GameObject(drawSprites);
	drawGO->SetPos(Vector(400.0f, 480.0f, 0));
	drawGO->SetScale(1.0f);

	winSprites = new Sprite("../media/YouWin.bmp");
	winGO = new GameObject(winSprites);
	winGO->SetPos(Vector(400.0f, 480.0f, 0));
	winGO->SetScale(1.0f);

	loseSprites = new Sprite("../media/YouLose.bmp");
	loseGO = new GameObject(loseSprites);
	loseGO->SetPos(Vector(400.0f, 480.0f, 0));
	loseGO->SetScale(1.0f);

	resetSprites = new Sprite("../media/Reset.bmp");
	resetGO = new GameObject(resetSprites);
	resetGO->SetPos(Vector(700.0f, 240.0f,0));
	resetGO->SetScale(1.0f);

	yourTurnSprites = new Sprite("../media/Your Turn.bmp");
	otherTurnSprites = new Sprite("../media/Other Turn.bmp");
	playerTurnsGO = new GameObject(otherTurnSprites);
	playerTurnsGO->SetPos(Vector(700.0f, 340.0f, 0));
	playerTurnsGO->SetScale(1.0f);

	// draw board
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int k = (i * 3) + j;
			//initialize images
			boardSprites[k] = new Sprite("../media/board.bmp");
			boardGO[k] = new GameObject(boardSprites[k]);

			//SetPos(x +offset, y ,0)
			boardGO[k]->SetSprite(boardSprites[k]);
			boardGO[k]->SetPos(Vector(((i + 1) * offset) + 170, (j + 1) * offset, 0));			
			boardGO[k]->SetScale(1.0f);

			//set to array
			board[k] = 0;			
		}
	}
}

void DrawTicTacToe()
{
	for (int i = 0; i < 9 ; i++)
	{
		boardGO[i]->draw();
	}

	//draw title
	titleGO->draw();
	resetGO->draw();
	playerTurnsGO->draw();
}

void onWindowResized(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	//! Use ortho2D view
	gluOrtho2D(0, width, 0, height);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_R && action == GLFW_PRESS)
	{
		Reset();
	}
}

static void cursor_position_callback(GLFWwindow* window, double xPos, double yPos)
{
	SetMousePos(xPos, RESOLUTION_Y - yPos);
}

static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{	
		MouseClick();		
	}
}

int main (void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create m_a windowed mode window and its OpenGL context */
	window = glfwCreateWindow (RESOLUTION_X, RESOLUTION_Y, "", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwSetWindowSizeCallback (window, onWindowResized);
	
	glfwSetKeyCallback(window, key_callback);
	glfwSetCursorPosCallback(window, cursor_position_callback);
	glfwSetMouseButtonCallback(window, mouse_button_callback);

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	onWindowResized (window, RESOLUTION_X, RESOLUTION_Y);

	MyPhoton::getInstance().connect();

	gluOrtho2D(0, RESOLUTION_X, 0, RESOLUTION_Y);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	InitializeBoard();

	while (!glfwWindowShouldClose(window))
	{
		MyPhoton::getInstance().run();

		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);
		
		SetPlayer();
		DrawTicTacToe();
		CheckCondition();

		// network extract
		for (int i = 0; i < 9 ; i++)
		{	
			DrawXO(i);
			board[i] = MyPhoton::getInstance().storeData[i];
			PlayersTurn();
		}	

		/* Swap front and back buffers */
		glfwSwapBuffers (window);
		/* Poll for and process events */
		glfwPollEvents ();		
	}

	glfwTerminate();
	return 0;
}