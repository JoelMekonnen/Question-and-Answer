#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <windows.h>
#include <ctime>
#include <string>
#include <vector>
#include "lib.hpp"
using namespace std;


int main()
{
    QuestionDb *ques = new QuestionDb();
    ques->AddQuestion();
    
    system("pause");
}