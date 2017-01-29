#ifndef INTERROGATIVE_H
#define INTERROGATIVE_H

#include <vector>
#include <string>

typedef struct {
	std::string singular;
	std::string plural;

	std::vector<std::string> relatedWords;

} INTERROGATIVE_PRONOUN;

class Interrogative_Pronoun {

public:
	Interrogative_Pronoun();
	~Interrogative_Pronoun();

	void init();

	bool isInterrogative(std::string word);

	void addInterrogative(std::string singular);
	void addInterrogative(std::string singular, std::string plural);
	void addInterrogative(std::string singular, std::string plural, std::vector<std::string> relatedWords);

	void setPlural(std::string singular, std::string plural);

	void addRelatedWord(std::string word, std::string relatedWords);
	bool isRelatedWord(std::string word, std::string relatedWord);

	std::string getSingular(std::string interrogativeWord);
	std::string getPlural(std::string interrogativeWord);

protected:
private:
	std::vector<INTERROGATIVE_PRONOUN> _interrogativePronounsList;

};
#endif //INTERROGATIVE_H