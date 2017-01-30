#include "semanticMemory.h"

semanticMemory::semanticMemory()
{
	this->init();
}
semanticMemory::~semanticMemory()
{
	this->_semantics.clear();
}

void semanticMemory::init()
{
	/* CREATING OBJECT MYSELF */
	this->createObject("MYSELF");
	this->addIsA("MYSELF", "HUMAN");
	WH_ANSWERS myselfAnswers;
	myselfAnswers.whatWH = "TARIQ";
	this->addIs("MYSELF", "NAME", myselfAnswers);
	this->addHas("MYSELF", "NAME");
	this->addCan("MYSELF", "TALK");

	/* CREATING OBJECT HUMAN */
	this->createObject("HUMAN");
	this->addIsA("HUMAN", "LIVING CREATURE");
	WH_ANSWERS humanAnswers;	
	this->addIs("HUMAN", "NAME", humanAnswers);
	this->addHas("HUMAN", "NAME");
	this->addCan("HUMAN", "TALK");


}

/* check if an object exists in the semantic memory */
bool semanticMemory::objectDoesExist(const std::string objectName)
{
	bool found = false;
	for (unsigned int i = 0; i < this->_semantics.size(); i++)
	{
		if (this->_semantics.at(i).objectName == objectName)
		{
			found = true;
			break;
		}
	}
	return found;
}
/* check if a word is in the canList of an object*/
bool semanticMemory::objetCanExist(const std::string objectName, const std::string can)
{
	bool found = false;
	for (unsigned int i = 0; i < this->_semantics.size(); i++)
	{
		if (this->_semantics.at(i).objectName == objectName)
		{
			for (unsigned int y = 0; y < this->_semantics.at(i)._can.size(); y++)
			{
				if (this->_semantics.at(i)._can.at(y) == can)
				{
					found = true;
					break;
				}
			}
			if (found)
				break;
		}
		
	}
	return found;
}
/* check if a word is in the isList of an object*/
bool semanticMemory::objetIsExist(const std::string objectName, const std::string object)
{
	bool found = false;
	for (unsigned int i = 0; i < this->_semantics.size(); i++)
	{
		if (this->_semantics.at(i).objectName == objectName)
		{
			for (unsigned int y = 0; y < this->_semantics.at(i)._is.size(); y++)
			{
				if (this->_semantics.at(i)._is.at(y).object == object)
				{
					found = true;
					break;
				}
			}
			if (found)
				break;
		}
	}
	return found;
}
/* check if a word is in the hasList of an object*/
bool semanticMemory::objetHasExist(const std::string objectName, const std::string has)
{
	bool found = false;
	for (unsigned int i = 0; i < this->_semantics.size(); i++)
	{
		if (this->_semantics.at(i).objectName == objectName)
		{
			for (unsigned int y = 0; y < this->_semantics.at(i)._has.size(); y++)
			{
				if (this->_semantics.at(i)._has.at(y).object == has)
				{
					found = true;
					break;
				}
			}
			if (found)
				break;
		}
	}
	return found;
}

/* check if a word is in the isAList of an object*/
bool semanticMemory::objetIsAExist(const std::string objectName, const std::string isA)
{
	bool found = false;
	for (unsigned int i = 0; i < this->_semantics.size(); i++)
	{
		if (this->_semantics.at(i).objectName == objectName)
		{
			for (unsigned int y = 0; y < this->_semantics.at(i)._isA.size(); y++)
			{
				if (this->_semantics.at(i)._isA.at(y) == isA)
				{
					found = true;
				}
			}
		}

	}
	return found;
}


void semanticMemory::createObject(const std::string objectName)
{
	OBJETSEMANTIC object;
	object.objectName = objectName;
	this->_semantics.push_back(object);
}

