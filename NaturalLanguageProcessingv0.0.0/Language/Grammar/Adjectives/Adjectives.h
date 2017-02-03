#ifndef ADJECTIVES_H
#define ADJECTIVES_H

#include "..\..\Words.h"

/*
LORD MOTHER OF ALL PRONOUNS
*/


class Adjectives : public Words {
public:
	Adjectives(void);
	Adjectives(string value, WORDS wordType, WORDS_TYPE type);
	~Adjectives(void);

	string getInfinitiveForm();
	string getIngForm();
	string getPassiveForm();
	string getParticipateForm();
	vector<string> getPresentForm();
	vector<string> getPastForm();

protected:

private:

};

#endif //ADJECTIVES
