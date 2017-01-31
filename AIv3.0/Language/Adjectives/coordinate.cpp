#include "coordinate.h"

Coordinate_Adjectives::Coordinate_Adjectives(void)
{
	this->init();
}
Coordinate_Adjectives::~Coordinate_Adjectives(void)
{
	this->_coordinateAdjList.clear();
}

void Coordinate_Adjectives::init(void)
{
	this->addCoordinate("WINDY");
	this->addCoordinate("HOT");
}
void Coordinate_Adjectives::addCoordinate(std::string adjective)
{
	COORDINATE_ADJECTIVES attr;
	attr.adjective = adjective;
	this->_coordinateAdjList.push_back(attr);
}
void Coordinate_Adjectives::addCoordinate(std::string adjective, std::vector<std::string> relatedWords)
{
	COORDINATE_ADJECTIVES attr;
	attr.adjective = adjective;
	attr.relatedWords = relatedWords;
	this->_coordinateAdjList.push_back(attr);
}
bool Coordinate_Adjectives::isAdjective(std::string adjective)
{
	bool found = false;
	for (unsigned int i = 0; i < this->_coordinateAdjList.size(); i++)
	{
		if (this->_coordinateAdjList.at(i).adjective == adjective)
		{
			found = true;
			break;
		}
	}
	return found;
}
bool Coordinate_Adjectives::isAdjectiveInSentence(std::string sentence)
{
	bool found = false;
	size_t foundAt;
	for (unsigned int i = 0; i < this->_coordinateAdjList.size(); i++)
	{
		foundAt = sentence.find(this->_coordinateAdjList.at(i).adjective);
		if (foundAt != std::string::npos)
		{
			found = true;
			break;
		}
	}
	return found;
}
bool Coordinate_Adjectives::isAdjectiveInSentence(std::string sentence, std::vector<std::string> &adjectives)
{
	bool found = false;
	size_t foundAt;
	for (unsigned int i = 0; i < this->_coordinateAdjList.size(); i++)
	{
		foundAt = sentence.find(this->_coordinateAdjList.at(i).adjective);
		if (foundAt != std::string::npos)
		{
			found = true;
			adjectives.push_back(this->_coordinateAdjList.at(i).adjective);
		}
	}
	return found;
}
bool Coordinate_Adjectives::isAdjectiveInVector(std::vector<std::string> vectorSentence)
{
	bool found = false;
	for (unsigned int i = 0; i < this->_coordinateAdjList.size(); i++)
	{
		for (unsigned int y = 0; y < vectorSentence.size(); y++)
		{
			if (this->_coordinateAdjList.at(i).adjective == vectorSentence.at(y))
			{
				found = true;
				break;
			}
		}
	}
	return found;
}

bool Coordinate_Adjectives::isAdjectiveInVector(std::vector<std::string> vectorSentence, std::vector<std::string> &adjectives)
{
	bool found = false;
	for (unsigned int i = 0; i < this->_coordinateAdjList.size(); i++)
	{
		for (unsigned int y = 0; y < vectorSentence.size(); y++)
		{
			if (this->_coordinateAdjList.at(i).adjective == vectorSentence.at(y))
			{
				found = true;
				adjectives.push_back(this->_coordinateAdjList.at(i).adjective);
			}
		}
	}
	return found;
}

void Coordinate_Adjectives::addRelatedWord(std::string adjective, std::string relatedWord)
{
	for (unsigned int i = 0; i < this->_coordinateAdjList.size(); i++)
	{
		if (this->_coordinateAdjList.at(i).adjective == adjective)
		{
			this->_coordinateAdjList.at(i).relatedWords.push_back(relatedWord);
			break;
		}
	}
}
void Coordinate_Adjectives::addRelatedWords(std::string adjective, std::vector<std::string> relatedWords)
{
	for (unsigned int i = 0; i < this->_coordinateAdjList.size(); i++)
	{
		if (this->_coordinateAdjList.at(i).adjective == adjective)
		{
			this->_coordinateAdjList.at(i).relatedWords.insert(relatedWords.end(), relatedWords.begin(), relatedWords.end());
			break;
		}
	}
}
bool Coordinate_Adjectives::isRelatedWordTo(std::string adjective, std::string relatedWord)
{
	bool found = false;
	for (unsigned int i = 0; i < this->_coordinateAdjList.size(); i++)
	{
		if (found)
			break;
		if (this->_coordinateAdjList.at(i).adjective == adjective)
		{
			for (unsigned int y = 0; y < this->_coordinateAdjList.at(i).relatedWords.size(); y++)
			{
				if (this->_coordinateAdjList.at(i).relatedWords.at(y) == relatedWord)
				{
					found = true;
					break;
				}

			}

		}

	}
	return found;
}

std::vector<std::string> Coordinate_Adjectives::getRelatedWords(std::string adjective)
{
	bool found = false;
	std::vector<std::string> vectorToReturn;
	for (unsigned int i = 0; i < this->_coordinateAdjList.size(); i++)
	{
		if (this->_coordinateAdjList.at(i).adjective == adjective)
		{
			vectorToReturn = this->_coordinateAdjList.at(i).relatedWords;
			break;
		}

	}
	return vectorToReturn;
}