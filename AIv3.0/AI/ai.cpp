#include "ai.h"
#include <algorithm>
#include <iostream>

AI::AI() {

}

AI::~AI()
{

}

void AI::understandSentence(std::string usersentence)
{
	//Si on trouve un wh, qu'il est suivi de l'auxiliaire be, puis un adjectif possessif, puis un nom commun.

}

void AI::saySomething()
{
	std::cout << this->_sentenceToSay << std::endl;
}

std::string AI::putToUpperCase(std::string userSentence)
{
	std::transform(userSentence.begin(), userSentence.end(), userSentence.begin(), toupper);
	return userSentence;
}
std::string AI::putToLowerCase(std::string sentence)
{
	std::transform(sentence.begin(), sentence.end(), sentence.begin(), tolower);
	return sentence;
}