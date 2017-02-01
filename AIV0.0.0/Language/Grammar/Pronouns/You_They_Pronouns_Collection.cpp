#include "You_They_Pronouns_Collection.h"

You_They_Pronouns_Collection::You_They_Pronouns_Collection() :
	Pronouns_Collection()
{

}

You_They_Pronouns_Collection::~You_They_Pronouns_Collection()
{
	for (unsigned int i = 0; i < this->_youTheyPronounsList.size(); i++)
	{
		delete this->getPronoun(i);
	}
	this->_youTheyPronounsList.clear();
}

void You_They_Pronouns_Collection::init(void)
{
	this->addPronoun(new You_They_Pronouns("YOU"));
	this->addPronoun(new You_They_Pronouns("THEY"));
}

void You_They_Pronouns_Collection::addPronoun(You_They_Pronouns* r)
{
	this->_youTheyPronounsList.push_back(r);
}

You_They_Pronouns* You_They_Pronouns_Collection::getPronoun(std::string name)
{
	You_They_Pronouns* a = NULL;
	for (unsigned int i = 0; i < this->_youTheyPronounsList.size(); i++)
	{
		if (this->getPronoun(i)->getName() == name)
		{
			a = this->getPronoun(i);
		}
	}
	return a;
}
You_They_Pronouns* You_They_Pronouns_Collection::getPronoun(int index)
{
	You_They_Pronouns* a = NULL;
	a = this->_youTheyPronounsList.at(index);
	return a;
}
