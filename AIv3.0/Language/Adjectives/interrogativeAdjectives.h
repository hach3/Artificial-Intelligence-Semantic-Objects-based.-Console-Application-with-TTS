#ifndef INTERROGATIVE_ADJECTIVES_H
#define INTERROGATIVE_ADJECTIVES_H

#include <vector>
#include <string>
/*
THIS IS A WH THAT PRECEDE A NOUN
How many shit do you have ?
which car do you like ?

*/
typedef struct {
	std::string wh;

	std::string concept;
}INTERROGATIVE_ADJECTIVES;

class Interrogative_Adjectives {

public:
	Interrogative_Adjectives(void);
	~Interrogative_Adjectives(void);

	void init(void);

	void addInterrogative(std::string wh);
	void addInterrogative(std::string wh, std::string concept);

	bool isInterrogative(std::string word);
	bool isInterrogativeInSentence(std::string Sentence);
	bool isInterrogativeInVector(std::vector<std::string> vectorSentence);

	bool isConcept(std::string wh, std::string concept);
	std::string getConcept(std::string wh);

protected:
private:
	std::vector<INTERROGATIVE_ADJECTIVES> _interrogativeList;
};

#endif//INTERROGATIVE_ADJECTIVES_H