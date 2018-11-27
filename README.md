# Question-and-Answer
A question and answer program 

this program contains all forms of question such as fill in the blank and also choose
----> this file contains three Class. In the lib.hpp file there are two class.
       -> the QuestionDb class contains methods that are used for adding questions into the game
	   -> this classes are used in the addQuestion.cpp the addQuestion.cpp file therefore when compiled is the game database manager
	   -> the second class is the multiple choice class this is its own class because it needs extensive methods to add as well as to dispay the 
	      choices. note to access this options is also added to the addQuestion.cpp although the class is built the show_Question method in .hpp file has not
		  been implemented in any of the cpp file. so you simply call this Method and the rest will take care of itself
	   -> any part of this program can be modified and see the effect. this for Educational purpose and not commercial purpose
-----> the GameLogic class simply handles simple game logic such as adding life and decreasing life as well as creating multiple users
-----> this class is not implemented directly but rather its is used with QuestionDb and also multiple choice question.

