#ifndef POSSESSIVE_PRONOUNS_H
#define POSSESSIVE_PRONOUNS_H
#include "Pronouns.h"
/*
Source : https://learnenglish.britishcouncil.org/en/english-grammar/possessives/possessives-pronouns
Singular : Mine, yours, his, hers, its
Plural : Ours, yours, theirs

We can use a possessive pronoun instead of a noun phrase: Is that John’s car?	 	No, it’s [my car]	>	No, it’s mine.

We can use possessive pronouns after of.

We can say:

Susan is one of my friends.
or
Susan is a friend of mine.
but not
Susan is a friend of me


*/
class Possessive_Pronouns : public Pronouns{
public:
	Possessive_Pronouns();
	Possessive_Pronouns(std::string possessive, bool isPlural, int person);
	~Possessive_Pronouns();


	bool isPlural();
	int getPerson();

protected:
private:

	bool _isPlural;
	int _person; // 1er, 2eme, 3eme
};
#endif //POSSESSIVE_PRONOUNS_H