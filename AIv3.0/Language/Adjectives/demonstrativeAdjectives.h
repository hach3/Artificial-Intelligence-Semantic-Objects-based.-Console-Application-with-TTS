#ifndef DEMONSTRATIVEADJECTIVES_H
#define DEMONSTRATIVEADJECTIVES_H

#include <vector>
#include <string>
typedef struct {
	std::string singular;
	std::string plural;

	bool isFar; //if true, alors that, else this.
} DEMONSTRATIVE_ADJECTIVES;

class Demonstrative_Adjectives{
public:
	Demonstrative_Adjectives();
	~Demonstrative_Adjectives();

	void init(void);

	void addDemonstrative(std::string singular, std::string plural);
	void addDemonstrative(std::string singular, std::string plural, bool isFar);
	
	bool isDemonstrative(std::string word);
	bool isDemonstrativeInSentence(std::string sentence);
	bool isDemonsrativeInVector(std::vector<std::string> vectorSentence);

	std::string getDemonstrative(bool isPlural, bool isFar);

protected:
private:
	std::vector<DEMONSTRATIVE_ADJECTIVES> _demonstrativeList;
};
#endif//DEMONSTRATIVEADJECTIVES_H