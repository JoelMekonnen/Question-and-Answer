#pragma once
using namespace std;
struct File{
    ofstream output;  // the output
    ifstream input;  // the input
};
class QuestionDb
{
     // this is the question database
     // this simply adds a question to the file
     public:
        string Question; // takes the question input
        string Answer;
        void AddQuestion(){
            // Before Adding question we need to know number of question in the database
             File NewFile; 
            int NumOfQues = 0; // the variable to hold the number of question
            NewFile.input.open("QuesDb.txt", ios::app|ios::in);
            vector<string> SizeVec;
            while(!NewFile.input.eof()){
                 string buffer;
                 getline(NewFile.input, buffer);
                 SizeVec.push_back(buffer);
             }
             NumOfQues = SizeVec.size();
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
                NewFile.output << NumOfQues + r << "] " <<  Question << endl;
                // add answer
                addAnswer(NumOfQues + r);
            }   
        }
    void showQuestion()
    {
        int showQues; // to add randomness to the project
        File NewFile; 
        vector<string> SizeVec;
        NewFile.input.open("QuesDb.txt", ios::app|ios::in);
         while(!NewFile.input.eof()){
                 string buffer;
                 getline(NewFile.input, buffer);
                 SizeVec.push_back(buffer);
             }
        
        srand(time(NULL));
        showQues = 1 + rand() % SizeVec.size();
        cout << SizeVec[showQues] << endl;
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
        
};
