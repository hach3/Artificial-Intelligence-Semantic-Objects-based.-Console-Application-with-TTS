#ifndef INDEFINITE_H
#define INDEFINITE_H

#include <vector>
#include <string>

typedef struct {
	std::string indefinitePronoun;

	std::vector<std::string> relatedWords;

	bool isObject;
	bool isBeing;
	bool isPlace;

} INDEFINITE_PRONOUN;

class Indefinite_Pronoun {

public:
	Indefinite_Pronoun();
	~Indefinite_Pronoun();

	bool isIndefinite(std::string word);

	void addIndefinite(std::string indefinitePronoun);
	void addIndefinite(std::string indefinitePronoun, bool isObject, bool isBeing, bool isPlace);

	void addRelatedWord(std::string indefinitePronoun, std::string relatedWord);
	std::vector<std::string> getRelatedWord(std::string indefinitePronoun);

	void setIsObject(std::string indefinitePronoun, bool isObject);
	void setIsBeing(std::string indefinitePronoun, bool isBeing);
	void setIsPlace(std::string indefinitePronoun, bool isPlace);

	bool isObject(std::string indefinitePronoun);
	bool isBeing(std::string indefinitePronoun);
	bool isPlace(std::string indefinitePronoun);

protected:
private:
	std::vector<INDEFINITE_PRONOUN> _demonstrativePronounsList;

};
#endif //INDEFINITE_H