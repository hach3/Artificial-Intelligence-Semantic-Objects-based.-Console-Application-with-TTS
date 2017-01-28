#ifndef ACTION_H
#define ACTION_H

#include <string>
#include <vector>

typedef struct {
	//this is from the first person of singular to the last person of plural. be : am, are, is, are, are, are;
	std::string infinitiveForm;
	std::string gerundForm;
	std::vector<std::string> presentVerb;

	std::vector<std::string> relatedWords;

	bool isMental; // i know
	bool isPhysical; // i cut
	bool isStateOfBeing; // i am a student

	/* 
	Transitive : richards phones his boss (direct object)
	Intransitive : richards continues to be late at work.(dont need direct object, many are followed by adjectives, adverbs, prepositions or verb complement (gerund or infinitive)
	*/
	bool isTransitive;
	bool isIntransitive;
} ACTION_VERB;


class Action_Verb {
public:
	Action_Verb();
	~Action_Verb();

	bool isActionVerb(std::string word);

	bool isInfinitive(std::string verb);
	bool isGerund(std::string verb);

	std::string getPresentVerbAt(std::string verb, int person);
	std::vector<std::string> getPresent();

	void addVerb(std::string infinitiveForm);
	void addVerb(std::string infinitiveForm, std::string gerundForm);
	
	void addVerb(std::string infinitiveForm, std::string gerundForm, std::vector<std::string> presentVerb, std::vector<std::string> relatedWords, bool isMental, bool isPhysical, bool isStateOfBeing, bool isTransitive, bool isIntransitive);

	void addRelatedWord(std::string verb, std::string word);
	void setPresentForm(std::string verb, std::vector<std::string> presentForm);

	void setGerundForm(std::string verb, std::string gerundForm);
	std::string getGerundForm(std::string verb);

	void setMental(bool isMental, std::string verb);
	void setPhysical(bool isPhysical, std::string verb);
	bool isStateOfBeing(bool isStateOfBeing, std::string verb);

	bool isMental(std::string verb);
	bool isPhysical(std::string verb);
	bool isStateOfBeing(std::string verb);

	void setTransitive(bool isTransitive, std::string verb);
	void setIntransitive(bool isIntransitive, std::string verb);
	bool isTransitive(std::string verb);
	bool isIntransitive(std::string verb);

protected:
private:
	std::vector<ACTION_VERB> _actionVerbsList;

};
#endif //ACTION_H