#ifndef REFLEXIVE_H
#define REFLEXIVE_H

#include <vector>
#include <string>

typedef struct {
	std::vector<std::string> _reflexivePronouns;

} REFLEXIVE_PRONOUN;

class Reflexive_Pronoun {

public:
	Reflexive_Pronoun();
	~Reflexive_Pronoun();

	bool isReflexive(std::string word);

	void addReflexive(std::vector<std::string> reflexivePronouns);

protected:
private:
	std::vector<REFLEXIVE_PRONOUN> _reflexivePronounsList;

};
#endif //REFLEXIVE_H