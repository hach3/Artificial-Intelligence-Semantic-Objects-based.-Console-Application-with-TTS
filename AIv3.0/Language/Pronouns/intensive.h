#ifndef INTENSIVE_H
#define INTENSIVE_H

#include <vector>
#include <string>

typedef struct {
	
	std::vector<std::string> _intensivePronouns;

} INTENSIVE_PRONOUNS;

class Intensive_Pronoun {

public:
	Intensive_Pronoun();
	~Intensive_Pronoun();

	void addIntensive(std::vector<std::string> intensivePronouns);

	bool isIntensive(std::string intensivePronouns);

	void getIntensiveAtPerson(std::string intensivePronoun, int person);

protected:
private:
	std::vector<INTENSIVE_PRONOUNS> _intensivePronounsList;

};
#endif //INTENSIVE_H