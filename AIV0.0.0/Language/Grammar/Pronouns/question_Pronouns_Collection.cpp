#include "question_Pronouns_Collection.h"

Question_Pronouns_Collection::Question_Pronouns_Collection() :
	Pronouns_Collection()
{
	this->init();
}
Question_Pronouns_Collection::~Question_Pronouns_Collection()
{
	for (unsigned int i = 0; i < this->_questionPronounsList.size(); i++)
	{
		delete this->getPronoun(i);
	}
	this->_questionPronounsList.clear();
}

void Question_Pronouns_Collection::init(void)
{
	this->addPronoun(new Question_Pronouns("WHO", true, false, false, false));
	this->addPronoun(new Question_Pronouns("WHOSE", false, true, false, false));
	this->addPronoun(new Question_Pronouns("WHAT", false, false, true, false));
	this->addPronoun(new Question_Pronouns("WHICH", false, false, false, true));
}

void Question_Pronouns_Collection::addPronoun(Question_Pronouns* s)
{
	this->_questionPronounsList.push_back(s);
}

Question_Pronouns* Question_Pronouns_Collection::getPronoun(std::string name)
{
	Question_Pronouns* a = NULL;
	for (unsigned int i = 0; i < this->_questionPronounsList.size(); i++)
	{
		if (this->getPronoun(i)->getName() == name)
		{
			a = this->getPronoun(i);
		}
	}
	return a;
}
Question_Pronouns* Question_Pronouns_Collection::getPronoun(int index)
{
	Question_Pronouns* a = NULL;
	a = this->_questionPronounsList.at(index);
	return a;
}
