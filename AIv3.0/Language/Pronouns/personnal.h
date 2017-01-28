#ifndef PERSONNAL_H
#define PERSONNAL_H

#include <vector>
#include <string>

typedef struct {
	std::string pronoun;
	std::string pluralForm;

	int person;
	
	bool isObject;
	bool isSubject;

} PERSONNAL_PRONOUN;

class Personnal_Pronoun {

public:
	Personnal_Pronoun();
	~Personnal_Pronoun();

	bool isPersonnal(std::string word);


	void addPersonnal(std::string pronoun);
	void addPersonnal(std::string pronoun, int person);
	void addPersonnal(std::string pronoun, std::string pluralForm, int person);
	
	void addPersonnal(std::string pronoun, bool isObject, bool isSubject);
	void addPersonnal(std::string pronoun, std::string pluralForm, bool isObject, bool isSubject);

	void addPersonnal(std::string pronoun, int person, bool isObject, bool isSubject);
	void addPersonnal(std::string pronoun, std::string pluralForm, int person, bool isObject, bool isSubject);

	bool isPlural(std::string pronoun);

	std::string getPersonnal(bool isPlural, int person, bool isObject, bool isSubject);

protected:
private:
	std::vector<PERSONNAL_PRONOUN> _personnalPronounsList;

};
#endif //PERSONNAL_H