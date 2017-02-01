#include "Verbs.h"

Verbs::Verbs()
{

}
Verbs::Verbs(std::string verbalBase, std::string ingForm,
	std::string _pastForm, std::string pastParticipate)
{
	this->_verbalBase = verbalBase;
	this->_ingForm = ingForm;
	this->_pastForm = _pastForm;
	this->_pastParticipate = pastParticipate;
}
Verbs::Verbs(std::string verbalBase, std::string ingForm,
	std::string _pastForm, std::string pastParticipate,
	std::vector<std::string> simplePresent, std::vector<std::string> simplePast)
{
	this->_verbalBase = verbalBase;
	this->_ingForm = ingForm;
	this->_pastForm = _pastForm;
	this->_pastParticipate = pastParticipate;
	this->_simplePresent = simplePresent;
	this->_simplePast = simplePast;
}
Verbs::~Verbs()
{

}

std::string Verbs::getVerbalBase()
{
	return this->_verbalBase;
}
std::string Verbs::getIngForm()
{
	return this->_ingForm;
}
std::string Verbs::getPastForm()
{
	return this->_pastForm;
}
std::string Verbs::getPastParticipate()
{
	return this->_pastParticipate;
}

std::string Verbs::getPresentVerbAtPerson(int person)
{
	std::string verbAtPresent;
	verbAtPresent = this->_simplePresent.at(person - 1);
	return verbAtPresent;
}
std::string Verbs::getPastVerbAtPerson(int person)
{
	std::string verbAtPast;
	verbAtPast = this->_simplePast.at(person - 1);
	return verbAtPast;
}
bool Verbs::checkIfVerbInSentence(std::string sentence, std::string &verb)
{
	bool found = false;
	size_t foundBV;
	size_t foundIng;
	size_t foundPast;
	size_t foundParticipate;
	foundBV = sentence.find(this->getVerbalBase());
	foundIng = sentence.find(this->getIngForm());
	foundPast = sentence.find(this->getPastForm());
	foundParticipate = sentence.find(this->getPastParticipate());
	if (foundPast != std::string::npos)
	{
		found = true;
		verb = this->getPastForm();
	}
	else if (foundParticipate != std::string::npos)
	{
		found = true;
		verb = this->getPastParticipate();
	}
	else if (foundBV != std::string::npos)
	{
		found = true;
		verb = this->getVerbalBase();
	}
	else if (foundIng != std::string::npos)
	{
		found = true;
		verb = this->getIngForm();
	}
	return found;
}
bool Verbs::checkIfVerbInSentence(std::vector<std::string> vectorSentence, std::string &verb)
{
	bool found = false;
	for (unsigned int i = 0; i < vectorSentence.size(); i++)
	{
		if (this->getVerbalBase() == vectorSentence.at(i) ||
			this->getIngForm() == vectorSentence.at(i) ||
			this->getPastForm() == vectorSentence.at(i) ||
			this->getPastParticipate() == vectorSentence.at(i))
		{
			found = true;
			verb = vectorSentence.at(i);
			break;
		}
	}
	return found;
}