#include "possessive_Pronouns_Collection.h"

Possessive_Pronouns_Collection::Possessive_Pronouns_Collection()
{
	this->init();
}
Possessive_Pronouns_Collection::~Possessive_Pronouns_Collection()
{
	for (unsigned int i = 0; i < this->_possessivePronounList.size(); i++)
	{
		delete this->getPronoun(i);
	}
	this->_possessivePronounList.clear();
}

void Possessive_Pronouns_Collection::init(void)
{
	this->addPronoun(new Possessive_Pronouns("MINE", false, 1));
	this->addPronoun(new Possessive_Pronouns("YOURS", false, 2));
	this->addPronoun(new Possessive_Pronouns("HIS", false, 3));
	this->addPronoun(new Possessive_Pronouns("HERS", false, 3));
	this->addPronoun(new Possessive_Pronouns("ITS", false, 3));

	this->addPronoun(new Possessive_Pronouns("OURS", true, 1));
	this->addPronoun(new Possessive_Pronouns("YOURS", true, 2));
	this->addPronoun(new Possessive_Pronouns("THEIRS", true, 3));
}


void Possessive_Pronouns_Collection::addPronoun(Possessive_Pronouns* ab)
{
	this->_possessivePronounList.push_back(ab);
}

Possessive_Pronouns* Possessive_Pronouns_Collection::getPronoun(std::string name)
{
	Possessive_Pronouns* a = NULL;
	for (unsigned int i = 0; i < this->_possessivePronounList.size(); i++)
	{
		if (this->getPronoun(i)->getName() == name)
		{
			a = this->getPronoun(i);
		}
	}
	return a;
}
Possessive_Pronouns* Possessive_Pronouns_Collection::getPronoun(int index)
{
	Possessive_Pronouns* a = NULL;
	a = this->_possessivePronounList.at(index);
	return a;
}
