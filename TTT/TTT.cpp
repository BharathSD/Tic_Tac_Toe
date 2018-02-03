#include "TTT.h"

using namespace std;
TTT::TTT(void):m_currentPlayer(1)
{
	int i(0);
	for(char itr('0'); itr <= '9'; itr++)
		m_square[i++]=itr;
	drawBoard();
}


TTT::~TTT(void)
{
}

void TTT::drawBoard()
{
	system("cls");
	cout << "\n\n\tTic Tac Toe\n\n";

	cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
	cout << endl;

	cout << "     |     |     " << endl;
	cout << "  " << m_square[1] << "  |  " << m_square[2] << "  |  " << m_square[3] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << m_square[4] << "  |  " << m_square[5] << "  |  " << m_square[6] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << m_square[7] << "  |  " << m_square[8] << "  |  " << m_square[9] << endl;

	cout << "     |     |     " << endl << endl;
}

void TTT::checkWin()
{
	if (m_square[1] == m_square[2] && m_square[2] == m_square[3])

		m_ResultFlag = WIN;
	else if (m_square[4] == m_square[5] && m_square[5] == m_square[6])

		m_ResultFlag = WIN;
	else if (m_square[7] == m_square[8] && m_square[8] == m_square[9])

		m_ResultFlag = WIN;
	else if (m_square[1] == m_square[4] && m_square[4] == m_square[7])

		m_ResultFlag = WIN;
	else if (m_square[2] == m_square[5] && m_square[5] == m_square[8])

		m_ResultFlag = WIN;
	else if (m_square[3] == m_square[6] && m_square[6] == m_square[9])

		m_ResultFlag = WIN;
	else if (m_square[1] == m_square[5] && m_square[5] == m_square[9])

		m_ResultFlag = WIN;
	else if (m_square[3] == m_square[5] && m_square[5] == m_square[7])

		m_ResultFlag = WIN;
	else if (m_square[1] != '1' && m_square[2] != '2' && m_square[3] != '3' 
                    && m_square[4] != '4' && m_square[5] != '5' && m_square[6] != '6' 
                  && m_square[7] != '7' && m_square[8] != '8' && m_square[9] != '9')

		m_ResultFlag = NORESULT;
	else
		m_ResultFlag = CONTINUE;
}

void TTT::play(int choice)
{
	char mark=(m_currentPlayer == 1) ? 'X' : 'O';

	if (choice == 1 && m_square[1] == '1')

			m_square[1] = mark;
		else if (choice == 2 && m_square[2] == '2')

			m_square[2] = mark;
		else if (choice == 3 && m_square[3] == '3')

			m_square[3] = mark;
		else if (choice == 4 && m_square[4] == '4')

			m_square[4] = mark;
		else if (choice == 5 && m_square[5] == '5')

			m_square[5] = mark;
		else if (choice == 6 && m_square[6] == '6')

			m_square[6] = mark;
		else if (choice == 7 && m_square[7] == '7')

			m_square[7] = mark;
		else if (choice == 8 && m_square[8] == '8')

			m_square[8] = mark;
		else if (choice == 9 && m_square[9] == '9')

			m_square[9] = mark;
		else
		{
			m_ResultFlag = INVALIDMOVE;
			return;
		}
		drawBoard();
		checkWin();
		if(this->m_ResultFlag == CONTINUE)
			changePlayer();
}

void TTT::changePlayer()
{
	m_currentPlayer++;
	m_currentPlayer=(m_currentPlayer%2)?1:2;
}

int TTT::getCurrentPlayer()
{
	return m_currentPlayer;
}

TTTResult TTT::getResult()
{
	return m_ResultFlag;
}