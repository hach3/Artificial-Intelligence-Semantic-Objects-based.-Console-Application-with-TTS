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
	Nouns(string value, bool isPlural, WORDS wordType, WORDS_TYPE type);
	~Nouns(void);
	
	virtual bool isPlural();

protected:
	bool _isPlural;
private:
	
};

#endif //NOUNS_H
