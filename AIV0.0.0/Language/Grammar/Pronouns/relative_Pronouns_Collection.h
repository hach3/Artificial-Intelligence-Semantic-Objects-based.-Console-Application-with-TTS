#ifndef RELATIVE_PRONOUNS_COLLECTION_H
#define RELATIVE_PRONOUNS_COLLECTION_H
#include "relative_Pronouns.h"
#include "Pronouns_Collection.h"

class Relative_Pronouns_Collection : public Pronouns_Collection {
public:
	Relative_Pronouns_Collection();

	~Relative_Pronouns_Collection();

	void init(void);

	void addPronoun(Relative_Pronouns*);

	Relative_Pronouns* getPronoun(std::string name);
	Relative_Pronouns* getPronoun(int index);


protected:
private:
	std::vector<Relative_Pronouns*> _relativePronounsList;
};
#endif //REFLEXIVE_PRONOUNS_COLLECTION_H