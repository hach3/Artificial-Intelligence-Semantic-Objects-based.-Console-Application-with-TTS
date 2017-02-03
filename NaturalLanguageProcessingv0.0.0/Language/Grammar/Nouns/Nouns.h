#ifndef NOUNS_H
#define NOUNS_H


#include "..\..\Words.h"

/*
LORD MOTHER OF ALL PRONOUNS
*/


class Nouns : public Words {
public:
	Nouns(void);
	Nouns(string value, WORDS wordType, WORDS_TYPE type);
	~Nouns(void);

	string getInfinitiveForm();
	string getIngForm();
	string getPassiveForm();
	string getParticipateForm();
	vector<string> getPresentForm();
	vector<string> getPastForm();

protected:

private:

};

#endif //NOUNS_H