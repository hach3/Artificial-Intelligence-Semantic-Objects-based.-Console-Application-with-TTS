#include "manner.h"

Manner_Adverbs::Manner_Adverbs()
{
	this->init();
}

Manner_Adverbs::~Manner_Adverbs()
{
	this->_mannerAdverbsList.clear();
}


void Manner_Adverbs::init()
{
	this->addMannerAdj("WELL");
	this->addMannerAdj("QUICKLY");
	this->addMannerAdj("SOFTLY");
	this->addMannerAdj("LOUDLY");
	this->addMannerAdj("BEAUTIFULLY");
	this->addMannerAdj("GREEDILY");
}


void Manner_Adverbs::addMannerAdj(std::string manner)
{
	MANNER_ADVERBS adv;
	adv.manner = manner;
	this->_mannerAdverbsList.push_back(adv);
}


bool Manner_Adverbs::checkIfManner(std::string manner)
{
	bool found = false;
	for (unsigned int i = 0; i < this->_mannerAdverbsList.size(); i++)
	{
		if (this->_mannerAdverbsList.at(i).manner == manner)
		{
			found = true;
			break;
		}
	}
	return found;
}

bool Manner_Adverbs::checkIfMannerInSentence(std::string sentence)
{
	bool found = false;
	size_t foundAt;
	for (unsigned int i = 0; i < this->_mannerAdverbsList.size(); i++)
	{
		foundAt = sentence.find(this->_mannerAdverbsList.at(i).manner);
		if (foundAt != std::string::npos)
		{
			found = true;
			break;
		}
	}
	return found;
}

bool Manner_Adverbs::checkIfMannerInVector(std::vector<std::string> vectorSentence)
{
	bool found = false;
	for (unsigned int i = 0; i < this->_mannerAdverbsList.size(); i++)
	{
		for (unsigned int y = 0; y < vectorSentence.size(); y++)
		{
			if (this->_mannerAdverbsList.at(i).manner == vectorSentence.at(y))
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
