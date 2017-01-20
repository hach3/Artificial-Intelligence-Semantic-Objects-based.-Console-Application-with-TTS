#include "start.h"
#include <iostream>
#include <string>
#include "tariq.h"
/*
Main Loop of the AI

*/
Start::Start()
{

	this->loop();
}
Start::~Start()
{

}

void Start::loop()
{
	std::string userSentence;
	Tariq bot1;
	bool keepLooping = true;

	while (keepLooping)
	{
		
		userSentence = "";

		std::cin >> userSentence;
		
		bot1.startBehavior(userSentence);
	

		std::cin.ignore();

		userSentence = "";
		
	}
	
	/*
	the user sentence is in userSentence variable
	We now have to call for the ai with this sentence and that'll start its behavior

	*/
}