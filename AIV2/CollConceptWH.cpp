#include "CollConceptWH.h"


CollConceptWH::CollConceptWH()
{

}
CollConceptWH::~CollConceptWH()
{
    this->_whWords.clear();
}

void CollConceptWH::Init()
{
	std::vector<std::string> whatWords;
	whatWords.push_back("WHAT");
	this->addConceptWH("", "CONCEPT_WHAT", whatWords);
}



/* Check if the wh exists by checking the name in the whwords vector */
bool CollConceptWH::checkIfExist(std::string wh_name)
{
	bool found = false;
	for (int i = 0; i < this->_whWords.size(); i++)
	{
		if (this->_whWords.at(i).WH_NAME == wh_name)
		{
			found = true;
		}
	}
	return found;
}
bool CollConceptWH::checkIfWordIsWH(std::string wh_word)
{
	bool found = false;
	for (int i = 0; i < this->_whWords.size(); i++)
	{
		for (int y = 0; y < this->_whWords.at(i).WH_WORDS.size(); y++)
		{
			if (this->_whWords.at(i).WH_WORDS.at(y) == wh_word)
			{
				found = true;
			}
		}
	}
	return found;
}
void CollConceptWH::deleteAll()
{
    this->_whWords.clear();
}
void CollConceptWH::addConceptWH(std::string parent,
                                 std::string whname,
                                 std::vector<std::string> whwords)
{
	CONCEPT_WH wh = { parent, whname, whwords };
	this->_whWords.push_back(wh);
}
void CollConceptWH::deleteConceptWH(std::string wh)
{
	for (int i = 0; i < this->_whWords.size(); i++)
	{
		for (int y = 0; y < this->_whWords.at(i).WH_WORDS.size(); y++)
		{
			if (this->_whWords.at(i).WH_WORDS.at(y) == wh)
			{
				this->_whWords.at(i).WH_WORDS.erase(this->_whWords.at(i).WH_WORDS.begin() + y);
				break;
			}
		}
	}
}

std::string CollConceptWH::getName(std::string whWord)
{
	std::string name;
	for (int i = 0; i < this->_whWords.size(); i++)
	{
		for (int y = 0; y < this->_whWords.at(i).WH_WORDS.size(); y++)
		{
			if (this->_whWords.at(i).WH_WORDS.at(y) == whWord)
			{
				name = this->_whWords.at(i).WH_WORDS.at(y);
			}
		}
	}
	return name;
}


std::vector<std::string> CollConceptWH::getConceptWordsByName(std::string wh_name)
{
	std::vector<std::string> allWHWords;
	for (int i = 0; i < this->_whWords.size(); i++)
	{
		if (this->_whWords.at(i).WH_NAME == wh_name)
		{
			allWHWords = this->_whWords.at(i).WH_WORDS;
		}
	}
	return allWHWords;
}
