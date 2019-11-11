#include <iostream>
#include "Application.h"

using namespace std;

void Application::Start()
{
	cout << "Application is started" << endl;
	//sprite
	//m_dummySprite = new Sprite("../Media/TicTacToe.bmp");
	//
	////gameObject
	//m_dummyObject = new GameObject(m_dummySprite);
	//m_dummyObject->SetPos(Vector(400, 300, 0));
	////m_dummyObject->SetRotation(0.0f);
	//m_dummyObject->SetScale(0.3f);

	//initialize TicTacToe
	tictactoe = new TicTacToe();
	tictactoe->InitializeBoard();

}

void Application::Update(float xPos, float yPos)
{

}

void Application::Draw()
{
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	////Sprite
	//m_dummySprite->Draw(540, 360, 0.0f, 0.5f, Color(1.0f, 1.0f, 1.0f));

	////GameObject
	//m_dummyObject->draw();

	//Draw TicTacToe
	tictactoe-> DrawTicTacToe();
	tictactoe->CheckCondition();
	tictactoe->UpdateXO();
}
