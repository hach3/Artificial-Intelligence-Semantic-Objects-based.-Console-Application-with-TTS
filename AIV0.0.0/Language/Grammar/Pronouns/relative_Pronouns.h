#ifndef RELATIVE_PRONOUNS_H
#define RELATIVE_PRONOUNS_H
#include "Pronouns.h"
/*
Source: https://learnenglish.britishcouncil.org/en/english-grammar/pronouns/relative-pronouns

Subject		Object		Possessive
who			who(m)		whose
which		which		whose
that		that

We use who and whom for people, and which for things.
Or we can use that for people or things.

We use relative pronouns:
• after a noun, to make it clear which person or thing we are talking about: the house that Jack built
• to tell us more about a person or thing: My mother, who was born overseas, has always been a great traveller.
We use whose as the possessive form of who: This is George, whose brother went to school with me.
But nowadays we normally use who: This is George, who you met at our house last year.

When whom or which have a preposition the preposition can come at the beginning of the clause...I had an uncle in Germany, from who[m] I inherited a bit of money.
… or at the end of the clause: I had an uncle in Germany who[m] I inherited a bit of money from.

We can use that at the beginning of the clause: I had an uncle in Germany that I inherited a bit of money from.
*/
class Relative_Pronouns : public Pronouns {
public:
	
	Relative_Pronouns();
	Relative_Pronouns(std::string name, bool isSubject, bool isObject, bool isPossessive);
	~Relative_Pronouns();

	bool isSubject(void);
	bool isObject(void);
	bool isPossessive(void);
protected:
private:
	bool _isSubject;
	bool _isObject;
	bool _isPossessive;
};
#endif //RELATIVE_PRONOUNS_H