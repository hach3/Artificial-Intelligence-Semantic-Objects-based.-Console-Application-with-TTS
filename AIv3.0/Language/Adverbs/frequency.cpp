#include "frequency.h"

Frequency_Adverbs::Frequency_Adverbs()
{
	this->init();
}
Frequency_Adverbs::~Frequency_Adverbs()
{
	this->_frequencyAdverbsList.clear();
}

void Frequency_Adverbs::init()
{
	this->addFrequency("ALWAYS", 1.0);
	this->addFrequency("USUALLY", 0.9);
	this->addFrequency("NORMALLY", 0.8);
	this->addFrequency("GENERALLY", 0.8);
	this->addFrequency("FREQUENTLY", 0.7);
	this->addFrequency("OFTEN", 0.7);
	this->addFrequency("SOMETIMES", 0.5);
	this->addFrequency("OCCASIONALLY", 0.3);
	this->addFrequency("SELDOM", 0.1);
	this->addFrequency("HARDLY EVER", 0.05);
	this->addFrequency("RARELY", 0.05);
	this->addFrequency("NEVER", 0);

}
void Frequency_Adverbs::addFrequency(std::string frequency)
{
	FREQUENCY_ADVERBS frqcy;
	frqcy.adv = frequency;
	this->_frequencyAdverbsList.push_back(frqcy);
}
void Frequency_Adverbs::addFrequency(std::string frequency, double value)
{
	FREQUENCY_ADVERBS frqcy;
	frqcy.adv = frequency;
	frqcy.valueOfAdv = value;
	this->_frequencyAdverbsList.push_back(frqcy);
}

bool Frequency_Adverbs::isFrequency(std::string frequency)
{
	bool found = false;
	for (unsigned int i = 0; i < this->_frequencyAdverbsList.size(); i++)
	{
		if (this->_frequencyAdverbsList.at(i).adv == frequency)
		{
			found = true;
			break;
		}
	}
	return found;
}
bool Frequency_Adverbs::isFrequencyInSentence(std::string sentence)
{
	bool found = false;
	size_t foundAt;
	for (unsigned int i = 0; i < this->_frequencyAdverbsList.size(); i++)
	{
		foundAt = sentence.find(this->_frequencyAdverbsList.at(i).adv);
		if (foundAt != std::string::npos)
		{
			found = true;
			break;
		}
	}
	return found;
}
bool Frequency_Adverbs::isFrequencyInVector(std::vector<std::string> vectorSentence)
{
	bool found = false;
	for (unsigned int i = 0; i < this->_frequencyAdverbsList.size(); i++)
	{
		for (unsigned int y = 0; y < vectorSentence.size(); y++)
		{
			if (this->_frequencyAdverbsList.at(i).adv == vectorSentence.at(y))
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

double Frequency_Adverbs::getValueOfFrequency(std::string frequency)
{
	bool found = false;
	double fr;
	for (unsigned int i = 0; i < this->_frequencyAdverbsList.size(); i++)
	{
		if (this->_frequencyAdverbsList.at(i).adv == frequency)
		{
			fr = this->_frequencyAdverbsList.at(i).valueOfAdv;
			found = true;
			break;
		}
	}
	return fr;
}