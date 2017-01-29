#include "phrasal.h"

Phrasal_Verb::Phrasal_Verb()
{

}
Phrasal_Verb::~Phrasal_Verb()
{

}

void Phrasal_Verb::init()
{

}

bool Phrasal_Verb::isPhrasal(std::string word)
{
	return true;
}

void Phrasal_Verb::addPhrasal(std::string infinitiveForm)
{

}
void Phrasal_Verb::addPhrasal(std::string infinitiveForm, std::vector<std::string> presentForm)
{

}

void Phrasal_Verb::addRelateWord(std::string word, std::string relatedWord)
{

}
bool Phrasal_Verb::isRelated(std::string phrasal, std::string word)
{
	return true;
}



std::string Phrasal_Verb::getPhrasalAtPerson(std::string phrasal, int person)
{
	return "HelloWorld";
}