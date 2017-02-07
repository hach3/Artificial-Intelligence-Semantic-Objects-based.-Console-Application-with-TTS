#ifndef ABSTRACT_NOUNS_H
#define ABSTRACT_NOUNS_H

#include "Nouns.h"


class Abstract_Nouns : public Nouns {
public:
	Abstract_Nouns(string value, WORDS wordType, WORDS_TYPE type);
	Abstract_Nouns(string value, bool isPlural, WORDS wordType, WORDS_TYPE type);
	~Abstract_Nouns();
protected:
private:
};

#endif //ABSTRACT_NOUNS_H
