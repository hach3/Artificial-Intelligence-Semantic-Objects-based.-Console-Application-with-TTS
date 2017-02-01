#include "personnal_Pronouns_Collection.h"

Personnal_Pronouns_Collection::Personnal_Pronouns_Collection() :
	Pronouns_Collection()
{

}
Personnal_Pronouns_Collection::~Personnal_Pronouns_Collection()
{
	for (unsigned int i = 0; i < this->_personnalPronounList.size(); i++)
	{
		delete this->getPronoun(i);
	}
	this->_personnalPronounList.clear();
}

void Personnal_Pronouns_Collection::init(void)
{
	this->addPronoun(new Personnal_Pronouns("I", true, false, false, 1));
	this->addPronoun(new Personnal_Pronouns("YOU", true, false, false, 2));
	this->addPronoun(new Personnal_Pronouns("HE", true, false, false, 3));
	this->addPronoun(new Personnal_Pronouns("SHE", true, false, false, 3));
	this->addPronoun(new Personnal_Pronouns("IT", true, false, false, 3));

	this->addPronoun(new Personnal_Pronouns("WE", true, false, true, 1));
	this->addPronoun(new Personnal_Pronouns("YOU", true, false, true, 2));
	this->addPronoun(new Personnal_Pronouns("THEY", true, false, true, 3));


	this->addPronoun(new Personnal_Pronouns("ME", false, true, false, 1));
	this->addPronoun(new Personnal_Pronouns("YOU", false, true, false, 2));
	this->addPronoun(new Personnal_Pronouns("HIM", false, true, false, 3));
	this->addPronoun(new Personnal_Pronouns("HER", false, true, false, 3));
	this->addPronoun(new Personnal_Pronouns("IT", false, true, false, 3));

	this->addPronoun(new Personnal_Pronouns("US", false, true, true, 1));
	this->addPronoun(new Personnal_Pronouns("YOU", false, true, true, 2));
	this->addPronoun(new Personnal_Pronouns("THEM", false, true, true, 3));
}


void Personnal_Pronouns_Collection::addPronoun(Personnal_Pronouns* ab)
{
	this->_personnalPronounList.push_back(ab);
}

Personnal_Pronouns* Personnal_Pronouns_Collection::getPronoun(std::string name)
{
	Personnal_Pronouns* a = NULL;
	for (unsigned int i = 0; i < this->_personnalPronounList.size(); i++)
	{
		if (this->getPronoun(i)->getName() == name)
		{
			a = this->getPronoun(i);
		}
	}
	return a;
}
Personnal_Pronouns* Personnal_Pronouns_Collection::getPronoun(int index)
{
	Personnal_Pronouns* a = NULL;
	a = this->_personnalPronounList.at(index);
	return a;
}
