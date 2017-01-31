#include "attribute.h"

Attribute::Attribute(void)
{
	this->init();
}
Attribute::~Attribute(void)
{
	this->_attributeList.clear();
}

void Attribute::init(void)
{
	std::vector<std::string> blueRelatedWords;
	blueRelatedWords.push_back("COLOR");
	this->addAttribute("BLUE", blueRelatedWords);

	std::vector<std::string> oldRelatedWords;
	oldRelatedWords.push_back("AGE");
	this->addAttribute("OLD", oldRelatedWords);
}
void Attribute::addAttribute(std::string adjective)
{
	ATTRIBUTE_ADJECTIVES attr;
	attr.adjective = adjective;
	this->_attributeList.push_back(attr);
}
void Attribute::addAttribute(std::string adjective, std::vector<std::string> relatedWords)
{
	ATTRIBUTE_ADJECTIVES attr;
	attr.adjective = adjective;
	attr.relatedWords = relatedWords;
	this->_attributeList.push_back(attr);
}
bool Attribute::isAdjective(std::string adjective)
{
	bool found = false;
	for (unsigned int i = 0; i < this->_attributeList.size(); i++)
	{
		if (this->_attributeList.at(i).adjective == adjective)
		{
			found = true;
			break;
		}
	}
	return found;
}
bool Attribute::isAdjectiveInSentence(std::string sentence)
{
	bool found = false;
	size_t foundAt;
	for (unsigned int i = 0; i < this->_attributeList.size(); i++)
	{
		foundAt = sentence.find(this->_attributeList.at(i).adjective);
		if (foundAt != std::string::npos)
		{
			found = true;
			break;
		}
	}
	return found;
}
bool Attribute::isAdjectiveInSentence(std::string sentence, std::vector<std::string> &adjectives) 
{
	bool found = false;
	size_t foundAt;
	for (unsigned int i = 0; i < this->_attributeList.size(); i++)
	{
		foundAt = sentence.find(this->_attributeList.at(i).adjective);
		if (foundAt != std::string::npos)
		{
			found = true;
			adjectives.push_back(this->_attributeList.at(i).adjective);
		}
	}
	return found;
}
bool Attribute::isAdjectiveInVector(std::vector<std::string> vectorSentence)
{
	bool found = false;
	for (unsigned int i = 0; i < this->_attributeList.size(); i++)
	{
		for (unsigned int y = 0; y < vectorSentence.size(); y++)
		{
			if (this->_attributeList.at(i).adjective == vectorSentence.at(y))
			{
				found = true;
				break;
			}
		}
	}
	return found;
}

bool Attribute::isAdjectiveInVector(std::vector<std::string> vectorSentence, std::vector<std::string> &adjectives)
{
	bool found = false;
	for (unsigned int i = 0; i < this->_attributeList.size(); i++)
	{
		for (unsigned int y = 0; y < vectorSentence.size(); y++)
		{
			if (this->_attributeList.at(i).adjective == vectorSentence.at(y))
			{
				found = true;
				adjectives.push_back(this->_attributeList.at(i).adjective);
			}
		}
	}
	return found;
}

void Attribute::addRelatedWord(std::string adjective, std::string relatedWord)
{
	for (unsigned int i = 0; i < this->_attributeList.size(); i++)
	{
		if (this->_attributeList.at(i).adjective == adjective)
		{
			this->_attributeList.at(i).relatedWords.push_back(relatedWord);
			break;
		}
	}
}
void Attribute::addRelatedWords(std::string adjective, std::vector<std::string> relatedWords)
{
	for (unsigned int i = 0; i < this->_attributeList.size(); i++)
	{
		if (this->_attributeList.at(i).adjective == adjective)
		{
			this->_attributeList.at(i).relatedWords.insert(relatedWords.end(), relatedWords.begin(), relatedWords.end());
			break;
		}
	}
}
bool Attribute::isRelatedWordTo(std::string adjective, std::string relatedWord)
{
	bool found = false;
	for (unsigned int i = 0; i < this->_attributeList.size(); i++)
	{
		if (found)
			break;
		if (this->_attributeList.at(i).adjective == adjective)
		{
			for (unsigned int y = 0; y < this->_attributeList.at(i).relatedWords.size(); y++)
			{
				if (this->_attributeList.at(i).relatedWords.at(y) == relatedWord)
				{
					found = true;
					break;
				}
				
			}
			
		}
		
	}
	return found;
}

std::vector<std::string> Attribute::getRelatedWords(std::string adjective)
{
	bool found = false;
	std::vector<std::string> vectorToReturn;
	for (unsigned int i = 0; i < this->_attributeList.size(); i++)
	{
		if (this->_attributeList.at(i).adjective == adjective)
		{
			vectorToReturn = this->_attributeList.at(i).relatedWords;
			break;
		}

	}
	return vectorToReturn;
}