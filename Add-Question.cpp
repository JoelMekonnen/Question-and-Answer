#include <iostream>
#include <fstream>
#include <vector>
#include "lib.hpp"
#include <stdlib.h>
using namespace std;
/*
    compile this file to add Questions to the Database
*/

void Add_Question()
{
	// lets Control the number of times this program runs
	QuestionDb *NewQues = new QuestionDb("");
	string Choice;
	cout << "|-----------Hello Master Welcome to the Question Database-|" << endl;
	cout << "|------[A]dd Question ------------------------------------|" << endl;
	cout << "|------[M]multiple choice Question -----------------------|" << endl;
	cout << "|------[S]how Question Status ----------------------------|" << endl;
	cout << "|-------------[:";
	cin >> Choice;

	if ((Choice == "A") || (Choice == "a"))
	{
		int num;
		cout << "How many Questions do you want to add:";
		cin  >> num;
        QuestionDb *Question = new QuestionDb("");
		Question->add_Question(num);
	}
	else if ((Choice == "M") || (Choice == "m"))
	{
         int num;
		 cout << "How many Questions do you want to add:";
		 cin  >> num;
		 MultipleQuestion *Multi = new MultipleQuestion();
		 Multi->add_Question(num);
	}
	else if ((Choice == "S") || (Choice == "s"))
	{

	}
	else {
		cout << "please insert from one of the above choices.......\n";
	}
	
}
void Show_Question_Status()
{

}
int main()
{
	Add_Question();
	system("pause");
}