#include "demonstrativeAdjectives.h"

Demonstrative_Adjectives::Demonstrative_Adjectives()
{
	this->init();
}
Demonstrative_Adjectives::~Demonstrative_Adjectives()
{
	this->_demonstrativeList.clear();
}

void Demonstrative_Adjectives::init(void)
{

}

void Demonstrative_Adjectives::addDemonstrative(std::string singular, std::string plural)
{
	DEMONSTRATIVE_ADJECTIVES adj;
	adj.singular = singular;
	adj.plural = plural;
	this->_demonstrativeList.push_back(adj);
}
void Demonstrative_Adjectives::addDemonstrative(std::string singular, std::string plural, bool isFar)
{
	DEMONSTRATIVE_ADJECTIVES adj;
	adj.singular = singular;
	adj.plural = plural;
	adj.isFar = isFar;
	this->_demonstrativeList.push_back(adj);
}

bool Demonstrative_Adjectives::isDemonstrative(std::string word)
{
	bool found = false;
	for (unsigned int i = 0; i < this->_demonstrativeList.size(); i++)
	{
		if (this->_demonstrativeList.at(i).singular == word ||
			this->_demonstrativeList.at(i).plural == word)
		{
			found = true;
			break;
		}
	}
	return found;
}
bool Demonstrative_Adjectives::isDemonstrativeInSentence(std::string sentence)
{
	bool found = false;
	size_t foundAt;
	size_t foundAt2;
	for (unsigned int i = 0; i < this->_demonstrativeList.size(); i++)
	{
		foundAt = sentence.find(this->_demonstrativeList.at(i).singular);
		foundAt2 = sentence.find(this->_demonstrativeList.at(i).plural);

		if ((foundAt != std::string::npos) || (foundAt2 != std::string::npos))
		{
			found = true;
			break;
		}
	}
	return found;
}
bool Demonstrative_Adjectives::isDemonsrativeInVector(std::vector<std::string> vectorSentence)
{
	bool found = false;
	for (unsigned int i = 0; i < this->_demonstrativeList.size(); i++)
	{
		for (unsigned int y = 0; y < vectorSentence.size(); y++)
		{
			if (this->_demonstrativeList.at(i).singular == vectorSentence.at(y) ||
				this->_demonstrativeList.at(i).plural == vectorSentence.at(y))
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

std::string Demonstrative_Adjectives::getDemonstrative(bool isPlural, bool isFar)
{
	std::string adj;
	for (unsigned int i = 0; i < this->_demonstrativeList.size(); i++)
	{
		if (this->_demonstrativeList.at(i).isFar == isFar)
		{
			if (isPlural)
				adj = this->_demonstrativeList.at(i).plural;
			else
				adj = this->_demonstrativeList.at(i).singular;
			break;
		}
	}
	return adj;
}