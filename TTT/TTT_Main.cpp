#include <iostream>
#include "TTT.h"

using namespace std;

int main()
{
	TTT ob;
	do
	{
		cout << "Player " << ob.getCurrentPlayer() << ", enter a number:  ";
		int choice;
		cin >> choice;
		ob.play(choice);

		if(ob.getResult() == INVALIDMOVE)
		{
			cout << "Invalid Move!!" << endl;
			cin.ignore();
		}
	}while(ob.getResult() != WIN);
	
	if(ob.getResult() == WIN)
	{
		cout<<"==>\aPlayer "<<ob.getCurrentPlayer()<<" wins " << endl;
	}
	else
	{
		cout<<"==>\aGame draw" << endl;
	}
	return EXIT_SUCCESS;
}