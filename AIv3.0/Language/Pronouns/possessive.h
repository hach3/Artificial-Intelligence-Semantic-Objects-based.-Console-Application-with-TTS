#ifndef POSSESSIVE_H
#define POSSESSIVE_H

#include <vector>
#include <string>

typedef struct {
	std::string name;
	std::vector<std::string> possessivePronouns;

} POSSESSIVE_PRONOUN;

class Possessive_Pronoun {

public:
	Possessive_Pronoun();
	~Possessive_Pronoun();

	bool isPossessive(std::string word);

	void addPossessive(std::vector<std::string> possessivePronoun);
	void addPossessive(std::string name, std::vector<std::string> possessivePronoun);

	std::string getPossessiveByPos(std::string word, int person);

	bool isPlural(std::string possessivePronoun);

	

protected:
private:
	std::vector<POSSESSIVE_PRONOUN> _possessivePronounsList;

};
#endif //POSSESSIVE_H