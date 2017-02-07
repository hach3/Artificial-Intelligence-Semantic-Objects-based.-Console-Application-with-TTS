#ifndef PRONOUNS_H
#define PRONOUNS_H


#include "..\..\Words.h"

/*
LORD MOTHER OF ALL PRONOUNS
*/


class Pronouns : public Words {
public:
	Pronouns(void);

	Pronouns(string value, WORDS wordType, WORDS_TYPE type);
	~Pronouns(void);

	virtual bool isPlural();

protected:	

private:

};

#endif //PRONOUNS_H