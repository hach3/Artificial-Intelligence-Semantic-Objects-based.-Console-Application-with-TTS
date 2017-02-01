#ifndef PRONOUNS_H
#define PRONOUNS_H

#include <vector>
#include <string>
/*
LORD MOTHER OF ALL PRONOUNS
*/
class Pronouns {
public:
	
	Pronouns();
	Pronouns(std::string name);
	~Pronouns();

	std::string getName(void);

	bool isPronounInSentence(std::string sentence, std::string &pronoun);
	bool isPronounInSentence(std::vector<std::string> vectorSentence, std::string &pronoun);
protected:
	

private:
	std::string _name;
};

#endif //PRONOUNS_H