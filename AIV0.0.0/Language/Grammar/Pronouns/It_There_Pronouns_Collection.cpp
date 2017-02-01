#include "It_There_Pronouns_Collection.h"

It_There_Pronouns_Collection::It_There_Pronouns_Collection() :
	Pronouns_Collection()
{
	
}
It_There_Pronouns_Collection::~It_There_Pronouns_Collection()
{
	for (unsigned int i = 0; i < this->_itTherePronounsList.size(); i++)
	{
		delete this->getPronoun(i);
	}
	this->_itTherePronounsList.clear();
}

void It_There_Pronouns_Collection::init(void)
{
	this->addPronoun(new It_There_Pronouns("IT"));
	this->addPronoun(new It_There_Pronouns("THERE"));
}

void It_There_Pronouns_Collection::addPronoun(It_There_Pronouns* a)
{
	this->_itTherePronounsList.push_back(a);
}

It_There_Pronouns* It_There_Pronouns_Collection::getPronoun(std::string name)
{
	It_There_Pronouns* a = NULL;
	for (unsigned int i = 0; i < this->_itTherePronounsList.size(); i++)
	{
		if (this->getPronoun(i)->getName() == name)
		{
			a = this->getPronoun(i);
		}
	}
	return a;
}
It_There_Pronouns* It_There_Pronouns_Collection::getPronoun(int index)
{
	It_There_Pronouns* a = NULL;
	a = this->_itTherePronounsList.at(index);
	return a;
}
