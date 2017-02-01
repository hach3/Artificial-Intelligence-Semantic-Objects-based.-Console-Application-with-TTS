#include "One_Ones_Pronouns_Collection.h"


One_Ones_Pronouns_Collection::One_Ones_Pronouns_Collection() :
	Pronouns_Collection()
{
	
}
One_Ones_Pronouns_Collection::~One_Ones_Pronouns_Collection()
{
	for (unsigned int i = 0; i < this->_onePronounsList.size(); i++)
	{
		delete this->getPronoun(i);
	}
	this->_onePronounsList.clear();
}

void One_Ones_Pronouns_Collection::init(void)
{
	this->addPronoun(new One_Ones_Pronouns("ONE", false));
	this->addPronoun(new One_Ones_Pronouns("ONES", true));
}

void One_Ones_Pronouns_Collection::addPronoun(One_Ones_Pronouns* pronoun)
{
	this->_onePronounsList.push_back(pronoun);
}

One_Ones_Pronouns* One_Ones_Pronouns_Collection::getPronoun(std::string name)
{
	One_Ones_Pronouns* a = NULL;
	for (unsigned int i = 0; i < this->_onePronounsList.size(); i++)
	{
		if (this->getPronoun(i)->getName() == name)
		{
			a = this->getPronoun(i);
		}
	}
	return a;
}
One_Ones_Pronouns* One_Ones_Pronouns_Collection::getPronoun(int index)
{
	One_Ones_Pronouns* a = NULL;
	a = this->_onePronounsList.at(index);
	return a;
}