void semanticMemory::addIsA(const std::string objectName, std::string isA)
{
	bool found = false;
	for (unsigned int i = 0; i < this->_semantics.size(); i++)
	{
		if (this->_semantics.at(i).objectName == objectName)
		{
			this->_semantics.at(i)._isA.push_back(isA);
			found = true;
			break;
		}
	}
}
void semanticMemory::addIs(const std::string objectName, const std::string objectIs)
{
	bool found = false;
	for (unsigned int i = 0; i < this->_semantics.size(); i++)
	{
		if (this->_semantics.at(i).objectName == objectName)
		{
			OBJECTS obje;
			obje.object = objectIs;
			this->_semantics.at(i)._is.push_back(obje);
			found = true;
			break;
		}
	}
}
void semanticMemory::addIs(const std::string objectName, const std::string objectIs, const WH_ANSWERS whAnswers)
{
	bool found = false;
	for (unsigned int i = 0; i < this->_semantics.size(); i++)
	{
		if (this->_semantics.at(i).objectName == objectName)
		{
			OBJECTS obje;
			obje.object = objectIs;
			obje.whAnswers.push_back(whAnswers);
			this->_semantics.at(i)._is.push_back(obje);
			found = true;
			break;
		}
	}
}
void semanticMemory::addHas(const std::string objectName, const std::string objectHas)
{
	bool found = false;
	for (unsigned int i = 0; i < this->_semantics.size(); i++)
	{
		if (this->_semantics.at(i).objectName == objectName)
		{
			OBJECTS obje;
			obje.object = objectHas;
			this->_semantics.at(i)._has.push_back(obje);
			found = true;
			break;
		}
	}
}
void semanticMemory::addHas(const std::string objectName, const std::string objectHas, const WH_ANSWERS whAnswers)
{
	bool found = false;
	for (unsigned int i = 0; i < this->_semantics.size(); i++)
	{
		if (this->_semantics.at(i).objectName == objectName)
		{
			OBJECTS obje;
			obje.object = objectHas;
			obje.whAnswers.push_back(whAnswers);
			this->_semantics.at(i)._has.push_back(obje);
			found = true;
			break;
		}
	}
}
void semanticMemory::addCan(const std::string objectName, const std::string can)
{
	bool found = false;
	for (unsigned int i = 0; i < this->_semantics.size(); i++)
	{
		if (this->_semantics.at(i).objectName == objectName)
		{
			this->_semantics.at(i)._can.push_back(can);
			found = true;
			break;
		}
	}
}

void semanticMemory::addWHAnswer(const std::string objectName, const std::string verb, const std::string noun, const std::string wh, const std::string whAnswer)
{
	bool found = false;
	
	for (unsigned int i = 0; i < this->_semantics.size(); i++)
	{
		if (this->_semantics.at(i).objectName == objectName)
		{						
			if (verb == "IS")
			{
				for (unsigned int y = 0; y < this->_semantics.at(i)._is.size(); y++)
				{
					if (this->_semantics.at(i)._is.at(y).object == noun)
					{
						if (wh == "WHAT")
							this->_semantics.at(i)._is.at(y).whAnswers.at(0).whatWH = whAnswer;
						else if(wh == "WHO")
							this->_semantics.at(i)._is.at(y).whAnswers.at(0).WhoWH = whAnswer;
						else if (wh == "WHERE")
							this->_semantics.at(i)._is.at(y).whAnswers.at(0).whereWH = whAnswer;
						else if (wh == "WHEN")
							this->_semantics.at(i)._is.at(y).whAnswers.at(0).whenWH = whAnswer;
						else if (wh == "WHY")
							this->_semantics.at(i)._is.at(y).whAnswers.at(0).whyWH = whAnswer;
						else if (wh == "HOW")
							this->_semantics.at(i)._is.at(y).whAnswers.at(0).HowWH = whAnswer;

					}
				}				
			}
			else if (verb == "HAS")
			{
				for (unsigned int y = 0; y < this->_semantics.at(i)._has.size(); y++)
				{
					if (this->_semantics.at(i)._has.at(y).object == noun)
					{
						if (wh == "WHAT")
							this->_semantics.at(i)._has.at(y).whAnswers.at(0).whatWH = whAnswer;
						else if (wh == "WHO")
							this->_semantics.at(i)._has.at(y).whAnswers.at(0).WhoWH = whAnswer;
						else if (wh == "WHERE")
							this->_semantics.at(i)._has.at(y).whAnswers.at(0).whereWH = whAnswer;
						else if (wh == "WHEN")
							this->_semantics.at(i)._has.at(y).whAnswers.at(0).whenWH = whAnswer;
						else if (wh == "WHY")
							this->_semantics.at(i)._has.at(y).whAnswers.at(0).whyWH = whAnswer;
						else if (wh == "HOW")
							this->_semantics.at(i)._has.at(y).whAnswers.at(0).HowWH = whAnswer;

					}
				}
			}			
		}
	}
}

