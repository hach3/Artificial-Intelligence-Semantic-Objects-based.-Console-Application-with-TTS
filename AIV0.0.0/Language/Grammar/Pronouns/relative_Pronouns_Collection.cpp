#include "relative_Pronouns_Collection.h"


Relative_Pronouns_Collection::Relative_Pronouns_Collection() :
	Pronouns_Collection()
{

}

Relative_Pronouns_Collection::~Relative_Pronouns_Collection()
{
	for (unsigned int i = 0; i < this->_relativePronounsList.size(); i++)
	{
		delete this->getPronoun(i);
	}
	this->_relativePronounsList.clear();
}

void Relative_Pronouns_Collection::init(void)
{
	this->addPronoun(new Relative_Pronouns("WHO", true, false, false));
	this->addPronoun(new Relative_Pronouns("WHICH", true, false, false));
	this->addPronoun(new Relative_Pronouns("THAT", true, false, false));

	this->addPronoun(new Relative_Pronouns("WHO", false, true, false));
	this->addPronoun(new Relative_Pronouns("WHOM", false, true, false));
	this->addPronoun(new Relative_Pronouns("WHICH", false, true, false));
	this->addPronoun(new Relative_Pronouns("THAT", false, true, false));

	this->addPronoun(new Relative_Pronouns("WHOSE", false, false, true));
	this->addPronoun(new Relative_Pronouns("WHOSE", false, false, true));
}

void Relative_Pronouns_Collection::addPronoun(Relative_Pronouns* r)
{
	this->_relativePronounsList.push_back(r);
}

Relative_Pronouns* Relative_Pronouns_Collection::getPronoun(std::string name)
{
	Relative_Pronouns* a = NULL;
	for (unsigned int i = 0; i < this->_relativePronounsList.size(); i++)
	{
		if (this->getPronoun(i)->getName() == name)
		{
			a = this->getPronoun(i);
		}
	}
	return a;
}
Relative_Pronouns* Relative_Pronouns_Collection::getPronoun(int index)
{
	Relative_Pronouns* a = NULL;
	a = this->_relativePronounsList.at(index);
	return a;
}