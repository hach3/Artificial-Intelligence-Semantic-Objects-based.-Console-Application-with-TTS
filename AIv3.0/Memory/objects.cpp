#include "objects.h"


Objects::Objects()
{

}
Objects::~Objects()
{
	this->_objectsList.clear();
}

void Objects::init()
{

}
void Objects::createObject(std::string objectName)
{
	OBJECTS object;
	object.objectName = objectName;
	this->_objectsList.push_back(object);
}
void Objects::createObject(std::string objectName, std::string verb)
{
	OBJECTS object;
	object.objectName = objectName;
	object.verb = verb;
	this->_objectsList.push_back(object);
}
void Objects::createObject(std::string objectName, std::string verb, std::string objectConcept)
{
	OBJECTS object;
	object.objectName = objectName;
	object.verb = verb;
	object.object = objectConcept;
	this->_objectsList.push_back(object);
}
void Objects::createObject(std::string objectName, std::string verb, std::string objectConcept, std::vector<WH_ANSWERS> whAnswers)
{
	OBJECTS object;
	object.objectName = objectName;
	object.verb = verb;
	object.object = objectConcept;
	object.whAnswers = whAnswers;
	this->_objectsList.push_back(object);
}


void Objects::addWHanswer(std::string objectName, std::string verb, std::string object, std::string wh, std::string whAnswer)
{
	bool found = false;
	for (unsigned int i = 0; i < this->_objectsList.size(); i++)
	{
		if (this->_objectsList.at(i).objectName == objectName &&
			this->_objectsList.at(i).verb == verb &&
			this->_objectsList.at(i).object == object)
		{
			if (wh == "WHAT")
			{
				this->_objectsList.at(i).whAnswers.at(0).whatWH = whAnswer;
			}
			else if (wh == "WHY")
			{
				this->_objectsList.at(i).whAnswers.at(0).whyWH = whAnswer;
			}
			else if (wh == "WHO")
			{
				this->_objectsList.at(i).whAnswers.at(0).WhoWH = whAnswer;
			}
			else if (wh == "WHERE")
			{
				this->_objectsList.at(i).whAnswers.at(0).whereWH = whAnswer;
			}
			else if (wh == "WHEN")
			{
				this->_objectsList.at(i).whAnswers.at(0).whenWH = whAnswer;
			}
			else if (wh == "HOW")
			{
				this->_objectsList.at(i).whAnswers.at(0).HowWH = whAnswer;
			}
			found = true;
			break;
		}
	}
}

std::string Objects::getWHAnswer(std::string objectName, std::string verb, std::string object, std::string wh)
{
	bool found = false;
	std::string whAnswer;
	for (unsigned int i = 0; i < this->_objectsList.size(); i++)
	{
		if (this->_objectsList.at(i).objectName == objectName &&
			this->_objectsList.at(i).verb == verb &&
			this->_objectsList.at(i).object == object)
		{
			if (wh == "WHAT")
			{
				whAnswer = this->_objectsList.at(i).whAnswers.at(0).whatWH;
			}
			else if (wh == "WHY")
			{
				whAnswer = this->_objectsList.at(i).whAnswers.at(0).whyWH;
			}
			else if (wh == "WHO")
			{
				whAnswer = this->_objectsList.at(i).whAnswers.at(0).WhoWH;
			}
			else if (wh == "WHERE")
			{
				whAnswer = this->_objectsList.at(i).whAnswers.at(0).whereWH;
			}
			else if (wh == "WHEN")
			{
				whAnswer = this->_objectsList.at(i).whAnswers.at(0).whenWH;
			}
			else if (wh == "HOW")
			{
				whAnswer = this->_objectsList.at(i).whAnswers.at(0).HowWH;
			}
			found = true;
			break;
		}
		
	}
	return whAnswer;
}

bool Objects::isVerbInObjet(std::string objectName, std::string verb)
{
	bool found = false;
	bool isVerbExist = false;
	for (unsigned int i = 0; i < this->_objectsList.size(); i++)
	{
		if (this->_objectsList.at(i).objectName == objectName && this->_objectsList.at(i).verb == verb)
		{
			found = true;
			isVerbExist = true;
			break;
		}
	}
	return isVerbExist;
}
std::string Objects::getVerbForObject(std::string objectName, std::string object)
{
	bool found = false;
	std::string verbForObject;
	for (unsigned int i = 0; i < this->_objectsList.size(); i++)
	{
		if (this->_objectsList.at(i).objectName == objectName && this->_objectsList.at(i).object == object)
		{
			found = true;
			verbForObject = this->_objectsList.at(i).verb;
			break;
		}
	}
	return verbForObject;
}
std::vector<std::string> Objects::getVerbsForObject(std::string objectName, std::string object)
{
	bool found = false;
	std::vector<std::string> verbsForObject;
	for (unsigned int i = 0; i < this->_objectsList.size(); i++)
	{
		if (this->_objectsList.at(i).objectName == objectName && this->_objectsList.at(i).object == object)
		{
			found = true;
			verbsForObject.push_back(this->_objectsList.at(i).verb);	
		}
	}
	return verbsForObject;
}

bool Objects::isObjectInObject(std::string objectName, std::string verb)
{
	bool found = false;
	bool isObject = false;
	for (unsigned int i = 0; i < this->_objectsList.size(); i++)
	{
		if (this->_objectsList.at(i).objectName == objectName && this->_objectsList.at(i).verb == verb)
		{
			if (this->_objectsList.at(i).object != "")
			{
				found = true;
				isObject = true;
			}
		}
	}
	return isObject;
}