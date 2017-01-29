#include "action.h"

Action_Verb::Action_Verb()
{
	this->init();
}
Action_Verb::~Action_Verb()
{
	this->_actionVerbsList.clear();
}

void Action_Verb::init()
{
	//Create action verbs
}

bool Action_Verb::isActionVerb(std::string word)
{
	bool found = false;

	for (unsigned int i = 0; i < this->_actionVerbsList.size(); i++)
	{
		if (this->_actionVerbsList.at(i).infinitiveForm == word || this->_actionVerbsList.at(i).gerundForm == word)
		{
			found = true;
			break;
		}
		for (unsigned int y = 0; y < this->_actionVerbsList.at(i).presentVerb.size(); y++)
		{
			if (this->_actionVerbsList.at(i).presentVerb.at(y) == word)
			{
				found = true;
				break;
			}
		}
		if (found == true)
		{
			break;
		}
	}
	return found;
}

bool Action_Verb::isInfinitive(std::string verb)
{
	bool found = false;
	for (unsigned int i = 0; i < this->_actionVerbsList.size(); i++)
	{
		if (this->_actionVerbsList.at(i).infinitiveForm == verb)
		{
			found = true;
		}
	}
	return found;
}
bool Action_Verb::isGerund(std::string verb)
{
	bool found = false;
	for (unsigned int i = 0; i < this->_actionVerbsList.size(); i++)
	{
		if (this->_actionVerbsList.at(i).gerundForm == verb)
		{
			found = true;
		}
	}
	return found;
}

std::string Action_Verb::getPresentVerbAt(std::string verb, int person)
{
	std::string presentVerbAtPerson;
	bool found = false;
	for (unsigned int i = 0; i < this->_actionVerbsList.size(); i++)
	{
		if (this->_actionVerbsList.at(i).infinitiveForm == verb)
		{
			presentVerbAtPerson = this->_actionVerbsList.at(i).presentVerb.at(person - 1);
			found = true;
			break;
		}
		for (unsigned int y = 0; y < this->_actionVerbsList.at(i).presentVerb.size(); y++)
		{
			if (this->_actionVerbsList.at(i).presentVerb.at(y) == verb)
			{
				presentVerbAtPerson = this->_actionVerbsList.at(i).presentVerb.at(person - 1);
				found = true;
				break;
			}
		}
		if (found == true)
		{
			break;
		}
	}
	return presentVerbAtPerson;
}
std::vector<std::string> Action_Verb::getPresent(std::string verb)
{
	bool found = false;
	std::vector<std::string> presentForm;
	for (unsigned int i = 0; i < this->_actionVerbsList.size(); i++)
	{
		if (this->_actionVerbsList.at(i).infinitiveForm == verb)
		{
			presentForm = this->_actionVerbsList.at(i).presentVerb;
			found = true;
			break;
		}
	}
	return presentForm;
}

void Action_Verb::addVerb(std::string infinitiveForm)
{
	std::vector<std::string> presentVerb;
	std::vector<std::string> relatedWords;
	ACTION_VERB verb = {infinitiveForm, "", presentVerb, relatedWords, false, false, false, false, false};
	this->_actionVerbsList.push_back(verb);
}
void Action_Verb::addVerb(std::string infinitiveForm, std::string gerundForm)
{
	std::vector<std::string> presentVerb;
	std::vector<std::string> relatedWords;
	ACTION_VERB verb = { infinitiveForm, gerundForm, presentVerb, relatedWords, false, false, false, false, false };
	this->_actionVerbsList.push_back(verb);
}

void Action_Verb::addVerb(std::string infinitiveForm, std::string gerundForm, std::vector<std::string> presentVerb, std::vector<std::string> relatedWords, bool isMental, bool isPhysical, bool isStateOfBeing, bool isTransitive, bool isIntransitive)
{
	
	ACTION_VERB verb = { infinitiveForm, gerundForm, presentVerb, relatedWords, isMental, isPhysical, isStateOfBeing, isTransitive, isIntransitive };
	this->_actionVerbsList.push_back(verb);
}

void Action_Verb::addRelatedWord(std::string verb, std::string word)
{
	bool found = false;
	for (unsigned int i = 0; i < this->_actionVerbsList.size(); i++)
	{
		if (this->_actionVerbsList.at(i).infinitiveForm == verb)
		{
			this->_actionVerbsList.at(i).relatedWords.push_back(word);
			found = true;
			break;
		}
		for (unsigned int y = 0; y < this->_actionVerbsList.at(i).presentVerb.size(); y++)
		{
			if (this->_actionVerbsList.at(i).presentVerb.at(y) == verb)
			{
				this->_actionVerbsList.at(i).relatedWords.push_back(word);
				found = true;
				break;
			}
		}
		if (found == true)
		{
			break;
		}
	}
}
void Action_Verb::setPresentForm(std::string verb, std::vector<std::string> presentForm)
{

}

void Action_Verb::setGerundForm(std::string verb, std::string gerundForm)
{

}
std::string Action_Verb::getGerundForm(std::string verb)
{

}

void Action_Verb::setMental(bool isMental, std::string verb)
{

}
void Action_Verb::setPhysical(bool isPhysical, std::string verb)
{

}
bool Action_Verb::isStateOfBeing(bool isStateOfBeing, std::string verb)
{

}

bool Action_Verb::isMental(std::string verb)
{

}
bool Action_Verb::isPhysical(std::string verb)
{

}
bool Action_Verb::isStateOfBeing(std::string verb)
{

}

void Action_Verb::setTransitive(bool isTransitive, std::string verb)
{

}
void Action_Verb::setIntransitive(bool isIntransitive, std::string verb)
{

}
bool Action_Verb::isTransitive(std::string verb)
{

}
bool Action_Verb::isIntransitive(std::string verb)
{

}