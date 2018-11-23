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
/*
     This Header Handles the Game logic such as looping, 
     Keeping the score Count

     This is suppose to handle multiple things such as multiplayers 
*/
class GameLogic {
        protected:
          string player; // the player variable
          int Score = 0;  // the score of the user
          int Life = 3;  // the life of the user
          vector<int> ListOfQues;
        public:
          GameLogic(string playerName)
          {
              player = playerName;
          }
        protected:
         inline void AddScore()
         {
             Score++;
         }
         public: bool CheckLife()
         {
             if(Life > 0)
             {
                 return true;
             }
             else {
                 return false;
             }
         }
        protected: void DecreaseLife()
         {
             if(CheckLife())
             {
                this->Life--;
             }
             else {
                 cout << "-----Game Over-----" << endl;
             }
             
         }
         bool playedQuestion(int QuesNum)
         {
             bool notAvailable = true;
             for(int i = 0; i <ListOfQues.size(); i++)
             {
                 if(ListOfQues[i] == QuesNum)
                 {
                     notAvailable = false; 
                 }
                 else {
                     notAvailable = true;
                 }
             }
             if(notAvailable)
             {
                  ListOfQues.push_back(QuesNum);
                  return true;
             }
             else {
                 return false;
             }
             
         }
         void ShowStatus()
         {
             cout << "|-------------" << this->player << "-------|" << endl;
             cout << "|   Score:" << this->Score << "            |" << endl;
             cout << "|   Life:" << this->Life << "              |" << endl;
             cout << "|------------------------------------------|" << endl;
         }
};
