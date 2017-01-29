#include "possessiveAdjectives.h"
/*
TODO : add a vector for the 3rd person, it has to content his, hers, its.

*/
Possessive_Adjectives::Possessive_Adjectives()
{
	this->init();
}
Possessive_Adjectives::~Possessive_Adjectives()
{
	this->_possessiveAdjectivesList.clear();
}

void Possessive_Adjectives::init()
{
	//not used before a noun, a possessive adjectives is used before a noun.
	std::vector<std::string> possessive;
	possessive.push_back("MY");
	possessive.push_back("YOUR");
	possessive.push_back("HIS");
	possessive.push_back("OUR");
	possessive.push_back("YOUR");
	possessive.push_back("THEIR");
	this->addPossessive(possessive);
}

bool Possessive_Adjectives::isPossessive(std::string word)
{
	bool found = false;
	for (unsigned int i = 0; i < this->_possessiveAdjectivesList.size(); i++)
	{
		for (unsigned int y = 0; y < this->_possessiveAdjectivesList.at(i).possessiveAdjectives.size(); y++)
		{
			if (this->_possessiveAdjectivesList.at(i).possessiveAdjectives.at(y) == word)
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
bool Possessive_Adjectives::isPossessiveSentence(std::string sentence, std::string &possessiveAdjectif)
{
	bool found = false;
	std::size_t foundPos;

	for (unsigned int i = 0; i < this->_possessiveAdjectivesList.size(); i++)
	{
		for (unsigned int y = 0; y < this->_possessiveAdjectivesList.at(i).possessiveAdjectives.size(); y++)
		{
			foundPos = sentence.find(this->_possessiveAdjectivesList.at(i).possessiveAdjectives.at(y));
			if (foundPos != std::string::npos)
			{
				found = true;
				possessiveAdjectif = this->_possessiveAdjectivesList.at(i).possessiveAdjectives.at(y);
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
void Possessive_Adjectives::addPossessive(std::vector<std::string> possessiveAdjectives)
{
	POSSESSIVE_ADJECTIVES newPossessive;
	newPossessive.name = "";
	newPossessive.possessiveAdjectives = possessiveAdjectives;
	this->_possessiveAdjectivesList.push_back(newPossessive);
}
void Possessive_Adjectives::addPossessive(std::string name, std::vector<std::string> possessiveAdjectives)
{
	POSSESSIVE_ADJECTIVES newPossessive;
	newPossessive.name = name;
	newPossessive.possessiveAdjectives = possessiveAdjectives;
	this->_possessiveAdjectivesList.push_back(newPossessive);
}

std::string Possessive_Adjectives::getPossessiveByPos(std::string word, int person)
{
	bool found = false;
	std::string possessivePronounAtPerson;
	for (unsigned int i = 0; i < this->_possessiveAdjectivesList.size(); i++)
	{
		if (this->_possessiveAdjectivesList.at(i).name == word)
		{
			found = true;
			possessivePronounAtPerson = this->_possessiveAdjectivesList.at(i).possessiveAdjectives.at(person - 1);
			break;
		}
		for (unsigned int y = 0; y < this->_possessiveAdjectivesList.at(i).possessiveAdjectives.size(); y++)
		{
			if (this->_possessiveAdjectivesList.at(i).possessiveAdjectives.at(y) == word)
			{
				found = true;
				possessivePronounAtPerson = this->_possessiveAdjectivesList.at(i).possessiveAdjectives.at(person - 1);
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

bool Possessive_Adjectives::isPlural(std::string possessiveAdjectives)
{
	bool found = false;
	bool isPlural = false;
	std::string possessivePronounAtPerson;
	for (unsigned int i = 0; i < this->_possessiveAdjectivesList.size(); i++)
	{
		for (unsigned int y = 0; y < this->_possessiveAdjectivesList.at(i).possessiveAdjectives.size(); y++)
		{
			if (this->_possessiveAdjectivesList.at(i).possessiveAdjectives.at(y) == possessiveAdjectives)
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