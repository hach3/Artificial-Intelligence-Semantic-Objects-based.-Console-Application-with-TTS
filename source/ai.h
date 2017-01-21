#ifndef AI_H
#define AI_H
/*
This class does create an AI.

*/
#include <string>
#include "concepts.h"
#include "memory.h"
enum Emotions {
	LOVE,
	JOY,
	SURPRISE,
	ANGER,
	SADNESS,
	FEAR
};
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


	/* Turn a string to uppercase and return it. I use it to turn the userSentence concepts to uppercase to compare them with the AI's concepts*/
	std::string putToUpperCase(std::string s);

	/* Extract the word of a string in a vector and return it*/
	std::vector<std::string> split(const std::string& s);


	std::string sentenceToSay;
	int _love;
	int _joy;
	int _surprise;
	int _anger;
	int _sadness;
	int _fear;
	std::vector<Memory> _memories;
private:
	
	
};

#endif //AI_H
