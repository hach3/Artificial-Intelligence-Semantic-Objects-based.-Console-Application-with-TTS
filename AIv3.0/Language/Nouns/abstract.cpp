#include "abstract.h"

/* CONSTRUCTOR*/
Abstract_Noun::Abstract_Noun()
{

}
/* DESTRUCTOR : CLEAR THE VECTOR OF ABSTRACT NOUNS */

Abstract_Noun::~Abstract_Noun()
{

}

/* INITIALISATION */
void Abstract_Noun::init()
{

}

/* CHECK IF THE NOUN IS ABSTRACT */
bool Abstract_Noun::isAbstract(std::string noun)
{
	return true;
}
/* CREATE A NEW ABSTRACT NAME */
void Abstract_Noun::addAbstactNoun(std::string singular)
{

}
void Abstract_Noun::addAbstractNoun(std::string singular, std::string plural)
{

}
void Abstract_Noun::addAbstractNoun(std::string singular, std::string plural, std::string concept, std::vector<std::string> relatedWords, bool isCountable)
{

}

/* RETURN THE CONCEPT OF THE ABSTRACT NOUN */
std::string Abstract_Noun::getConcept()
{
	return "helloWorld";
}
/* CHECK IF A CONCEPT IS INSIDE AN ABSTRACT NAME */
bool Abstract_Noun::checkIfConceptIn(std::string conceptName)
{
	return true;
}
void Abstract_Noun::setConcept(std::string singular, std::string concept)
{

}

/* RETURN THE RELATED WORDS VECTOR OF A NOUN */
std::vector<std::string> Abstract_Noun::getRelatedWords(std::string noun)
{
	std::vector<std::string> helloWorld;
	return helloWorld;
}

void Abstract_Noun::addRelatedWord(std::string noun, std::string relatedWord)
{

}
/* CHECK IF A NOUN IS RELATED TO AN ABSTRACT NOUN */
bool Abstract_Noun::checkIfRelated(std::string relatedNoun)
{
	return true;
}

/* RETURN TRUE IF THE NOUN IS COUNTABLE */
bool Abstract_Noun::isCountable(std::string noun)
{
	return true;
}
void Abstract_Noun::setCountable(std::string noun, bool isCountable)
{

}