#include "reflexive_Pronouns_Collection.h"

Reflexive_Pronouns_Collection::Reflexive_Pronouns_Collection() :
	Pronouns_Collection()
{

}

Reflexive_Pronouns_Collection::~Reflexive_Pronouns_Collection()
{
	for (unsigned int i = 0; i < this->_reflexivePronounsList.size(); i++)
	{
		delete this->getPronoun(i);
	}
	this->_reflexivePronounsList.clear();
}

void Reflexive_Pronouns_Collection::init(void)
{
	this->addPronoun(new Reflexive_Pronouns("MYSELF", false, 1));
	this->addPronoun(new Reflexive_Pronouns("YOURSELF", false, 2));
	this->addPronoun(new Reflexive_Pronouns("HIMSELF", false, 3));
	this->addPronoun(new Reflexive_Pronouns("HERSELF", false, 3));
	this->addPronoun(new Reflexive_Pronouns("ITSELF", false, 3));

	this->addPronoun(new Reflexive_Pronouns("OURSELVES", true, 1));
	this->addPronoun(new Reflexive_Pronouns("YOURSELVES", true, 2));
	this->addPronoun(new Reflexive_Pronouns("THEMSELVES", true, 3));
}

void Reflexive_Pronouns_Collection::addPronoun(Reflexive_Pronouns* r)
{
	this->_reflexivePronounsList.push_back(r);
}

Reflexive_Pronouns* Reflexive_Pronouns_Collection::getPronoun(std::string name)
{
	Reflexive_Pronouns* a = NULL;
	for (unsigned int i = 0; i < this->_reflexivePronounsList.size(); i++)
	{
		if (this->getPronoun(i)->getName() == name)
		{
			a = this->getPronoun(i);
		}
	}
	return a;
}
Reflexive_Pronouns* Reflexive_Pronouns_Collection::getPronoun(int index)
{
	Reflexive_Pronouns* a = NULL;
	a = this->_reflexivePronounsList.at(index);
	return a;
}
