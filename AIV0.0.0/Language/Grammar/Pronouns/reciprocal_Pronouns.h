#ifndef RECIPROCAL_PRONOUNS_H
#define RECIPROCAL_PRONOUNS_H
#include "Pronouns.h"
/*
Source: https://learnenglish.britishcouncil.org/en/english-grammar/pronouns/reciprocal-pronouns-each-other-and-one-another

We use the reciprocal pronouns each other and one another when two or more people do the same thing. 
Traditionally, each other refers to two people and one another refers to more than two people, but this distinction is disappearing in modern English.

Peter and Mary helped one another. = Peter helped Mary and Mary helped Peter.

-We sent each other Christmas cards. = We sent them a Christmas card and they sent us a Christmas card.


-We also use the possessive forms each other’s and one another’s: They helped to look after each other’s children.

NOTE: We do not use reciprocal pronouns as the subject of a clause.
*/
class Reciprocal_Pronouns : public Pronouns {
public:
	Reciprocal_Pronouns();
	Reciprocal_Pronouns(std::string name);
	~Reciprocal_Pronouns();

protected:
private:
};
#endif //RECIPROCAL_PRONOUNS_H