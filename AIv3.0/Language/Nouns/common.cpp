#include "common.h"

Common_Noun::Common_Noun()
{
	this->init();
}

Common_Noun::~Common_Noun()
{
	this->_commonNounsList.clear();
}

void Common_Noun::init()
{
	/* CAR */
	std::vector<std::string> carRelatedWords;
	carRelatedWords.push_back("VEHICULE");
	std::vector<std::string> carSenseCalled;
	carSenseCalled.push_back("TOUCH");
	/* std::string singular, std::string plural, std::vector<std::string> relatedWords, bool isCountable, bool isConcrete, std::vector<std::string> senseCalled */
	this->addCommonNoun("CAR", "CARS", carRelatedWords, true, true, carSenseCalled);


	/* NAME */
	std::vector<std::string> nameRelatedWords;
	nameRelatedWords.push_back("FIRSTNAME");
	nameRelatedWords.push_back("IDENTITY");
	std::vector<std::string> nameSenseCalled;
	/* std::string singular, std::string plural, std::vector<std::string> relatedWords, bool isCountable, bool isConcrete, std::vector<std::string> senseCalled */
	this->addCommonNoun("NAME", "NAMES", nameRelatedWords, false, false, nameSenseCalled);



}

/* CHECK IF THE NOUN IS ABSTRACT */
bool Common_Noun::isCommon(std::string noun)
{
	bool found = false;
	for (unsigned int i = 0; i < this->_commonNounsList.size(); i++)
	{
		if (this->_commonNounsList.at(i)._nounSingular == noun || this->_commonNounsList.at(i)._nounPlural == noun)
		{
			found = true;
			break;
		}
	}
	return found;
}
/* CREATE A NEW ABSTRACT NAME */
void Common_Noun::addCommonNoun(std::string singular)
{
	/* ADDING NOUN */
	COMMON_NOUNS noun;
	noun._nounSingular = singular;
	noun._nounPlural = "";
	noun._isConcrete._isConcrete = false;
	noun._isCountable._isCountable = false;
	this->_commonNounsList.push_back(noun);


}
void Common_Noun::addCommonNoun(std::string singular, std::string plural)
{
	/* ADDING NOUN */
	COMMON_NOUNS noun;
	noun._nounSingular = singular;
	noun._nounPlural = plural;
	noun._isConcrete._isConcrete = false;
	noun._isCountable._isCountable = false;
	this->_commonNounsList.push_back(noun);

}
void Common_Noun::addCommonNoun(std::string singular, std::string plural, std::vector<std::string> relatedWords, bool isCountable, bool isConcrete, std::vector<std::string> senseCalled)
{
	/* ADDING NOUN */
	COMMON_NOUNS noun;
	noun._nounSingular = singular;
	noun._nounPlural = plural;
	noun._relatedWords = relatedWords;
	noun._isConcrete._isConcrete = isConcrete;
	noun._isConcrete._sensesCalled = senseCalled;
	noun._isCountable._isCountable = isCountable;
	this->_commonNounsList.push_back(noun);

}

/* RETURN THE RELATED WORDS VECTOR OF A NOUN */
std::vector<std::string> Common_Noun::getRelatedWords(std::string noun)
{
	bool found = false;
	std::vector<std::string> relatedWords;
	for (unsigned int i = 0; i < this->_commonNounsList.size(); i++)
	{
		if (this->_commonNounsList.at(i)._nounPlural == noun || this->_commonNounsList.at(i)._nounSingular == noun)
		{
			relatedWords = this->_commonNounsList.at(i)._relatedWords;
			found = true;
			break;
		}
	}
	return relatedWords;
}
/* CHECK IF A NOUN IS RELATED TO A COLLECTIVE NOUN */
bool Common_Noun::checkIfRelated(std::string noun, std::string relatedNoun)
{
	bool found = false;
	for (unsigned int i = 0; i < this->_commonNounsList.size(); i++)
	{
		if (this->_commonNounsList.at(i)._nounPlural == noun || this->_commonNounsList.at(i)._nounSingular == noun)
		{
			for (unsigned int y = 0; y < this->_commonNounsList.at(i)._relatedWords.size(); y++)
			{
				if (this->_commonNounsList.at(i)._relatedWords.at(y) == relatedNoun)
				{
					found = true;
					break;
				}
			}
		}
		if (found == true)
		{
			break;
		}
	}
	return found;
}
void Common_Noun::addRelatedWord(std::string noun, std::string relatedWord)
{
	bool found = false;
	for (unsigned int i = 0; i < this->_commonNounsList.size(); i++)
	{
		if (this->_commonNounsList.at(i)._nounPlural == noun || this->_commonNounsList.at(i)._nounSingular == noun)
		{
			this->_commonNounsList.at(i)._relatedWords.push_back(relatedWord);
			found = true;
			break;
		}
	
	}

}

