#pragma once
using namespace std;
struct File{
    ofstream output;  // the output
    ifstream input;  // the input
};
int GetSize(ifstream i)
{
  int NumOfQues = 0; // the variable to hold the number of question
  vector<string> SizeVec;
  while(!i.eof()){
       string buffer;
       getline(i, buffer);
       SizeVec.push_back(buffer);
   }
   NumOfQues = SizeVec.size();
   return NumOfQues;
}
vector<string> buildVec(ifstream i)
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
        else if(GetSize(NewFile.input) < 20 && GetSize(NewFile.input) > 9))
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
        string Answer[4];  // create the multiple
        string answer;
        string Question;
    private: void AddQuestion()
      {
          // first lets create a multiple question format for adding Questions
          File multiFile;
          multiFile.input.open("multQues.txt", ios::app|ios::in);
          multiFile.output.open("multQues.txt", ios::app|ios::out);
          cout << "Please insert the amount of time to run the program:";
          int n; cin>>n;
          for(int i = 0; i < n; i++)
          {
             cout << "Ques no " << i << ": ";
             getline(cin, Question);
             multiFile.output << GetSize(multiFile.input) << "] " << Question << endl;
          }
      }
    public: void add_Question()
    {
       AddQuestion();
    }
};
