#ifndef IT_THERE_PRONOUNS_COLLECTION_H
#define IT_THERE_PRONOUNS_COLLECTION_H

#include "It_There_Pronouns.h"
#include "Pronouns_Collection.h"
/*
Collection of it and there.

*/
class It_There_Pronouns_Collection : public Pronouns_Collection {
public:
	It_There_Pronouns_Collection();
	~It_There_Pronouns_Collection();

	void init(void);
	
	void addPronoun(It_There_Pronouns*);

	It_There_Pronouns* getPronoun(std::string name);
	It_There_Pronouns* getPronoun(int index);


protected:
private:
	std::vector<It_There_Pronouns*> _itTherePronounsList;
};

#endif //IT_THERE_PRONOUNS_COLLECTION_H