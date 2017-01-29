#include "interrogativePronouns.h"

Interrogative_Pronoun::Interrogative_Pronoun()
{
	this->init();
}
Interrogative_Pronoun::~Interrogative_Pronoun()
{
	this->_interrogativePronounsList.clear();
}

void Interrogative_Pronoun::init()
{
	this->addInterrogative("WHAT");

	this->addInterrogative("HOW");

	this->addInterrogative("WHERE");

	this->addInterrogative("WHEN");

	this->addInterrogative("WHY");

	this->addInterrogative("WHO");
}

bool Interrogative_Pronoun::isInterrogative(std::string word)
{
	bool found = false;
	for (unsigned int i = 0; i < this->_interrogativePronounsList.size(); i++)
	{
		if (this->_interrogativePronounsList.at(i).singular == word || this->_interrogativePronounsList.at(i).plural == word)
		{
			found = true;
			break;
		}

	}
	return found;
}
bool Interrogative_Pronoun::isInterrogativeInSentence(std::string sentence, std::string &sentenceIfFound, std::string &wh)
{
	bool found = false;
	std::size_t foundAt;
	for (unsigned int i = 0; i < this->_interrogativePronounsList.size(); i++)
	{
		foundAt = sentence.find(this->_interrogativePronounsList.at(i).singular);
		if (foundAt != std::string::npos)
		{
			found = true;
			sentenceIfFound = sentence.substr(foundAt);
			wh = this->_interrogativePronounsList.at(i).singular;
			break;
		}
		

	}
	return found;

}

void Interrogative_Pronoun::addInterrogative(std::string singular)
{
	INTERROGATIVE_PRONOUN interrogativePronoun;
	interrogativePronoun.singular = singular;
	this->_interrogativePronounsList.push_back(interrogativePronoun);
}
void Interrogative_Pronoun::addInterrogative(std::string singular, std::string plural)
{
	INTERROGATIVE_PRONOUN interrogativePronoun;
	interrogativePronoun.singular = singular;
	interrogativePronoun.plural = plural;
	this->_interrogativePronounsList.push_back(interrogativePronoun);
}
void Interrogative_Pronoun::addInterrogative(std::string singular, std::string plural, std::vector<std::string> relatedWords)
{
	INTERROGATIVE_PRONOUN interrogativePronoun;
	interrogativePronoun.singular = singular;
	interrogativePronoun.plural = plural;
	interrogativePronoun.relatedWords = relatedWords;
	this->_interrogativePronounsList.push_back(interrogativePronoun);
}

void Interrogative_Pronoun::setPlural(std::string singular, std::string plural)
{
	bool found = false;
	for (unsigned int i = 0; i < this->_interrogativePronounsList.size(); i++)
	{
		if (this->_interrogativePronounsList.at(i).singular == singular)
		{
			this->_interrogativePronounsList.at(i).plural = plural;
			found = true;
			break;
		}
	}
}

void Interrogative_Pronoun::addRelatedWord(std::string word, std::string relatedWords)
{
	bool found = false;
	for (unsigned int i = 0; i < this->_interrogativePronounsList.size(); i++)
	{
		if (this->_interrogativePronounsList.at(i).singular == word || this->_interrogativePronounsList.at(i).plural == word)
		{
			this->_interrogativePronounsList.at(i).relatedWords.push_back(relatedWords);
			found = true;
			break;
		}
	}
}
bool Interrogative_Pronoun::isRelatedWord(std::string word, std::string relatedWord)
{
	bool found = false;
	for (unsigned int i = 0; i < this->_interrogativePronounsList.size(); i++)
	{
		if (this->_interrogativePronounsList.at(i).singular == word || this->_interrogativePronounsList.at(i).plural == word)
		{
			for (unsigned int y = 0; y < this->_interrogativePronounsList.at(i).relatedWords.size(); y++)
			{
				if (this->_interrogativePronounsList.at(i).relatedWords.at(y) == relatedWord)
				{
					found = true;
					break;
				}
			}
			
			
		}
		if (found == true)
		{
			break;
		}
	}
	return found;
}

std::string Interrogative_Pronoun::getSingular(std::string interrogativeWord)
{
	std::string interrogativeSingular;
	for (unsigned int i = 0; i < this->_interrogativePronounsList.size(); i++)
	{
		if (this->_interrogativePronounsList.at(i).plural == interrogativeWord || this->_interrogativePronounsList.at(i).singular == interrogativeWord)
		{
			interrogativeSingular = this->_interrogativePronounsList.at(i).singular;
		}
	}
	return interrogativeSingular;
}
std::string Interrogative_Pronoun::getPlural(std::string interrogativeWord)
{
	std::string interrogativePlural;
	for (unsigned int i = 0; i < this->_interrogativePronounsList.size(); i++)
	{
		if (this->_interrogativePronounsList.at(i).plural == interrogativeWord || this->_interrogativePronounsList.at(i).singular == interrogativeWord)
		{
			interrogativePlural = this->_interrogativePronounsList.at(i).plural;
		}
	}
	return interrogativePlural;
}