#include "degree.h"

Degree_Adverbs::Degree_Adverbs()
{
	this->init();
}
Degree_Adverbs::~Degree_Adverbs()
{
	this->_degreeAdverbsList.clear();
}

void Degree_Adverbs::init()
{
	this->addDegree("ALMOST");
	this->addDegree("ABSOLUTELY");
	this->addDegree("ENOUGH");
	this->addDegree("FAIRLY");
}
void Degree_Adverbs::addDegree(std::string adv)
{
	DEGREE_ADVERBS adverb;
	adverb.adv = adv;
	this->_degreeAdverbsList.push_back(adverb);
}

bool Degree_Adverbs::isDegree(std::string adv)
{
	bool found = false;
	for (unsigned int i = 0; i < this->_degreeAdverbsList.size(); i++)
	{
		if (this->_degreeAdverbsList.at(i).adv == adv)
		{
			found = true;
			break;
		}
	}
	return found;
}
bool Degree_Adverbs::isDegreeInSentence(std::string sentence)
{
	bool found = false;
	size_t foundAt;
	for (unsigned int i = 0; i < this->_degreeAdverbsList.size(); i++)
	{
		foundAt = sentence.find(this->_degreeAdverbsList.at(i).adv);
		if (foundAt != std::string::npos)
		{
			found = true;
			break;
		}
	}
	return found;
}
bool Degree_Adverbs::isDegreeInVector(std::vector<std::string> vectorSentence)
{
	bool found = false;
	for (unsigned int i = 0; i < this->_degreeAdverbsList.size(); i++)
	{
		for (unsigned int y = 0; y < vectorSentence.size(); y++)
		{
			if (this->_degreeAdverbsList.at(i).adv == vectorSentence.at(y))
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