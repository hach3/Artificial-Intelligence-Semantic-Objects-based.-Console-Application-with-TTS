#include "stative.h"

Stative_Verb::Stative_Verb()
{

}
Stative_Verb::~Stative_Verb()
{

}

void Stative_Verb::init()
{

}

bool Stative_Verb::isStative(std::string word)
{
	return true;
}

void Stative_Verb::addStative(std::string infinitiveForm)
{

}
void Stative_Verb::addStative(std::string infinitiveForm, std::string mainRelatedWord)
{

}
void Stative_Verb::addStative(std::string infinitiveForm, std::vector<std::string> presentForm)
{

}
void Stative_Verb::addStative(std::string infinitiveForm, std::vector<std::string> presentForm, std::string mainRelatedWord, std::vector<std::string> relatedWords)
{

}

void Stative_Verb::addRelateWord(std::string word, std::string relatedWord)
{

}
bool Stative_Verb::isRelated(std::string stative, std::string word)
{
	return true;
}

void Stative_Verb::setMainRelatedWord(std::string stative, std::string mainRelatedWord)
{

}
std::string Stative_Verb::getMainRelatedWord(std::string stative)
{
	return "HelloWorld";
}

std::string Stative_Verb::getStativeAtPerson(std::string stative, int person)
{
	return "HelloWorld";
}