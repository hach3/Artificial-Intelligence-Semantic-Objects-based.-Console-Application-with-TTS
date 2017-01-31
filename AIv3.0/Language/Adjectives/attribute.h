#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

#include <vector>
#include <string>
typedef struct {
	std::string adjective;
	std::vector<std::string> relatedWords;
//bool isAttribute; //Before the noun
//bool isPredicative; // follow the noun
//	bool isCoordinate;
} ATTRIBUTE_ADJECTIVES;
class Attribute {
public:
	Attribute(void);
	~Attribute(void);

	void init(void);

	void addAttribute(std::string adjective);
	void addAttribute(std::string adjective, std::vector<std::string> relatedWords);

	bool isAdjective(std::string adjective);
	bool isAdjectiveInSentence(std::string sentence);
	bool isAdjectiveInSentence(std::string sentence, std::vector<std::string> &adjectives);
	bool isAdjectiveInVector(std::vector<std::string> vectorSentence);
	bool isAdjectiveInVector(std::vector<std::string> vectorSentence, std::vector<std::string> &adjectives);
	
	

	void addRelatedWord(std::string adjective, std::string relatedWord);
	void addRelatedWords(std::string adjective, std::vector<std::string> relatedWords);
	bool isRelatedWordTo(std::string adjective, std::string relatedWord);

	std::vector<std::string> getRelatedWords(std::string adjective);
protected:
private:
	std::vector<ATTRIBUTE_ADJECTIVES> _attributeList;
};

#endif //ATTRIBUTE_H