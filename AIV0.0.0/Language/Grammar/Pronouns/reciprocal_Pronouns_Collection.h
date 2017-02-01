#ifndef RECIPROCAL_PRONOUNS_COLLECTION_H
#define RECIPROCAL_PRONOUNS_COLLECTION_H
#include "reciprocal_Pronouns.h"
#include "Pronouns_Collection.h"


class Reciprocal_Pronouns_Collection : public Pronouns_Collection {
public:
	Reciprocal_Pronouns_Collection();
	~Reciprocal_Pronouns_Collection();

	void init(void);

	void addPronoun(Reciprocal_Pronouns*);

	Reciprocal_Pronouns* getPronoun(std::string name);
	Reciprocal_Pronouns* getPronoun(int index);


protected:
private:
	std::vector<Reciprocal_Pronouns*> _reciprocalPronounsList;
};


#endif //RECIPROCAL_PRONOUNS_COLLECTION_H