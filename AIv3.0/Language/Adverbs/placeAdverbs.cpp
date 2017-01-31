#include "placeAdverbs.h"


Place_Adverbs::Place_Adverbs()
{
	this->init();
}
Place_Adverbs::~Place_Adverbs()
{
	this->_placeAdverbsList.clear();
}

void Place_Adverbs::init(void)
{
	this->addPlaceAdj("AROUND");
	this->addPlaceAdj("EVERYWHERE");
	this->addPlaceAdj("BACK");
	this->addPlaceAdj("IN");
	this->addPlaceAdj("OUTSIDE");
}

void Place_Adverbs::addPlaceAdj(std::string place)
{
	PLACE_ADVERBS adv;
	adv.place = place;
	this->_placeAdverbsList.push_back(adv);
}

bool Place_Adverbs::checkIfPlace(std::string place)
{
	bool found = false;
	for (unsigned int i = 0; i < this->_placeAdverbsList.size(); i++)
	{
		if (this->_placeAdverbsList.at(i).place == place)
		{
			found = true;
			break;
		}
	}
	return found;
}
bool Place_Adverbs::checkIfPlaceInSentence(std::string sentence)
{
	bool found = false;
	size_t foundAt;
	for (unsigned int i = 0; i < this->_placeAdverbsList.size(); i++)
	{
		foundAt = sentence.find(this->_placeAdverbsList.at(i).place);
		if (foundAt != std::string::npos)
		{
			found = true;
			break;
		}
	}
	return found;
}
bool Place_Adverbs::checkIfPlaceInVector(std::vector<std::string> vectorSentence)
{
	bool found = false;
	for (unsigned int i = 0; i < this->_placeAdverbsList.size(); i++)
	{
		for (unsigned int y = 0; y < vectorSentence.size(); y++)
		{
			if (this->_placeAdverbsList.at(i).place == vectorSentence.at(y))
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