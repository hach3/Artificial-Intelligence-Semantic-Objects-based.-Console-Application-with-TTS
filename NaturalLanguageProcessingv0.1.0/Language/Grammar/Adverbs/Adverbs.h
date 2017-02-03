#ifndef ADVERBS_H
#define ADVERBS_H


#include "..\..\Words.h"


/*
LORD MOTHER OF ALL PRONOUNS
*/


class Adverbs : public Words {
public:
	Adverbs(void);
	Adverbs(string value, WORDS wordType, WORDS_TYPE type);
	~Adverbs(void);

	string getInfinitiveForm();
	string getIngForm();
	string getPassiveForm();
	string getParticipateForm();
	vector<string> getPresentForm();
	vector<string> getPastForm();

protected:

private:

};

#endif //ADVERBS_H
