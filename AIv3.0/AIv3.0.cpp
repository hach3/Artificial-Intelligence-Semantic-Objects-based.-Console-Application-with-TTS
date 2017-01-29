// AIv3.0.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "AI/ai.h"

int main()
{
	AI bot1;
	std::string userSentence;
	bool keepLooping = true;
	std::cout << "AI is waiting for a talk..." << std::endl;
	while (keepLooping)
	{

		userSentence = "";

		std::getline(std::cin, userSentence);

		
		/*
		the user sentence is in userSentence variable
		We now have to call for the ai with this sentence and that'll start its behavior
		*/
		userSentence = bot1.putToUpperCase(userSentence);
		bot1.understandSentence(userSentence);

		userSentence = "";
	}
    return 0;
}

