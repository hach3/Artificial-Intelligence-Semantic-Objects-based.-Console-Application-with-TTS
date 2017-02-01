#ifndef QUESTION_PRONOUNS_COLLECTION_H
#define QUESTION_PRONOUNS_COLLECTION_H

#include "question_Pronouns.h"
#include "Pronouns_Collection.h"

class Question_Pronouns_Collection : public Pronouns_Collection {
public:
	Question_Pronouns_Collection();
	~Question_Pronouns_Collection();

	void init(void);

	void addPronoun(Question_Pronouns*);

	Question_Pronouns* getPronoun(std::string name);
	Question_Pronouns* getPronoun(int index);


protected:
private:
	std::vector<Question_Pronouns*> _questionPronounsList;
};

#endif //QUESTION_PRONOUNS_COLLECTION_H