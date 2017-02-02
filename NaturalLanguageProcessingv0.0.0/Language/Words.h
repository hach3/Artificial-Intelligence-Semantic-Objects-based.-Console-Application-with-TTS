#ifndef WORDS_H
#define WORDS_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

enum WORDS_TYPE {
	DEMONSTRATIVE_PRONOUNS,
	RELATIVE_PRONOUNS,
	REFLEXIVE_PRONOUNS,
	POSSESSIVE_PRONOUNS,
	PERSONAL_PRONOUNS,
	OBJECT_PRONOUNS,
	SUBJECT_PRONOUNS,
	INDEFINITE_PRONOUNS,
	INTERROGATIVE_PRONOUNS,
	RECIPROCAL_PRONOUNS,
	INTENSIVE_PRONOUNS
};

class Words {
public:
	Words();
	Words(string value, WORDS_TYPE type);
	~Words();

	string getValue(void);
	WORDS_TYPE getType(void);


protected:
	void setValue(string value);
	void setType(WORDS_TYPE type);
private:
	string _value;
	WORDS_TYPE _type;
};

#endif //WORDS_H