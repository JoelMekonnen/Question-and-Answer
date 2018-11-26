#include <iostream>
#include <stdlib.h>
#include <cctype>
#include <fstream>
#include <windows.h>
#include <ctime>
#include <string>
#include <vector>
#include "lib.hpp"
using namespace std;
void singlePlayer()
{
    string usr_name;
	cout << "----------player1 name:";
	cin.ignore();
	getline(cin, usr_name);
	QuestionDb *NewUser = new QuestionDb(usr_name);
	int i = 0;
    while( i <= NewUser->QueSize)
	{
		NewUser->show_Question();
		i++;
	}
}
void multiPlayer()
{

}
void programLogic()
{
	int choice;
	// this is the program Logic that glues everything together
	// first lets create another .cpp that handles the process of Question Adding 
    cout << "-----------QandA trivia-----------\n";
    cout << "| Welcome to QandA trivia        |\n";
	cout << "| Choose the Game Mode           |\n";
	cout << "|     1) Single Player Mode      |\n";
	cout << "|     2) Multiplayer Mode        |\n";
	cout << "| choice:"; 
	cin >> choice; 
    switch (choice)
	{
       case 1:
	      singlePlayer();
		  break;
	   case 2:
	      multiPlayer();
		  break;
	}

}

int main()
{
	programLogic();
	system("pause");
}

