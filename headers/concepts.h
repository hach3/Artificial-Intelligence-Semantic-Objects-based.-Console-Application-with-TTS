#ifndef CONCEPTS_H
#define CONCEPTS_H
/*
Concepts.h is used to create concepts vectors. It creates groups of words that represents the same concept.
Ex : The concept of "me" is represented by words like "Me", "I"...

*/
#include <vector>
#include <string>


class Concepts {
public:
	/* Basic Constructor */
	Concepts();
	/* Constructor with conceptName*/
	Concepts(std::string);
	/* Constructor with conceptName and conceptWords*/
	Concepts(std::string, std::vector<std::string>);
	/*Destructor*/
	~Concepts();

	/*
	Add a concept word to the concept
	*/
	void addConceptWords(std::string);

	/*
	Return all the concept words of the concept
	*/
	std::vector<std::string> getConceptWords();
	std::string getConceptName();

protected:
private:
	std::string _conceptName;
	std::vector<std::string> _conceptWords;

};
#endif //CONCEPTS_H
