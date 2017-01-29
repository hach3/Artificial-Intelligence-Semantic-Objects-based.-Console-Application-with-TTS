#include "collective.h"

Collective_Noun::Collective_Noun()
{

}
Collective_Noun::~Collective_Noun()
{

}

/* CHECK IF THE NOUN IS ABSTRACT */
bool Collective_Noun::isCollective(std::string noun)
{
	return true;
}
/* CREATE A NEW ABSTRACT NAME */
void Collective_Noun::addCollectiveNoun(std::string singular)
{

}
void Collective_Noun::addCollectiveNoun(std::string singular, std::string plural)
{

}
void Collective_Noun::addCollectiveNoun(std::string singular, std::string plural, std::vector<std::string> relatedWords, bool isCountable, bool isConcrete, std::vector<std::string> senseCalled)
{

}

/* RETURN THE NOUN RELATED TO THE COLLECTIVE NOUN, for example, swarm will return insects */
std::string Collective_Noun::getRelatedNoun(std::string noun)
{
	return "Hello World";
}
void Collective_Noun::addRelatedWord(std::string noun, std::string relatedWord)
{

}

/* RETURN THE RELATED WORDS VECTOR OF A NOUN */
std::vector<std::string> Collective_Noun::getRelatedWords(std::string noun)
{
	std::vector<std::string> helloWorld;
	return helloWorld;
}
/* CHECK IF A NOUN IS RELATED TO A COLLECTIVE NOUN */
bool Collective_Noun::checkIfRelated(std::string relatedNoun)
{
	return true;
}

/* RETURN TRUE IF THE NOUN IS COUNTABLE */
bool Collective_Noun::isCountable(std::string noun)
{
	return true;
}
void Collective_Noun::setCountable(std::string noun, bool isCountable)
{

}
/* RETURN TRUE IF THE NOUN IS CONCRETE */
bool Collective_Noun::isConcrete(std::string noun)
{
	return true;
}
void Collective_Noun::setConcrete(std::string noun, bool isConcrete)
{

}
void Collective_Noun::setConcrete(std::string noun, bool isConcrete, std::vector<std::string> senseCalled)
{

}
void Collective_Noun::addSenseCalled(std::string noun, std::string senseCalled)
{

}

/* ALSO PUT THE SENSE CALLED IN VECTOR OUTPARAMETERS*/
bool Collective_Noun::isConcrete(std::string noun, std::vector<std::string> &senseCalled)
{
	return true;
}