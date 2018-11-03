#pragma once
#include <iostream>
#include <stdlib.h>
#include <cctype>
#include <fstream>
#include <windows.h>
#include <ctime>
#include <string>
#include <vector>
using namespace std;
struct File{
    ofstream output;  // the output
    ifstream input;  // the input
};
int GetSize(ifstream &i)
{
  int NumOfQues; // the variable to hold the number of question
  vector<string> SizeVec;
  while(!i.eof()){
       string buffer;
       getline(i, buffer);
       SizeVec.push_back(buffer);
   }
   NumOfQues = SizeVec.size();
   return NumOfQues;
}
vector<string> buildVec(ifstream &i)
{
  vector<string> SizeVec;
  while(!i.eof()){
       string buffer;
       getline(i, buffer);
       SizeVec.push_back(buffer);
   }
   return SizeVec;
}
class QuestionDb
{
     // this is the question database
     // this simply adds a question to the file
   protected:
        string Question; // takes the question input
        string Answer;
        void AddQuestion(){
            // Before Adding question we need to know number of question in the database
             File NewFile;
             int run; // the ammount of times to run the program
             cout << "please inser the ammount of times to run the program....:";
             cin >> run;
            // the instance of the structure
            cin.ignore();
            NewFile.input.open("QuesDb.txt", ios::app|ios::in);
            NewFile.output.open("QuesDb.txt", ios::app|ios::out);
            for(int r = 0; r < run; r++)
            {
                cout << "please insert the question:";
                cin.ignore(0);
                getline(cin, Question);
                NewFile.output << GetSize(NewFile.input) + r << "] " <<  Question << endl;
                // add answer
                addAnswer(GetSize(NewFile.input) + r);
            }
        }
    void showQuestion()
    {
        try {
        int showQues; // to add randomness to the project
        File NewFile;
        srand(time(NULL));
        NewFile.input.open("QuesDb.txt", ios::app|ios::in);
        showQues = rand() % (GetSize(NewFile.input) - 1);
        if(showQues == GetSize(NewFile.input) - 1)
        {
           cout << "Error.......\n";
           throw new exception;
        }
        cout << buildVec(NewFile.input)[showQues] << endl;
        // now lets ask the user for an Answer
        string Answer; // this is the answer string
        cout << "ans:";
        getline(cin, Answer); // this accepts the Answer
        //-----------------------------
        File answer_file;
        answer_file.input.open("answer.txt", ios::app|ios::in);
        vector<string> answer_vec = buildVec(answer_file.input);
        // now check if the answer is correct
        string correct_answer;
        if(GetSize(NewFile.input) < 9)
        {
            correct_answer = answer_vec[showQues].substr(3, 100);
        }
        else if(GetSize(NewFile.input) < 20 && GetSize(NewFile.input) > 9)
        {
            correct_answer = answer_vec[showQues].substr(4, 100);
        }
        else
        {
           correct_answer = answer_vec[showQues].substr(5, 100);
        }
        // then lets make sure the user know they are wrong or right
        if(Answer == correct_answer)
        {
           wcout << "correct Answer......" << endl;
        }
        else {
          wcout << "wrong answer......" << endl;
        }
    } catch(exception e)
    {
      cout << "something went wrong....\n" << endl;
    }
    }
    void addAnswer(int quesnum)
    {
        cout << "Ans:";
        cin.ignore(0);
        cin.clear();
        getline(cin, Answer);
        File NewFile; // create a new file
        NewFile.output.open("answer.txt", ios::app|ios::in);
        NewFile.output << quesnum << "] " << Answer << endl;
    }
   public:
    void add_Question()
    {
       AddQuestion();
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
    private: void AddQuestion()
      {
          // first lets create a multiple question format for adding Questions
          File multiFile;
          cout << "Please insert the amount of time to run the program:";
          int n; cin>>n;
          multiFile.input.open("multQues.txt", ios::app|ios::in);
          multiFile.output.open("multQues.txt", ios::app|ios::out);
          int Size = GetSize(multiFile.input);
          cin.ignore();
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
        multiFile.output.open("multQues_Ans.txt", ios::app|ios::out);
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
        multiFile.output  << QuesNum << "]---A]" << Choices[0] << "---B]" << Choices[1]
            << "---C]" << Choices[2] << "---D]" << Choices[3] << "---" << "Ans:" << answer << endl;
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
        vector<string> QuesVec = buildVec(multiFile.input);
        int size = GetSize(multiFile.input);
        srand(time(NULL));
        cout << size << endl;
        int Quesnum = rand() % (size -1);
        cout << QuesVec[Quesnum] << endl;
        // lets first Check if the vector has properly built by using random number
        } catch(exception e)
        {
            cerr << "something went wrong try again" << endl;
        }
      }
    public: void add_Question()
    {
       AddQuestion();
    }
    void show_Question()
    {
        show_multi_Question();
    }
};
