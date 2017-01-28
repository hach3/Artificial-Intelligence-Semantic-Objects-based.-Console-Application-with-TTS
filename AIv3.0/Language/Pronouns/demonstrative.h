#ifndef DEMONSTRATIVE_H
#define DEMONSTRATIVE_H

#include <vector>
#include <string>

typedef struct {
	std::string singular;
	std::string plural;

	std::string concept;

} DEMONSTRATIVE_PRONOUN;

class Demonstrative_Pronoun {

public:
	Demonstrative_Pronoun();
	~Demonstrative_Pronoun();

	bool isDemonstrative(std::string word);

	void addDemonstrative(std::string singular);
	void addDemonstrative(std::string singular, std::string plural);
	void addDemonstrative(std::string singular, std::string plural, std::string concept);

	std::string getConcept(std::string demonstrative);
	std::string getPlural(std::string demonstrative);
	std::string getSingular(std::string demonstrative);

	void setPlural(std::string demonstrative, std::string plural);
	void setConcept(std::string demonstrative, std::string concept);

protected:
private:
	std::vector<DEMONSTRATIVE_PRONOUN> _demonstrativePronounsList;

};
#endif //DEMONSTRATIVE_H