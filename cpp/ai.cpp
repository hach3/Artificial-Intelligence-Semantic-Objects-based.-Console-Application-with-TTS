#include "ai.h"
#include <iostream>
#include <algorithm>
/*
This class does create an AI.

*/

/*Basic constructor*/
AI::AI()
{

}
/*Constructor with name*/
AI::AI(std::string name)
{
	this->_AIName = name;
}
/*Destructor*/
AI::~AI()
{
	
}

/*Accessors*/
void AI::setAIName(std::string name)
{
	this->_AIName = name;
}
std::string AI::getAIName()
{
	return this->_AIName;
}

void AI::addConcept(Concepts c)
{

}
std::vector<Concepts> AI::getConcepts()
{
	return this->_concepts;
}

std::string AI::putToUpperCase(std::string s)
{
	std::transform(s.begin(), s.end(), s.begin(), ::toupper);

	return s;
}

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