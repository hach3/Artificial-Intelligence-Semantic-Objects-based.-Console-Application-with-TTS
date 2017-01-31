#include "interrogativeAdjectives.h"


Interrogative_Adjectives::Interrogative_Adjectives(void)
{
	this->init();
}
Interrogative_Adjectives::~Interrogative_Adjectives(void)
{
	this->_interrogativeList.clear();
}

void Interrogative_Adjectives::init(void)
{
	this->addInterrogative("WHAT", "ABOUT");
	this->addInterrogative("WHICH", "CHOOSE");
	this->addInterrogative("WHOSE", "POSSESSION");
}

void Interrogative_Adjectives::addInterrogative(std::string wh)
{
	INTERROGATIVE_ADJECTIVES adj;
	adj.wh = wh;
	this->_interrogativeList.push_back(adj);
}
void Interrogative_Adjectives::addInterrogative(std::string wh, std::string concept)
{
	INTERROGATIVE_ADJECTIVES adj;
	adj.wh = wh;
	adj.concept = concept;
	this->_interrogativeList.push_back(adj);
}

bool Interrogative_Adjectives::isInterrogative(std::string word)
{
	bool found = false;
	for (unsigned int i = 0; i < this->_interrogativeList.size(); i++)
	{
		if (this->_interrogativeList.at(i).wh == word)
		{
			found = true;
			break;

		}
	}
	return found;
}
bool Interrogative_Adjectives::isInterrogativeInSentence(std::string Sentence)
{
	bool found = false;
	size_t foundAt;
	for (unsigned int i = 0; i < this->_interrogativeList.size(); i++)
	{
		foundAt = Sentence.find(this->_interrogativeList.at(i).wh);
		if (foundAt != std::string::npos)
		{
			found = true;
			break;
		}
	}
	return found;
}
bool Interrogative_Adjectives::isInterrogativeInVector(std::vector<std::string> vectorSentence)
{
	bool found = false;
	for (unsigned int i = 0; i < this->_interrogativeList.size(); i++)
	{
		for (unsigned int y = 0; y < vectorSentence.size(); y++)
		{
			if (this->_interrogativeList.at(i).wh == vectorSentence.at(y))
			{
				found = true;
				break;
			}
		}
		if (found)
			break;
	}
	return found;
}

bool Interrogative_Adjectives::isConcept(std::string wh, std::string concept)
{
	bool found = false;
	for (unsigned int i = 0; i < this->_interrogativeList.size(); i++)
	{
		if (this->_interrogativeList.at(i).wh == wh &&
			this->_interrogativeList.at(i).concept == concept)
		{
			found = true;
			break;
		}
	}
	return found;
}
std::string Interrogative_Adjectives::getConcept(std::string wh)
{
	std::string concept;
	for (unsigned int i = 0; i < this->_interrogativeList.size(); i++)
	{
		if (this->_interrogativeList.at(i).wh == wh)
		{
			concept = this->_interrogativeList.at(i).concept;
		}
	}
	return concept;
}