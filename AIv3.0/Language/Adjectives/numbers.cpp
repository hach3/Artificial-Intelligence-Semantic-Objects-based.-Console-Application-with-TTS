#include "numbers.h"


Numbers::Numbers()
{
	this->init();
}
Numbers::~Numbers()
{
	this->_numberAdjList.clear();
}

void Numbers::init()
{
	this->addNumber("ONE", "1", "FIRST", "1ST");
	this->addNumber("TWO", "2", "SECOND", "2ND");
	this->addNumber("THREE", "3", "THIRD", "3RD");
}

void Numbers::addNumber(std::string alphaForm, std::string nbForm,
	std::string thAlphaForm, std::string thNbForm)
{
	NUMBERS_ADJECTIVES adj;
	adj.alphaForm = alphaForm;
	adj.nbForm = nbForm;
	adj.thAlphaForm = thAlphaForm;
	adj.thNbForm = thNbForm;
	this->_numberAdjList.push_back(adj);
}
bool Numbers::isNumber(std::string nb)
{
	bool found = false;
	for (unsigned int i = 0; i < this->_numberAdjList.size(); i++)
	{
		if (this->_numberAdjList.at(i).alphaForm == nb ||
			this->_numberAdjList.at(i).nbForm == nb ||
			this->_numberAdjList.at(i).thAlphaForm == nb ||
			this->_numberAdjList.at(i).thNbForm == nb)
		{
			found = true;
			break;
		}
	}
	return found;
}

bool Numbers::isNumberInVector(std::vector<std::string> vectorSentence)
{
	bool found = false;
	for (unsigned int i = 0; i < this->_numberAdjList.size(); i++)
	{
		for (unsigned int y = 0; y < vectorSentence.size(); y++)
		{
			if (this->_numberAdjList.at(i).alphaForm == vectorSentence.at(y) ||
				this->_numberAdjList.at(i).nbForm == vectorSentence.at(y) ||
				this->_numberAdjList.at(i).thAlphaForm == vectorSentence.at(y) ||
				this->_numberAdjList.at(i).thNbForm == vectorSentence.at(y))
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
