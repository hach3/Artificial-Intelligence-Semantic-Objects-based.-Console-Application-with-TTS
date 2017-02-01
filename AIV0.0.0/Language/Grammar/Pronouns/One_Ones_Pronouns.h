#ifndef ONE_ONES_PRONOUNS_H
#define ONE_ONES_PRONOUNS_H
#include "Pronouns.h"

/*
Source : https://learnenglish.britishcouncil.org/en/english-grammar/pronouns/one-and-ones
We use one (singular) and ones (plural) to avoid unnecessary repetition.
	See those two girls. Helen is the one on the left.
	Let’s look at the photographs. The ones you took in Paris.
	
We often use them after Which ... in questions:
	You can borrow a book. Which one do you want?
	There are lots of books here. Which ones are yours?

*/

class One_Ones_Pronouns : public Pronouns {
public:
	One_Ones_Pronouns();
	One_Ones_Pronouns(std::string name, bool isPlural);

	~One_Ones_Pronouns();


	bool isPlural();

protected:
private:

	bool _isPlural;

};
#endif //ONE_ONES_PRONOUNS_H