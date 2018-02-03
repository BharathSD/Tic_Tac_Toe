#pragma once
#include<iostream>
enum TTTResult
{
	WIN =1,
	CONTINUE = -1,
	NORESULT=0,
	INVALIDMOVE=-2
};
class TTT
{
public:
	TTT(void);
	~TTT(void);
	void play(int choice);
	int getCurrentPlayer();
	TTTResult getResult();
private:
	char m_square[10];

	TTTResult m_ResultFlag;

	int m_currentPlayer;

	void drawBoard();

	void checkWin();

	void changePlayer();
};

