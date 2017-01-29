#include "modal.h"


Modal_Verb::Modal_Verb()
{

}
Modal_Verb::~Modal_Verb()
{

}

void Modal_Verb::init()
{

}

bool Modal_Verb::isModal(std::string word)
{
	return true;
}

void Modal_Verb::addModal(std::string infinitiveForm)
{

}
void Modal_Verb::addModal(std::string infinitiveForm, std::string conceptOfModal)
{

}
void Modal_Verb::addModal(std::string infinitiveForm, std::vector<std::string> presentForm)
{

}

void Modal_Verb::addRelateWord(std::string word, std::string relatedWord)
{

}
bool Modal_Verb::isRelated(std::string modal, std::string word)
{
	return true;
}

bool Modal_Verb::isConceptOfModal(std::string modal, std::string conceptOf)
{
	return true;
}

std::string Modal_Verb::getModalAtPerson(std::string modal, int person)
{
	return "HelloWorld";
}