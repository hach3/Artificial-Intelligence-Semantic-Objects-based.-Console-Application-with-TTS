#include "CollMemory.h"
#include <algorithm>
#include <iostream>

/* Constructor */
CollMemory::CollMemory()
{

}
/* Destructor */
CollMemory::~CollMemory()
{
	this->_souvenirs.clear();
}
void CollMemory::Init()
{
    //Create the basic souvenirs

	 this->addSouvenir("CONCEPT_BE", "CONCEPT_NAME", "YOU", "", "", "", "Gandalf", "", true, true);
}

void CollMemory::deleteAll()
{
    this->_souvenirs.clear();
}


/* Check if the souvenir exist by checking the verb and the name */
bool CollMemory::checkIfExist(std::string concept_verb,
                              std::string concept_name)
{
	bool found = false;
	for (int i = 0; i < this->_souvenirs.size(); i++)
	{
		if (this->_souvenirs.at(i).CONCEPT_NAME == concept_name && this->_souvenirs.at(i).CONCEPT_VERB == concept_verb)
		{
			found = true;
		}
	}
	return found;
}
bool CollMemory::checkIfWhExists(std::string concept_verb,
                                 std::string concept_name,
                                 int whPlace)
{
	bool found = false;
	for (int i = 0; i < this->_souvenirs.size(); i++)
	{
		if (this->_souvenirs.at(i).CONCEPT_NAME == concept_name 
			&& this->_souvenirs.at(i).CONCEPT_VERB == concept_verb)
		{
			switch (whPlace)
			{
			case 0:
				if (this->_souvenirs.at(i).WHO != "")
				{
					found = true;
				}
			case 1:
				if (this->_souvenirs.at(i).WHY != "")
				{
					found = true;
				}
			case 2:
				if (this->_souvenirs.at(i).WHERE != "")
				{
					found = true;
				}
			case 3:
				if (this->_souvenirs.at(i).WHEN != "")
				{
					found = true;
				}
			case 4:
				if (this->_souvenirs.at(i).WHAT != "")
				{
					found = true;
				}
			case 5:
				if (this->_souvenirs.at(i).HOW != "")
				{
					found = true;
				}
			}
		}
	}
	return found;
}


/* Return the value contained in the WH structure
For example, if my name is Tariq, the getWHValue(CONCEPT_BE, CONCEPT_NAME, WHAT) will return Tariq.

 */
std::string CollMemory::getWHValueByPos(std::string subject, std::string concept_verb,
                                   std::string concept_name,
                                   int whPlace)
{
	
	std::string theWHValue;
	for (int i = 0; i < this->_souvenirs.size(); i++)
	{
		if (this->_souvenirs.at(i).CONCEPT_NAME == concept_name
			&& this->_souvenirs.at(i).CONCEPT_VERB == concept_verb
			&& this->_souvenirs.at(i).WHO == subject)
		{
			switch (whPlace)
			{
			case 0:
				if (this->_souvenirs.at(i).WHO != "")
				{
					theWHValue = this->_souvenirs.at(i).WHO;
				}
			case 1:
				if (this->_souvenirs.at(i).WHY != "")
				{
					theWHValue = this->_souvenirs.at(i).WHY;
				}
			case 2:
				if (this->_souvenirs.at(i).WHERE != "")
				{
					theWHValue = this->_souvenirs.at(i).WHERE;
				}
			case 3:
				if (this->_souvenirs.at(i).WHEN != "")
				{
					theWHValue = this->_souvenirs.at(i).WHEN;
				}
			case 4:
				if (this->_souvenirs.at(i).WHAT != "")
				{
					theWHValue = this->_souvenirs.at(i).WHAT;
				}
			case 5:
				if (this->_souvenirs.at(i).HOW != "")
				{
					theWHValue = this->_souvenirs.at(i).HOW;
				}
			}
		}
	}
	return theWHValue;
}
std::string CollMemory::getWHValue(std::string subject, std::string concept_verb,
	std::string concept_name,
	std::string wh_value)
{
	wh_value = this->putToUpperCase(wh_value);
	int wh_place;
	std::string theWHValue;

	if (wh_value == "WHO")
	{
		wh_place = 0;
	}
	else if (wh_value == "WHY")
	{
		wh_place = 1;
	}
	else if (wh_value == "WHERE")
	{
		wh_place = 2;
	}
	else if (wh_value == "WHEN")
	{
		wh_place = 3;
	}
	else if (wh_value == "WHAT")
	{
		wh_place = 4;
	}
	else if (wh_value == "HOW")
	{
		wh_place = 5;
	}
	theWHValue = this->getWHValueByPos(subject, concept_verb, concept_name, wh_place);
	
	return theWHValue;
}
void CollMemory::setWHValue(std::string concept_verb,
                            std::string concept_name,
                            int whPlace,
                            std::string valueToPutIn)
{
	for (int i = 0; i < this->_souvenirs.size(); i++)
	{
		if (this->_souvenirs.at(i).CONCEPT_NAME == concept_name
			&& this->_souvenirs.at(i).CONCEPT_VERB == concept_verb)
		{
			switch (whPlace)
			{
			case 0:			
				this->_souvenirs.at(i).WHY = valueToPutIn;				
			case 1:
				this->_souvenirs.at(i).WHY = valueToPutIn;
			case 2:			
				this->_souvenirs.at(i).WHERE = valueToPutIn;
			case 3:
				this->_souvenirs.at(i).WHEN = valueToPutIn;
			case 4:				
				this->_souvenirs.at(i).WHAT = valueToPutIn;
			case 5:
				this->_souvenirs.at(i).HOW = valueToPutIn;
				
			}
		}
	}
}

/*
Create a souvenir
std::string WHO;
std::string WHY;
std::string WHERE;
std::string WHEN;
std::string WHAT;
std::string HOW;
*/
void CollMemory::addSouvenir(std::string concept_name)
{
	Souvenir souvenir = { "", "", "", "", "", "", "", concept_name, false, false};
	this->_souvenirs.push_back(souvenir);
}
void CollMemory::addSouvenir(std::string concept_verb, std::string concept_name)
{
	Souvenir souvenir = { "", "", "", "", "", "", concept_verb, concept_name , false, false };
	this->_souvenirs.push_back(souvenir);
}
void CollMemory::addSouvenir(std::string concept_verb, std::string concept_name, std::string who, std::string why, std::string where, std::string when, std::string what, std::string how, bool is, bool have)
{
	Souvenir souvenir = { who, why, where, when, what, how, concept_verb, concept_name , is, have };
	this->_souvenirs.push_back(souvenir);
}

bool CollMemory::checkIs(std::string concept_name)
{
	bool is;
	for (int i = 0; i < this->_souvenirs.size(); i++)
	{
		if (this->_souvenirs.at(i).CONCEPT_NAME == concept_name)
		{
			is = this->_souvenirs.at(i).is;
		}
	}
	return is;
}
bool CollMemory::checkHave(std::string concept_name)
{
	bool have;
	for (int i = 0; i < this->_souvenirs.size(); i++)
	{
		if (this->_souvenirs.at(i).CONCEPT_NAME == concept_name)
		{
			have = this->_souvenirs.at(i).have;
		}
	}
	return have;
}


std::string CollMemory::putToUpperCase(std::string s)
{
	std::transform(s.begin(), s.end(), s.begin(), ::toupper);

	return s;
}