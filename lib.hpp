#pragma once
#include <iostream>
#include <stdlib.h>
#include <cctype>
#include <fstream>
#include <windows.h>
#include <ctime>
#include <string>
#include <vector>
#include "GameLogic.hpp"
using namespace std;
struct File{
    ofstream output;  // the output
    ifstream input;  // the input
};
class QuestionDb :GameLogic
{
	// this is the question database
	// this simply adds a question to the file
protected:
	string Question; // takes the question input
	string Answer;
	// string user;
	int score = 0;
public:
	QuestionDb(string playersName) :GameLogic(playersName)
	{
		// Initate a new user and show them the current stats
		this->ShowStatus(); // this show the status of the user
	}
protected:

	void AddQuestion(int run) {
		// Before Adding question we need to know number of question in the database
		File NewFile;
		// the instance of the structure
		cin.ignore();
		NewFile.input.open("QuesDb.txt", ios::app | ios::in);
		NewFile.output.open("QuesDb.txt", ios::app | ios::out);
		vector<string> SizeVec;
		while (!NewFile.input.eof()) {
			string buffer;
			getline(NewFile.input, buffer);
			SizeVec.push_back(buffer);
		}
		int Quesnum = SizeVec.size();
		for (int r = 0; r < run; r++)
		{
			cout << "please insert the question:";
			cin.ignore(0);
			getline(cin, Question);
			NewFile.output << Quesnum + r << "] " << Question << endl;
			// add answer
			addAnswer(Quesnum + r);
		}
	}
	void showQuestion()
	{
		int i = 0;
		while(this->CheckLife() && i < this->QueSize()){
		try {
			int showQues; // to add randomness to the project
			File NewFile;
			NewFile.input.open("QuesDb.txt", ios::app | ios::in);
			vector<string> SizeVec;
			while (!NewFile.input.eof()) {
				string buffer;
				getline(NewFile.input, buffer);
				SizeVec.push_back(buffer);
			}
			int Quesnum = SizeVec.size();
			if (Quesnum == 0)
			{
				cout << "the work file is currently is empty please try again latter\n";
			}
			else {
			MoveUp:
			    srand(time(NULL));
				showQues = rand() % (Quesnum - 1);
				cout << showQues <<  "|" << Quesnum <<endl;
				if((showQues < 0) && (showQues > Quesnum) && this->playedQuestion(Quesnum))
				{
                    goto MoveUp;
				}
				 else {
                    cout << SizeVec[showQues] << endl;
					i++;
				 }
				bool isAvailable;
				// lets loop through the vector that tells us where the question is played

				// now lets ask the user for an Answer
				this->playedQuestion(showQues); // this adds the question to the list of played question
				string Answer; // this is the answer string
				cin.ignore(0);
				cout << "ans:";
				getline(cin, Answer); // this accepts the Answer
				//-----------------------------
				File answer_file;
				answer_file.input.open("answer.txt", ios::app | ios::in);
				vector<string> AnsVec;
				while (!answer_file.input.eof()) {
					string buffer;
					getline(answer_file.input, buffer);
					AnsVec.push_back(buffer);
				}
				// now check if the answer is correct
				string correct_answer;
				if (Quesnum < 9)
				{
					correct_answer = AnsVec[showQues].substr(3, 100);
				}
				else if (Quesnum < 99 && Quesnum > 9)
				{
					correct_answer = AnsVec[showQues].substr(4, 100);
				}
				else
				{
					correct_answer = AnsVec[showQues].substr(5, 100);
				}
				// then lets make sure the user know they are wrong or right
				if (Answer == correct_answer)
				{
					wcout << "correct Answer......" << endl;
					this->AddScore();
					this->ShowStatus();
				}
				else {
					wcout << "wrong answer......" << endl;
					this->DecreaseLife();
					this->ShowStatus();
				}
			} /*else if((isAvailable) && this->CheckLife()){
				  goto MoveUp;
				}*/
		}
		catch (exception e)
		{
			cout << "something went wrong....\n" << endl;
		}
	  }
	}
	void addAnswer(int quesnum)
	{
		cout << "Ans:";
		cin.ignore(0);
		cin.clear();
		getline(cin, Answer);
		File NewFile; // create a new file
		NewFile.output.open("answer.txt", ios::app | ios::in);
		NewFile.output << quesnum << "] " << Answer << endl;
	}
   public:
    int QueSize()
    {
         File NewFile;
         NewFile.input.open("QuesDb.txt", ios::app|ios::in);
		 vector<string> SizeVec;
		 while (!NewFile.input.eof()) {
			string buffer;
			getline(NewFile.input, buffer);
			SizeVec.push_back(buffer);
		}
        int Quesnum = SizeVec.size();
        return Quesnum;
    }
    void add_Question(int run)
    {
       AddQuestion(run);
    }
    void show_Question()
    {
       showQuestion();
    }


};
class MultipleQuestion {
      // implementing inheritance
    public:
        string Choices[4];  // create the multiple
        string answer;
        string Question;
    private: void AddQuestion(int n)
      {
          // first lets create a multiple question format for adding Questions
          File multiFile;
          multiFile.input.open("multQues.txt", ios::app|ios::in);
          multiFile.output.open("multQues.txt", ios::app|ios::out);
		  int Size;
		  vector<string> SizeVec;
		  while (!multiFile.input.eof()) {
			  string buffer;
			  getline(multiFile.input, buffer);
			  SizeVec.push_back(buffer);
		  }
		  Size = SizeVec.size();
          cin.ignore();
		  cin.clear();
          for(int i = 1; i <= n; i++)
          {
             cin.ignore(0);
             cout << "please insert the Question: ";
             getline(cin, Question);
             multiFile.output <<  (Size + i) - 1 << "] " << Question << endl;
             add_multi_answer((Size + i) - 1);
          }
      }
      void add_multi_answer(int QuesNum)
      {
        // here we add the multiple choices as well as the answer to the multiple choices
        File multiFile;
        File multiFile_Ans;
        multiFile.output.open("multQues_Ans.txt", ios::app|ios::out);
        multiFile_Ans.output.open("Ans_multi.txt", ios::app|ios::out);
        cin.ignore(0);
        cout << "Insert A:";
        getline(cin, Choices[0]);
        cout << "Insert B:";
        getline(cin, Choices[1]);
        cout << "Insert C:";
        getline(cin, Choices[2]);
        cout << "Insert D:";
        getline(cin, Choices[3]);
        cout << "Ans: ";
        getline(cin, answer);
        multiFile.output  << QuesNum << "] ---A]" << Choices[0] << "---B]" << Choices[1]
            << "---C]" << Choices[2] << "---D]" << Choices[3] << "---" << endl;
        multiFile_Ans.output << QuesNum << "]" << answer << endl;
      }
      void show_multi_Question()
      {
        // this is multiple question viewer progrm that displays the questions
        // first lets build lets get the file size and also the vector
        try {
        File multiFile;
        File ans_file;
        multiFile.input.open("multQues.txt", ios::app|ios::in);
        ans_file.input.open("multQues_Ans.txt", ios::app|ios::in);
        //cout << "-------lets stop here for a moment-------" << endl;
		vector<string> QuesVec;
		while (!multiFile.input.eof()) {
			string buffer;
			getline(multiFile.input, buffer);
			QuesVec.push_back(buffer);
		}
        int size = QuesVec.size();
        srand(time(NULL));
        // cout << size << endl;
        int Quesnum = rand() % (size - 1);
        cout << QuesVec[Quesnum] << endl;
		vector<string> AnsVec;
		while (!ans_file.input.eof()) {
			string buffer;
			getline(ans_file.input, buffer);
			AnsVec.push_back(buffer);
		}
        string choiceString = AnsVec[Quesnum].substr(3, 100);
        // now that we have the answer it is best to send this to be decoded to another function
        decode_Answer(choiceString, Quesnum);
        // lets first Check if the vector has properly built by using random number
        } catch(exception e)
        {
            cerr << "something went wrong try again" << endl;
        }
      }
      void decode_Answer(string ans_string, int Quesnum)
      {
         string ans; // this is the property that takes the answer
         string delim = "---";
         size_t pos = 0;
         vector<string> choiceVec;
         while((pos = ans_string.find(delim)) != string::npos)
         {
             string token = ans_string.substr(0, pos);
             choiceVec.push_back(token);
             ans_string.erase(0, pos + delim.length());
         }
         for(int i = 0; i < choiceVec.size(); i++)
         {
             cout << choiceVec[i] << endl;
         }
         File multiFile_Ans;
         vector<string> multiVec;
         multiFile_Ans.input.open("Ans_multi.txt", ios::app|ios::in);
         while(!multiFile_Ans.input.eof())
         {
             string buffer;
             getline(multiFile_Ans.input, buffer);
             multiVec.push_back(buffer);
         }
         string Corr_Ans = multiVec[Quesnum].substr(2, 100);
         //cout << Corr_Ans << endl;
         string _ans;
         cout << "Ans:";
         cin >> _ans;
         if(_ans == Corr_Ans)
         {
             cout << "Correct......." << endl;
             
         } 
         else {
             cout << "Wrong----------" << endl;
         }
      }
    public: void add_Question(int n)
    {
       AddQuestion(n);
    }
   void show_Question()
    {
       show_multi_Question();
    }
};
