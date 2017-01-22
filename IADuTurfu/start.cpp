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
	std::cout << "Tariq is waiting for a friend..." << std::endl;
	while (keepLooping)
	{		
		userSentence = "";

		std::getline(std::cin, userSentence);
		/*
		the user sentence is in userSentence variable
		We now have to call for the ai with this sentence and that'll start its behavior

		*/
		bot1.startBehavior(userSentence);

		userSentence = "";		
	}
	
	
}