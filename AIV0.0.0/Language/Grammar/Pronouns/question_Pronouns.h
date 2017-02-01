#ifndef QUESTION_PRONOUNS_H
#define QUESTION_PRONOUNS_H
#include "Pronouns.h"
/*
Source : https://learnenglish.britishcouncil.org/en/english-grammar/pronouns/questions

-We use who to ask questions about people: Who is that?

-We use whose to ask about possession: Whose book is that? [or] Whose is that book?

-We use what to ask questions about things: What is that? What do you want?

-We use which to ask someone to choose something: Which came first, the chicken or the egg?

-We can also use what and which with nouns: 
	What subjects did you study at school?
	What newspaper do you read?


After Who, Which or What we often have a preposition at the end of the sentence:
	Who does this book belong to?
	What are you looking for?
*/
class Question_Pronouns : public Pronouns {
public:
	Question_Pronouns();
	Question_Pronouns(std::string wh, bool isPeople, bool isPossession, bool isThing, bool isChoose);
	~Question_Pronouns();

	bool isPeople();
	bool isPossession();
	bool isThing();
	bool isChoose();


protected:
private:
	//This can be people, possession, things, choose
	bool _isPeople;
	bool _isPossession;
	bool _isThing;
	bool _isChoose;
};

#endif //QUESTION_PRONOUNS_H