/* RETURN TRUE IF THE NOUN IS COUNTABLE */
bool Common_Noun::isCountable(std::string noun)
{
	bool found = false;
	bool isCountable = false;
	for (unsigned int i = 0; i < this->_commonNounsList.size(); i++)
	{
		if (this->_commonNounsList.at(i)._nounPlural == noun || this->_commonNounsList.at(i)._nounSingular == noun)
		{
			isCountable = this->_commonNounsList.at(i)._isCountable._isCountable;
			found = true;
			break;
		}

	}
	return isCountable;
}
void Common_Noun::setCountable(std::string noun, bool isCountable)
{
	bool found = false;
	for (unsigned int i = 0; i < this->_commonNounsList.size(); i++)
	{
		if (this->_commonNounsList.at(i)._nounPlural == noun || this->_commonNounsList.at(i)._nounSingular == noun)
		{
			this->_commonNounsList.at(i)._isCountable._isCountable = isCountable;
			found = true;
			break;
		}

	}
}
/* RETURN TRUE IF THE NOUN IS CONCRETE */
bool Common_Noun::isConcrete(std::string noun)
{
	bool found = false;
	bool isConcrete = false;
	for (unsigned int i = 0; i < this->_commonNounsList.size(); i++)
	{
		if (this->_commonNounsList.at(i)._nounPlural == noun || this->_commonNounsList.at(i)._nounSingular == noun)
		{
			isConcrete = this->_commonNounsList.at(i)._isConcrete._isConcrete;
			found = true;
			break;
		}

	}
	return isConcrete;
}
void Common_Noun::setConcrete(std::string noun, bool isConcrete)
{
	bool found = false;
	for (unsigned int i = 0; i < this->_commonNounsList.size(); i++)
	{
		if (this->_commonNounsList.at(i)._nounPlural == noun || this->_commonNounsList.at(i)._nounSingular == noun)
		{
			this->_commonNounsList.at(i)._isConcrete._isConcrete = isConcrete;
			found = true;
			break;
		}

	}
}
void Common_Noun::setConcrete(std::string noun, bool isConcrete, std::vector<std::string> senseCalled)
{
	bool found = false;
	for (unsigned int i = 0; i < this->_commonNounsList.size(); i++)
	{
		if (this->_commonNounsList.at(i)._nounPlural == noun || this->_commonNounsList.at(i)._nounSingular == noun)
		{
			this->_commonNounsList.at(i)._isConcrete._isConcrete = isConcrete;
			this->_commonNounsList.at(i)._isConcrete._sensesCalled = senseCalled;
			found = true;
			break;
		}

	}
}
void Common_Noun::addSenseCalled(std::string noun, std::string senseCalled)
{
	bool found = false;
	for (unsigned int i = 0; i < this->_commonNounsList.size(); i++)
	{
		if (this->_commonNounsList.at(i)._nounPlural == noun || this->_commonNounsList.at(i)._nounSingular == noun)
		{
			this->_commonNounsList.at(i)._isConcrete._sensesCalled.push_back(senseCalled);
			found = true;
			break;
		}

	}
}
/* ALSO PUT THE SENSE CALLED IN VECTOR OUTPARAMETERS*/
bool Common_Noun::isConcrete(std::string noun, std::vector<std::string> &senseCalled)
{
	bool found = false;
	bool isConcrete = false;
	for (unsigned int i = 0; i < this->_commonNounsList.size(); i++)
	{
		if (this->_commonNounsList.at(i)._nounPlural == noun || this->_commonNounsList.at(i)._nounSingular == noun)
		{
			isConcrete = this->_commonNounsList.at(i)._isConcrete._isConcrete;
			senseCalled = this->_commonNounsList.at(i)._isConcrete._sensesCalled;
			found = true;
			break;
		}

	}
	return isConcrete;
}