#ifndef REFLEXIVE_PRONOUNS_COLLECTION_H
#define REFLEXIVE_PRONOUNS_COLLECTION_H
#include "reflexive_Pronouns.h"
#include "Pronouns_Collection.h"

class Reflexive_Pronouns_Collection : public Pronouns_Collection {
public:
	Reflexive_Pronouns_Collection();

	~Reflexive_Pronouns_Collection();

	void init(void);

	void addPronoun(Reflexive_Pronouns*);

	Reflexive_Pronouns* getPronoun(std::string name);
	Reflexive_Pronouns* getPronoun(int index);


protected:
private:
	std::vector<Reflexive_Pronouns*> _reflexivePronounsList;
};
#endif //REFLEXIVE_PRONOUNS_COLLECTION_H