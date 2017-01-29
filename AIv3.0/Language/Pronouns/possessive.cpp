#include "possessive.h"
/*
TODO : add a vector for the 3rd person, it has to content his, hers, its.

*/
Possessive_Pronoun::Possessive_Pronoun()
{
	this->init();
}
Possessive_Pronoun::~Possessive_Pronoun()
{
	this->_possessivePronounsList.clear();
}

void Possessive_Pronoun::init()
{
	//not used before a noun, a possessive adjectives is used before a noun.
	std::vector<std::string> possessive;
	possessive.push_back("MINE");
	possessive.push_back("YOURS");
	possessive.push_back("HIS");
	possessive.push_back("OURS");
	possessive.push_back("YOURS");
	possessive.push_back("THEIRS");
	this->addPossessive(possessive);
}

bool Possessive_Pronoun::isPossessive(std::string word)
{
	bool found = false;
	for (unsigned int i = 0; i < this->_possessivePronounsList.size(); i++)
	{
		for (unsigned int y = 0; y < this->_possessivePronounsList.at(i).possessivePronouns.size(); y++)
		{
			if (this->_possessivePronounsList.at(i).possessivePronouns.at(y) == word)
			{
				found = true;
				break;
			}
		}
		if (found == true)
		{
			break;
		}
	}
	return found;
}

void Possessive_Pronoun::addPossessive(std::vector<std::string> possessivePronoun)
{
	POSSESSIVE_PRONOUN newPossessive;
	newPossessive.name = "";
	newPossessive.possessivePronouns = possessivePronoun;
	this->_possessivePronounsList.push_back(newPossessive);
}
void Possessive_Pronoun::addPossessive(std::string name, std::vector<std::string> possessivePronoun)
{
	POSSESSIVE_PRONOUN newPossessive;
	newPossessive.name = name;
	newPossessive.possessivePronouns = possessivePronoun;
	this->_possessivePronounsList.push_back(newPossessive);
}

std::string Possessive_Pronoun::getPossessiveByPos(std::string word, int person)
{
	bool found = false;
	std::string possessivePronounAtPerson;
	for (unsigned int i = 0; i < this->_possessivePronounsList.size(); i++)
	{
		if (this->_possessivePronounsList.at(i).name == word)
		{
			found = true;
			possessivePronounAtPerson = this->_possessivePronounsList.at(i).possessivePronouns.at(person - 1);
			break;
		}
		for (unsigned int y = 0; y < this->_possessivePronounsList.at(i).possessivePronouns.size(); y++)
		{
			if (this->_possessivePronounsList.at(i).possessivePronouns.at(y) == word)
			{
				found = true;
				possessivePronounAtPerson = this->_possessivePronounsList.at(i).possessivePronouns.at(person - 1);
				break;
			}
		}
		if (found == true)
		{
			break;
		}
	}
	return possessivePronounAtPerson;
}

bool Possessive_Pronoun::isPlural(std::string possessivePronoun)
{
	bool found = false;
	bool isPlural = false;
	std::string possessivePronounAtPerson;
	for (unsigned int i = 0; i < this->_possessivePronounsList.size(); i++)
	{
		for (unsigned int y = 0; y < this->_possessivePronounsList.at(i).possessivePronouns.size(); y++)
		{
			if (this->_possessivePronounsList.at(i).possessivePronouns.at(y) == possessivePronoun)
			{
				found = true;
				if (y >= 3)
				{
					isPlural = true;
				}
				break;
			}
		}
		if (found == true)
		{
			break;
		}
	}
	return isPlural;
}