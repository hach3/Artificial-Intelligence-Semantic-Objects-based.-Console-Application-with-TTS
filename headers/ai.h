#ifndef AI_H
#define AI_H
/*
This class does create an AI.

*/
#include <string>
#include "concepts.h"

class AI {
public:
	/*Basic constructor*/
	AI();
	/*Constructor with name*/
	AI(std::string);
	/*Destructor*/
	~AI();

	/*
	Accessors
	*/
	void setAIName(std::string);
	std::string getAIName();

	void addConcept(Concepts);
	std::vector<Concepts> getConcepts();
	/*Methods*/
	
	

protected:
	std::string _AIName;
	std::vector<Concepts> _concepts;
	std::string putToUpperCase(std::string s);

	std::vector<std::string> split(const std::string& s);
private:
	
	
};

#endif //AI_H
