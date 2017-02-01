#ifndef IT_THERE_PRONOUNS_H
#define IT_THERE_PRONOUNS_H
#include "Pronouns.h"
/*
Source : https://learnenglish.britishcouncil.org/en/english-grammar/pronouns/it-and-there
English clauses always have a subject except for the imperative (Go away). If we have no other subject, we use there or it.

There :
We use there as a dummy subject with part of the verb be followed by a noun phrase :

- to introduce a new topic: There is a meeting this evening. 
- with numbers or quantities: There was a lot of rain last night.
- to say where something is: I wonder if there will be anyone at home.

- with an indefinite pronoun or expressions of quantity and the to-infinitive: There is nothing to do in the village.
- with an indefinite pronoun or expressions of quantity and an -ing verb: There is someone waiting to see you.

- We use a singular verb if the noun phrase is singular: There was a lot of rain last night.
- We use a plural verb if the noun phrase is plural: There are more than twenty people waiting to see you.

It :
We use it to talk about:
- times and dates: It’s my birthday.
- weather: It’s raining.
- to give an opinion about a place: It’s very cold in here.
- to give an opinion followed by to-infinitive: It’s nice to meet you.
- to give an opinion followed by an -ing verb: It’s great living in Spain.


Using "it" to talk about people

We use it to talk about ourselves:
- on the telephone: Hello. It’s George.
- when people cannot see us: [Mary knocks on door] It’s me. It’s Mary.

We use it to talk about other people:

- when we point them out for the first time: Look. It’s Sir Paul McCartney.
- when we cannot see them and we ask them for their name: [telephone rings, we pick it up] Hello. Who is it?
*/

class It_There_Pronouns : public Pronouns{
public:
	/* CONSTRUCTOR */
	It_There_Pronouns();
	It_There_Pronouns(std::string dummy);
	
	~It_There_Pronouns();

protected:
private:


};

#endif //IT_THERE_PRONOUNS_H