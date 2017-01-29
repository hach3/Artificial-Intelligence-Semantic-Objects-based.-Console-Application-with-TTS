#include "personnal.h"

Personnal_Pronoun::Personnal_Pronoun()
{
	this->init();
}
Personnal_Pronoun::~Personnal_Pronoun()
{
	this->_personnalPronounsList.clear();
}
void Personnal_Pronoun::init()
{
	this->addPersonnal("I", 1, false, true);
	this->addPersonnal("ME", 1, true, false);

	this->addPersonnal("YOU", 1, false, true);
	this->addPersonnal("YOU", 1, true, false);

	this->addPersonnal("HE", 1, false, true);
	this->addPersonnal("HIM", 1, true, false);

	this->addPersonnal("WE", 1, false, true);
	this->addPersonnal("US", 1, true, false);

	this->addPersonnal("YOU", 1, false, true);
	this->addPersonnal("YOU", 1, true, false);

	this->addPersonnal("THEY", 1, false, true);
	this->addPersonnal("THEM", 1, true, false);


}

bool Personnal_Pronoun::isPersonnal(std::string word)
{
	bool found = false;
	for (unsigned int i = 0; i < this->_personnalPronounsList.size(); i++)
	{
		if (this->_personnalPronounsList.at(i).pronoun == word || this->_personnalPronounsList.at(i).pluralForm == word)
		{
			found = true;
			break;
		}

	}
	return found;
}


void Personnal_Pronoun::addPersonnal(std::string pronoun)
{
	PERSONNAL_PRONOUN personnalPronoun;
	personnalPronoun.pronoun = pronoun;
	this->_personnalPronounsList.push_back(personnalPronoun);
}
void Personnal_Pronoun::addPersonnal(std::string pronoun, int person)
{
	PERSONNAL_PRONOUN personnalPronoun;
	personnalPronoun.pronoun = pronoun;
	personnalPronoun.person = person;
	this->_personnalPronounsList.push_back(personnalPronoun);
}
void Personnal_Pronoun::addPersonnal(std::string pronoun, std::string pluralForm, int person)
{
	PERSONNAL_PRONOUN personnalPronoun;
	personnalPronoun.pronoun = pronoun;
	personnalPronoun.pluralForm = pluralForm;
	personnalPronoun.person = person;
	this->_personnalPronounsList.push_back(personnalPronoun);
}

void Personnal_Pronoun::addPersonnal(std::string pronoun, bool isObject, bool isSubject)
{
	PERSONNAL_PRONOUN personnalPronoun;
	personnalPronoun.pronoun = pronoun;
	personnalPronoun.isObject = isObject;
	personnalPronoun.isSubject = isSubject;
	this->_personnalPronounsList.push_back(personnalPronoun);
}
void Personnal_Pronoun::addPersonnal(std::string pronoun, std::string pluralForm, bool isObject, bool isSubject)
{
	PERSONNAL_PRONOUN personnalPronoun;
	personnalPronoun.pronoun = pronoun;
	personnalPronoun.pluralForm = pluralForm;
	personnalPronoun.isObject = isObject;
	personnalPronoun.isSubject = isSubject;
	this->_personnalPronounsList.push_back(personnalPronoun);
}

void Personnal_Pronoun::addPersonnal(std::string pronoun, int person, bool isObject, bool isSubject)
{
	PERSONNAL_PRONOUN personnalPronoun;
	personnalPronoun.pronoun = pronoun;
	personnalPronoun.person = person;
	personnalPronoun.isObject = isObject;
	personnalPronoun.isSubject = isSubject;
	this->_personnalPronounsList.push_back(personnalPronoun);
}
void Personnal_Pronoun::addPersonnal(std::string pronoun, std::string pluralForm, int person, bool isObject, bool isSubject)
{
	PERSONNAL_PRONOUN personnalPronoun;
	personnalPronoun.pronoun = pronoun;
	personnalPronoun.pluralForm = pluralForm;
	personnalPronoun.person = person;
	personnalPronoun.isObject = isObject;
	personnalPronoun.isSubject = isSubject;
	this->_personnalPronounsList.push_back(personnalPronoun);
}

bool Personnal_Pronoun::isPlural(std::string pronoun)
{
	bool found = false;
	bool isPlural = false;
	for (unsigned int i = 0; i < this->_personnalPronounsList.size(); i++)
	{
		if (this->_personnalPronounsList.at(i).pluralForm == pronoun)
		{
			found = true;
			isPlural = true;
			break;
		}
	}
	return isPlural;
}

std::string Personnal_Pronoun::getPersonnal(bool isPlural, int person, bool isObject, bool isSubject)
{
	bool found = false;
	std::string personnalAtPerson;
	for (unsigned int i = 0; i < this->_personnalPronounsList.size(); i++)
	{
		if (isPlural == true)
		{
			if (this->_personnalPronounsList.at(i).pluralForm != "" &&
				this->_personnalPronounsList.at(i).person == person &&
				this->_personnalPronounsList.at(i).isObject == isObject &&
				this->_personnalPronounsList.at(i).isSubject == isSubject)
			{
				personnalAtPerson = this->_personnalPronounsList.at(i).pluralForm;
				break;
			}
		}
		else {
			if (this->_personnalPronounsList.at(i).pronoun != "" &&
				this->_personnalPronounsList.at(i).person == person &&
				this->_personnalPronounsList.at(i).isObject == isObject &&
				this->_personnalPronounsList.at(i).isSubject == isSubject)
			{
				personnalAtPerson = this->_personnalPronounsList.at(i).pronoun;
				break;
			}
		}
		
	}
	return personnalAtPerson;
}

bool Personnal_Pronoun::isObject(std::string pronoun)
{
	bool found = false;
	bool isObject;
	for (unsigned int i = 0; i < this->_personnalPronounsList.size(); i++)
	{
		if (this->_personnalPronounsList.at(i).pronoun == pronoun || this->_personnalPronounsList.at(i).pluralForm == pronoun)
		{
			isObject = this->_personnalPronounsList.at(i).isObject;
			found = true;
			break;
		}
	}
	return isObject;
}
bool Personnal_Pronoun::isSubject(std::string pronoun)
{
	bool found = false;
	bool isSubject;
	for (unsigned int i = 0; i < this->_personnalPronounsList.size(); i++)
	{
		if (this->_personnalPronounsList.at(i).pronoun == pronoun || this->_personnalPronounsList.at(i).pluralForm == pronoun)
		{
			isSubject = this->_personnalPronounsList.at(i).isSubject;
			found = true;
			break;
		}
	}
	return isSubject;
}