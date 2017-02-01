#ifndef PRONOUNS_COLLECTION_H
#define PRONOUNS_COLLECTION_H

#include "Pronouns.h"
/*
LORD MOTHER OF ALL PRONOUNS COLLECTIONS
*/
class Pronouns_Collection {
public:
	Pronouns_Collection();
	~Pronouns_Collection();

	//Have to create virtual method here to have the same method name in all child
	virtual void init(void) = 0;

	virtual void addPronoun(Pronouns* pronoun) = 0;

	virtual Pronouns* getPronoun(std::string pronounName) = 0;
	virtual Pronouns* getPronoun(int index) = 0;


protected:


private:
	std::vector<Pronouns*> _pronounsList;
};


#endif //PRONOUNS_COLLECTION_H