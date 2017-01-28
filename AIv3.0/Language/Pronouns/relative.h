#ifndef RELATIVE_H
#define RELATIVE_H

#include <vector>
#include <string>

typedef struct {
	std::string relativePronoun;

	std::vector<std::string> relatedWords; //it can be place, people, things, animals, ideas

} RELATIVE_PRONOUN;

class Relative_Pronoun {

public:
	Relative_Pronoun();
	~Relative_Pronoun();

	bool isRelativePronoun(std::string word);

	void addRelativePronoun(std::string pronoun, std::vector<std::string> relatedWords);

	void addRelatedWord(std::string pronoun, std::string relatedWord);

protected:
private:
	std::vector<RELATIVE_PRONOUN> _relativePronounsList;

};
#endif //RELATIVE_H