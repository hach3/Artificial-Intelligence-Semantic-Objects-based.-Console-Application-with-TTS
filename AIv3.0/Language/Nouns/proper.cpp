#include "proper.h"

Proper_Noun::Proper_Noun()
{

}
Proper_Noun::~Proper_Noun()
{

}

/* CHECK IF THE NOUN IS ABSTRACT */
bool Proper_Noun::isProper(std::string noun)
{
	return true;
}
/* CREATE A NEW ABSTRACT NAME */
void Proper_Noun::addProperNoun(std::string singular)
{

}
void Proper_Noun::addProperNoun(std::string singular, std::string plural)
{

}
void Proper_Noun::addProperNoun(std::string singular, std::string plural, std::string commonNounTarget)
{

}
void Proper_Noun::addProperNoun(std::string singular, std::string plural, std::string commonNounTarget, std::vector<std::string> relatedWords, bool isConcrete, std::vector<std::string> senseCalled)
{

}

/*
RETURN THE COMMON NOUN TARGET
*/
std::string Proper_Noun::getCommonNounTarget(std::string noun)
{
	return "helloWorld";
}
void Proper_Noun::setCommonNounTarget(std::string noun, std::string commonNounTarget)
{

}

/* RETURN THE RELATED WORDS VECTOR OF A NOUN */
std::vector<std::string> Proper_Noun::getRelatedWords(std::string noun)
{
	std::vector<std::string> helloWorld;
	return helloWorld;
}
void Proper_Noun::addRelatedWord(std::string noun, std::string relatedWord)
{

}

/* CHECK IF A NOUN IS RELATED TO A COLLECTIVE NOUN */
bool Proper_Noun::checkIfRelated(std::string relatedNoun)
{
	return true;
}
/* RETURN TRUE IF THE NOUN IS CONCRETE */
bool Proper_Noun::isConcrete(std::string noun)
{
	return true;
}
void Proper_Noun::setConcrete(std::string noun, bool isConcrete)
{

}
void Proper_Noun::setConcrete(std::string noun, bool isConcrete, std::vector<std::string> senseCalled)
{

}
void Proper_Noun::addSense(std::string noun, std::string senseCalled)
{

}
/* ALSO PUT THE SENSE CALLED IN VECTOR OUTPARAMETERS*/
bool Proper_Noun::isConcrete(std::string noun, std::vector<std::string> &senseCalled)
{
	return true;
}