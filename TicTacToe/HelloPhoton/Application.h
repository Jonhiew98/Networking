#pragma once

#ifndef _APPLICATION_

#include <GLFW/glfw3.h>
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <windows.h>
#include "Sprite.h"
#include "GameObject.h"
#include "vector.h"
#include "TicTacToe.h"

class Application
{
private:
	Sprite* m_dummySprite;
	GameObject* m_dummyObject;
	TicTacToe* tictactoe;

public:
	void Start();
	void Update(float xPos,float yPos);
	void Draw();
};

#endif
