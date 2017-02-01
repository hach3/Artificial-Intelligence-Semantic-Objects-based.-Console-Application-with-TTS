#include "indefinite_Pronouns_Collection.h"

Indefinite_Pronouns_Collection::Indefinite_Pronouns_Collection(void) : 
	Pronouns_Collection()
{

}
Indefinite_Pronouns_Collection::~Indefinite_Pronouns_Collection(void)
{
	for (unsigned int i = 0; i < this->_indefinitePronounsList.size(); i++)
	{
		delete this->getPronoun(i);
	}
	this->_indefinitePronounsList.clear();
}

/* Create the basics indefinite pronouns */
void Indefinite_Pronouns_Collection::init(void)
{
	//Indefinite_Pronouns(std::string indefinitePronouns, bool isPeople, bool isThink, double targetRate, bool canBeUseInNegativeForm);
	this->addPronoun(new Indefinite_Pronouns("SOMEBODY", true, false, 0.1, false));
	this->addPronoun(new Indefinite_Pronouns("SOMEONE", true, false, 0.1, false));
	this->addPronoun(new Indefinite_Pronouns("SOMETHING", false, true, 0.1, false));

	this->addPronoun(new Indefinite_Pronouns("ANYBODY", true, false, 0.5, false));
	this->addPronoun(new Indefinite_Pronouns("ANYONE", true, false, 0.5, false));
	this->addPronoun(new Indefinite_Pronouns("ANYTHING", false, true, 0.5, false));

	this->addPronoun(new Indefinite_Pronouns("NOBODY", true, false, 0.0, true));
	this->addPronoun(new Indefinite_Pronouns("NO ONE", true, false, 0.0, true));
	this->addPronoun(new Indefinite_Pronouns("NOTHING", false, true, 0.0, true));

	this->addPronoun(new Indefinite_Pronouns("EVERYBODY", true, false, 1.0, false));
	this->addPronoun(new Indefinite_Pronouns("EVERYONE", true, false, 1.0, false));
	this->addPronoun(new Indefinite_Pronouns("EVERYTHING", false, true, 1.0, false));
}

/* Add a pronoun in the list */
void Indefinite_Pronouns_Collection::addPronoun(Indefinite_Pronouns* pronoun)
{
	this->_indefinitePronounsList.push_back(pronoun);
}

/* Return the indefinite pronoun */
Indefinite_Pronouns* Indefinite_Pronouns_Collection::getPronoun(std::string pronounName)
{
	Indefinite_Pronouns* p = NULL;
	for (unsigned int i = 0; i < this->_indefinitePronounsList.size(); i++)
	{
		if (this->getPronoun(i)->getName() == pronounName)
		{
			p = this->getPronoun(i);
		}
	}
	return p;
}
Indefinite_Pronouns* Indefinite_Pronouns_Collection::getPronoun(int index)
{
	Indefinite_Pronouns* p = NULL;
	p = this->_indefinitePronounsList.at(index);
	return p;
}
