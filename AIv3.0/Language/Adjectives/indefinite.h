#ifndef INDEFINITE_ADJECTIVES_H
#define INDEFINITE_ADJECTIVES_H

#include <vector>
#include <string>

typedef struct {
	std::string adjective;

	std::string relatedWord;
}INDEFINITE_ADJECTIVES;

class IndefiniteAdj {
public:
	IndefiniteAdj();
	~IndefiniteAdj();

	void init(void);

	void addIndefinite(std::string adjective);
	void addIndefinite(std::string adjective, std::string relatedWord);

	bool isIndefinite(std::string word);
	bool isIndefiniteInSentence(std::string sentence);
	bool isIndefiniteInVector(std::vector<std::string> vectorSentence);

	std::string getRelatedWord(std::string adjective);
protected:
private:
	std::vector<INDEFINITE_ADJECTIVES> _indefiniteAdjectivesList;
};
#endif//INDEFINITE_ADJECTIVES_H