#include "reciprocal_Pronouns_Collection.h"

Reciprocal_Pronouns_Collection::Reciprocal_Pronouns_Collection() :
	Pronouns_Collection()
{
	this->init();
}
Reciprocal_Pronouns_Collection::~Reciprocal_Pronouns_Collection()
{
	for (unsigned int i = 0; i < this->_reciprocalPronounsList.size(); i++)
	{
		delete this->getPronoun(i);
	}
	this->_reciprocalPronounsList.clear();
}

void Reciprocal_Pronouns_Collection::init(void)
{
	this->addPronoun(new Reciprocal_Pronouns("EACH OTHER"));
	this->addPronoun(new Reciprocal_Pronouns("ONE ANOTHER"));
}

void Reciprocal_Pronouns_Collection::addPronoun(Reciprocal_Pronouns* s)
{
	this->_reciprocalPronounsList.push_back(s);
}

Reciprocal_Pronouns* Reciprocal_Pronouns_Collection::getPronoun(std::string name)
{
	Reciprocal_Pronouns* a = NULL;
	for (unsigned int i = 0; i < this->_reciprocalPronounsList.size(); i++)
	{
		if (this->getPronoun(i)->getName() == name)
		{
			a = this->getPronoun(i);
		}
	}
	return a;
}
Reciprocal_Pronouns* Reciprocal_Pronouns_Collection::getPronoun(int index)
{
	Reciprocal_Pronouns* a = NULL;
	a = this->_reciprocalPronounsList.at(index);
	return a;
}

