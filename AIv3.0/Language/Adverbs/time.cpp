#include "time.h"


Time_Adverbs::Time_Adverbs()
{
	this->init();
}
Time_Adverbs::~Time_Adverbs()
{
	this->_timeAdverbsList.clear();
}

void Time_Adverbs::init()
{
	this->addTimeAdj("YESTERDAY", "DAY");
	this->addTimeAdj("TOMORROW", "DAY");
	this->addTimeAdj("TODAY", "DAY");
	this->addTimeAdj("LATER", "");
	this->addTimeAdj("NOW", "");
	this->addTimeAdj("LAST YEAR", "YEAR");
}

void Time_Adverbs::addTimeAdj(std::string time)
{
	TIME_ADVERBS adv;
	adv.time = time;
	this->_timeAdverbsList.push_back(adv);
}
void Time_Adverbs::addTimeAdj(std::string time, std::string relatedWord)
{
	TIME_ADVERBS adv;
	adv.time = time;
	adv.relatedWord = relatedWord;
	this->_timeAdverbsList.push_back(adv);
}

bool Time_Adverbs::checkIfTime(std::string time)
{
	bool found = false;
	for (unsigned int i = 0; i < this->_timeAdverbsList.size(); i++)
	{
		if (this->_timeAdverbsList.at(i).time == time)
		{
			found = true;
			break;
		}
	}
	return found;
}
bool Time_Adverbs::checkIfTimeInSentence(std::string sentence)
{
	bool found = false;
	size_t foundAt;
	for (unsigned int i = 0; i < this->_timeAdverbsList.size(); i++)
	{
		foundAt = sentence.find(this->_timeAdverbsList.at(i).time);
		if (foundAt != std::string::npos)
		{
			found = true;
			break;
		}
	}
	return found;
}
bool Time_Adverbs::checkIfTimeInVector(std::vector<std::string> vectorSentence)
{
	bool found = false;
	for (unsigned int i = 0; i < this->_timeAdverbsList.size(); i++)
	{
		for (unsigned int y = 0; y < vectorSentence.size(); y++)
		{
			if (this->_timeAdverbsList.at(i).time == vectorSentence.at(y))
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

std::string Time_Adverbs::getRelatedWord(std::string time)
{
	bool found = false;
	std::string wordToReturn;

	for (unsigned int i = 0; i < this->_timeAdverbsList.size(); i++)
	{
		if (this->_timeAdverbsList.at(i).time == time)
		{
			wordToReturn = this->_timeAdverbsList.at(i).relatedWord;
			break;
		}
	}
	return wordToReturn;
}