bool semanticMemory::getIsA(const std::string objectName, std::string &whAnswer)
{
	bool found = false;
	for (unsigned int i = 0; i < this->_semantics.size(); i++)
	{
		if (this->_semantics.at(i).objectName == objectName)
		{
			whAnswer = this->_semantics.at(i)._isA.at(0);
			found = true;
			break;
		}
	}
	return found;
}


bool semanticMemory::getIsA(const std::string objectName, std::vector<std::string> &whAnswers)
{
	bool found = false;
	for (unsigned int i = 0; i < this->_semantics.size(); i++)
	{
		if (this->_semantics.at(i).objectName == objectName)
		{
			whAnswers = this->_semantics.at(i)._isA;
			found = true;
			break;
		}
	}
	return found;
}


bool semanticMemory::getIs(const std::string objectName, const std::string object, const std::string wh, std::string &whAnswer)
{
	bool found = false;
	for (unsigned int i = 0; i < this->_semantics.size(); i++)
	{
		if (this->_semantics.at(i).objectName == objectName)
		{
			for (unsigned int y = 0; y < this->_semantics.at(i)._is.size(); y++)
			{
				if (this->_semantics.at(i)._is.at(y).object == object)
				{
					if (wh == "WHAT")
						whAnswer = this->_semantics.at(i)._is.at(y).whAnswers.at(0).whatWH;
					else if(wh == "WHERE")
						whAnswer = this->_semantics.at(i)._is.at(y).whAnswers.at(0).whereWH;
					else if (wh == "WHEN")
						whAnswer = this->_semantics.at(i)._is.at(y).whAnswers.at(0).whenWH;
					else if (wh == "WHY")
						whAnswer = this->_semantics.at(i)._is.at(y).whAnswers.at(0).whyWH;
					else if (wh == "WHO")
						whAnswer = this->_semantics.at(i)._is.at(y).whAnswers.at(0).WhoWH;
					else if (wh == "HOW")
						whAnswer = this->_semantics.at(i)._is.at(y).whAnswers.at(0).HowWH;
					break;
				}
			}
		}
		if (found)
			break;
	}
	return found;
}
bool semanticMemory::getHas(const std::string objectName, const std::string object, const std::string wh, std::string &whAnswer)
{
	bool found = false;
	for (unsigned int i = 0; i < this->_semantics.size(); i++)
	{
		if (this->_semantics.at(i).objectName == objectName)
		{
			for (unsigned int y = 0; y < this->_semantics.at(i)._has.size(); y++)
			{
				if (this->_semantics.at(i)._has.at(y).object == object)
				{
					if (wh == "WHAT")
						whAnswer = this->_semantics.at(i)._has.at(y).whAnswers.at(0).whatWH;
					else if (wh == "WHERE")
						whAnswer = this->_semantics.at(i)._has.at(y).whAnswers.at(0).whereWH;
					else if (wh == "WHEN")
						whAnswer = this->_semantics.at(i)._has.at(y).whAnswers.at(0).whenWH;
					else if (wh == "WHY")
						whAnswer = this->_semantics.at(i)._has.at(y).whAnswers.at(0).whyWH;
					else if (wh == "WHO")
						whAnswer = this->_semantics.at(i)._has.at(y).whAnswers.at(0).WhoWH;
					else if (wh == "HOW")
						whAnswer = this->_semantics.at(i)._has.at(y).whAnswers.at(0).HowWH;
					break;
				}
			}
		}
		if (found)
			break;
	}
	return found;
}

bool semanticMemory::getCan(const std::string objectName, std::string &whAnswer)
{
	bool found = false;
	for (unsigned int i = 0; i < this->_semantics.size(); i++)
	{
		if (this->_semantics.at(i).objectName == objectName)
		{
			whAnswer = this->_semantics.at(i)._can.at(0);
			found = true;
			break;
		}
	}
	return found;
}
bool semanticMemory::getCan(const std::string objectName, std::vector<std::string> &whAnswers)
{
	bool found = false;
	for (unsigned int i = 0; i < this->_semantics.size(); i++)
	{
		if (this->_semantics.at(i).objectName == objectName)
		{
			whAnswers = this->_semantics.at(i)._can;
			found = true;
			break;
		}
	}
	return found;
}