#ifndef CORRELATIVE_CONJUNCTIONS_H
#define CORRELATIVE_CONJUNCTIONS_H

#include <vector>
#include <string>

/*

Correlative Conjunctions are simply pairs of conjunctions used in a sentence to join different words or groups of words in a sentence together. 
Correlative Conjunctions are generally not used to link sentences themselves, instead they link two or more words of equal importance within the sentence itself. 
Some of the more commonly used correlative conjunctions are -


Both the shoes and the dress were completely overpriced.

This is an example of using the correlative conjunctions ‘both/and’ in a sentence. As you can see in this sentence, the ‘shoes’ and the 
‘dress’ were equally important elements that needed to be given the same importance.

They should either change their strategy or just forfeit the game.

The ‘either/or’ conjunctions are used to suggest a choice between two options. Here the choice being suggested is between - ‘change their strategy’ or ‘forfeit the game’.

Just as she loves hiking so she enjoys travelling as well.

The correlative conjunctions ‘just as/so’ are used to link two phrases that have a similar theme or are referring to a similar thing together. 
This conjunction is used to show the correspondence between two phrases or words.

He neither helps around the house nor does he look for a job.

‘Neither/nor’ are conjunctions that are used to deny or negate words and phrases. In the case of ‘neither’, 
it gives two options that are both negated. ‘Nor’ is the negative form of ‘or’.
*/

typedef struct {

} CORRELATIVE_CONJUNCTIONS;

class Correlative_Conjunctions {
public:
	Correlative_Conjunctions();
	~Correlative_Conjunctions();

	void init();
protected:
private:
	std::vector<CORRELATIVE_CONJUNCTIONS> _correlativeConjunctionsList;
};
#endif //CORRELATIVE_CONJUNCTIONS_H