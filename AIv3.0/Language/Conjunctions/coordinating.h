#ifndef COORDINATING_CONJUNCTIONS_H
#define COORDINATING_CONJUNCTIONS_H

#include <vector>
#include <string>

/*

These conjunctions are used to link or join two words or phrases that are equally important and complete 
in terms of grammar when compared with each other. That is to say, the sentences or words do not depend 
on anything to give themselves meaning.
*/

typedef struct {
	std::string coordinating;

	std::string relatedWord;
} COORDINATING_CONJUNCTIONS;

class Coordinating_Conjunctions {
public:
	Coordinating_Conjunctions();
	~Coordinating_Conjunctions();

	void init();
protected:
private:
	std::vector<COORDINATING_CONJUNCTIONS> _coordinatingConjunctionsList;
};
#endif //COORDINATING_CONJUNCTIONS_H