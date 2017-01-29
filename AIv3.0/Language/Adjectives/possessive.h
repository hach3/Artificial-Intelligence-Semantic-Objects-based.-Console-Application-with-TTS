#ifndef POSSESSIVE_H
#define POSSESSIVE_H

#include <vector>
#include <string>

typedef struct {
	std::string name;
	std::vector<std::string> possessiveAdjectives;


} POSSESSIVE_ADJECTIVES;

class Possessive_Adjectives {
public:
	Possessive_Adjectives();
	~Possessive_Adjectives();

	void init();

	bool isPossessive(std::string word);

	void addPossessive(std::vector<std::string> possessiveAdjectives);
	void addPossessive(std::string name, std::vector<std::string> possessiveAdjectives);

	std::string getPossessiveByPos(std::string word, int person);

	bool isPlural(std::string possessiveAdjectives);

protected:
private:
	std::vector<POSSESSIVE_ADJECTIVES> _possessiveAdjectivesList;
};

#endif //POSSESSIVE_H