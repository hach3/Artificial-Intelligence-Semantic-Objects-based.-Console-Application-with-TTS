#include "indefinite.h"

IndefiniteAdj::IndefiniteAdj()
{
	this->init();
}
IndefiniteAdj::~IndefiniteAdj()
{
	this->_indefiniteAdjectivesList.clear();
}

void IndefiniteAdj::init(void)
{
	this->addIndefinite("ANY");
	this->addIndefinite("EACH");
	this->addIndefinite("FEW");
	this->addIndefinite("MANY");
	this->addIndefinite("MUCH");
	this->addIndefinite("MOST");
	this->addIndefinite("SEVERAL");
	this->addIndefinite("SOME");
}

void IndefiniteAdj::addIndefinite(std::string adjective)
{
	INDEFINITE_ADJECTIVES adj;
	adj.adjective = adjective;
	this->_indefiniteAdjectivesList.push_back(adj);
}
void IndefiniteAdj::addIndefinite(std::string adjective, std::string relatedWord)
{
	INDEFINITE_ADJECTIVES adj;
	adj.adjective = adjective;
	adj.relatedWord = relatedWord;
	this->_indefiniteAdjectivesList.push_back(adj);
}

bool IndefiniteAdj::isIndefinite(std::string word)
{
	bool found = false;
	for (unsigned int i = 0; i < this->_indefiniteAdjectivesList.size(); i++)
	{
		if (this->_indefiniteAdjectivesList.at(i).adjective == word)
		{
			found = true;
			break;
		}
	}
	return found;
}
bool IndefiniteAdj::isIndefiniteInSentence(std::string sentence)
{
	bool found = false;
	size_t foundAt;
	for (unsigned int i = 0; i < this->_indefiniteAdjectivesList.size(); i++)
	{
		foundAt = sentence.find(this->_indefiniteAdjectivesList.at(i).adjective);
		if (foundAt != std::string::npos)
		{
			found = true;
			break;
		}
	}
	return found;
}
bool IndefiniteAdj::isIndefiniteInVector(std::vector<std::string> vectorSentence)
{
	bool found = false;
	for (unsigned int i = 0; i < this->_indefiniteAdjectivesList.size(); i++)
	{
		for (unsigned int y = 0; y < vectorSentence.size(); y++)
		{
			if (this->_indefiniteAdjectivesList.at(i).adjective == vectorSentence.at(y))
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

std::string IndefiniteAdj::getRelatedWord(std::string adjective)
{
	bool found = false;
	std::string adjToReturn;
	for (unsigned int i = 0; i < this->_indefiniteAdjectivesList.size(); i++)
	{
		if (this->_indefiniteAdjectivesList.at(i).adjective == adjective)
		{
			found = true;
			adjToReturn = this->_indefiniteAdjectivesList.at(i).relatedWord;
		}
	}
	return adjToReturn;
}