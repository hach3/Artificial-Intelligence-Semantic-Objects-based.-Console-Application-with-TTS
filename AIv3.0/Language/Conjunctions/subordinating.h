#ifndef SUBORDINATING_CONJUNCTIONS_H
#define SUBORDINATING_CONJUNCTIONS_H

#include <vector>
#include <string>

/*

These conjunctions are used to link or join two words or phrases that are equally important and complete
in terms of grammar when compared with each other. That is to say, the sentences or words do not depend
on anything to give themselves meaning.
*/

typedef struct {
	std::string subordinating;

	std::string relatedWord;
} SUBORDINATING_CONJUNCTIONS;

class Subordinating_Conjunctions {
public:
	Subordinating_Conjunctions();
	~Subordinating_Conjunctions();

	void init();
protected:
private:
	std::vector<SUBORDINATING_CONJUNCTIONS> _subordinatingConjunctionsList;
};
#endif //SUBORDINATING_CONJUNCTIONS_H