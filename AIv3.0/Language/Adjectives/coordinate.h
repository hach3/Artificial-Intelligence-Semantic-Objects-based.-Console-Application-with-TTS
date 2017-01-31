#ifndef COORDINATE_H
#define COORDINATE_H

#include <vector>
#include <string>

typedef struct {
	std::string adjective;

	std::vector<std::string> relatedWords;
}COORDINATE_ADJECTIVES;
class Coordinate_Adjectives
{
public:
	Coordinate_Adjectives(void);
	~Coordinate_Adjectives(void);

	void init(void);

	void addCoordinate(std::string adjective);
	void addCoordinate(std::string adjective, std::vector<std::string> relatedWords);

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
	std::vector<COORDINATE_ADJECTIVES> _coordinateAdjList;
};
#endif//COORDINATE_H