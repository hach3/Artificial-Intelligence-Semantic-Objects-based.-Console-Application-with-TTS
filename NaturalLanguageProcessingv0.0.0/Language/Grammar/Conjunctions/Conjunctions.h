#ifndef CONJUNCTIONS_H
#define CONJUNCTIONS_H


#include "..\..\Words.h"

/*
LORD MOTHER OF ALL PRONOUNS
*/


class Conjunctions : public Words {
public:
	Conjunctions(void);
	Conjunctions(string value, WORDS wordType, WORDS_TYPE type);
	~Conjunctions(void);

	string getInfinitiveForm();
	string getIngForm();
	string getPassiveForm();
	string getParticipateForm();
	vector<string> getPresentForm();
	vector<string> getPastForm();

protected:

private:

};

#endif //CONJUNCTIONS_H