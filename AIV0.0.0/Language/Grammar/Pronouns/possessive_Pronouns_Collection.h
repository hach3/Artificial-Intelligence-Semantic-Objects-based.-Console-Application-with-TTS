#ifndef POSSESSIVE_PRONOUNS_COLLECTION_H
#define POSSESSIVE_PRONOUNS_COLLECTION_H

#include "possessive_Pronouns.h"
#include "Pronouns_Collection.h"

class Possessive_Pronouns_Collection : public Pronouns_Collection {
public:
	Possessive_Pronouns_Collection();
	~Possessive_Pronouns_Collection();

	void init(void);


	void addPronoun(Possessive_Pronouns*);

	Possessive_Pronouns* getPronoun(std::string name);
	Possessive_Pronouns* getPronoun(int index);


protected:
private:
	std::vector<Possessive_Pronouns*> _possessivePronounList;
};

#endif //POSSESSIVE_PRONOUNS_COLLECTION_H