#include "concepts.h"

/* Basic Constructor */
Concepts::Concepts()
{

}

/* Constructor with conceptName*/
Concepts::Concepts(std::string conceptName)
{
	this->_conceptName = conceptName;
}

/* Constructor with conceptName and conceptWords*/
Concepts::Concepts(std::string conceptName, std::vector<std::string> conceptWords)
{
	this->_conceptName = conceptName;
	for (unsigned int i = 0; i < conceptWords.size(); i++)
	{
		this->_conceptWords.push_back(conceptWords.at(i));
	}
}

/*Destructor*/
Concepts::~Concepts()
{
	this->_conceptWords.clear();
}

/*
Add a concept word to the concept
*/
void Concepts::addConceptWords(std::string conceptWord)
{
	this->_conceptWords.push_back(conceptWord);
}

/*
Return all the concept words of the concept
*/
std::vector<std::string> Concepts::getConceptWords()
{
	return this->_conceptWords;
}

std::string Concepts::getConceptName()
{
	return this->_conceptName;
}