#include "ai.h"
#include <iostream>
#include <algorithm>


AI::AI()
{
    this->Initialization();
}
AI::~AI()
{
    //Delete all the content in collectionner
    this->_souvenirs.deleteAll();

    this->_conceptAux.deleteAll();
    this->_conceptBe.deleteAll();
    this->_conceptComplement.deleteAll();
    this->_ConceptComplementChild.deleteAll();
    this->_ConceptSubject.deleteAll();
    this->_ConceptSubjectChild.deleteAll();
    this->_ConceptVerb.deleteAll();
    this->_ConceptWH.deleteAll();
    this->_Expression.deleteAll();
}

void AI::Initialization()
{
    //Example of initialization
    this->_souvenirs.Init();

    this->_conceptAux.Init();
    this->_conceptBe.Init();
    this->_conceptComplement.Init();
    this->_ConceptComplementChild.Init();
    this->_ConceptSubject.Init();
    this->_ConceptSubjectChild.Init();
    this->_ConceptVerb.Init();
    this->_ConceptWH.Init();
    this->_Expression.Init();
}


/* Turn a string to uppercase and return it. I use it to turn the userSentence concepts to uppercase to compare them with the AI's concepts*/
std::string AI::putToUpperCase(std::string s)
{
	std::transform(s.begin(), s.end(), s.begin(), ::toupper);

	return s;
}

/* Extract the word of a string in a vector and return it*/
std::vector<std::string> AI::split(const std::string& s)
{
	std::vector<std::string> ret;
	typedef std::string::size_type string_size;
	string_size i = 0;

	// invariant: we have processed characters [original value of i, i)
	while (i != s.size()) {
		// ignore leading blanks
		// invariant: characters in range [original i, current i) are all spaces
		while (i != s.size() && isspace(s[i]))
			++i;

		// find end of next word
		string_size j = i;
		// invariant: none of the characters in range [original j, current j)is a space
		while (j != s.size() && !isspace(s[j]))
			j++;

		// if we found some nonwhitespace characters
		if (i != j) {
			// copy from s starting at i and taking j - i chars
			ret.push_back(s.substr(i, j - i));
			i = j;
		}
	}
	return ret;
}
