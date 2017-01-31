#ifndef MANNER_ADVERBS_H
#define MANNER_ADVERBS_H

#include <vector>
#include <string>
/*
TELL US HOW SMTH HAPPENS
*/
typedef struct {
	std::string manner;
}MANNER_ADVERBS;

class Manner_Adverbs {
public:
	Manner_Adverbs();
	~Manner_Adverbs();

	void init();

	void addMannerAdj(std::string manner);

	bool checkIfManner(std::string manner);
	bool checkIfMannerInSentence(std::string sentence);
	bool checkIfMannerInVector(std::vector<std::string> vectorSentence);


protected:
private:
	std::vector<MANNER_ADVERBS> _mannerAdverbsList;
};
#endif//MANNER_ADVERBS_H