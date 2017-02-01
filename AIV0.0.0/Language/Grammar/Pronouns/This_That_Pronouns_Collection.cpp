#include "This_That_Pronouns_Collection.h"


This_That_Pronouns_Collection::This_That_Pronouns_Collection() :
	Pronouns_Collection()
{

}

This_That_Pronouns_Collection::~This_That_Pronouns_Collection()
{
	for (unsigned int i = 0; i < this->_thisThatPronounsList.size(); i++)
	{
		delete this->getPronoun(i);
	}
	this->_thisThatPronounsList.clear();
}

void This_That_Pronouns_Collection::init(void)
{
	this->addPronoun(new This_That_Pronouns("THIS", false, false));
	this->addPronoun(new This_That_Pronouns("THESE", true, false));
	this->addPronoun(new This_That_Pronouns("THAT", false, true));
	this->addPronoun(new This_That_Pronouns("THOSE", true, true));
}

void This_That_Pronouns_Collection::addPronoun(This_That_Pronouns* r)
{
	this->_thisThatPronounsList.push_back(r);
}

This_That_Pronouns* This_That_Pronouns_Collection::getPronoun(std::string name)
{
	This_That_Pronouns* a = NULL;
	for (unsigned int i = 0; i < this->_thisThatPronounsList.size(); i++)
	{
		if (this->getPronoun(i)->getName() == name)
		{
			a = this->getPronoun(i);
		}
	}
	return a;
}
This_That_Pronouns* This_That_Pronouns_Collection::getPronoun(int index)
{
	This_That_Pronouns* a = NULL;
	a = this->_thisThatPronounsList.at(index);
	return a;
}