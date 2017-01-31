#ifndef TIME_ADVERBS_H
#define TIME_ADVERBS_H

#include <vector>
#include <string>
/*
TELL US HOW SMTH HAPPENS
*/
typedef struct {
	std::string time;

	std::string relatedWord;
}TIME_ADVERBS;

class Time_Adverbs {
public:
	Time_Adverbs();
	~Time_Adverbs();

	void init();

	void addTimeAdj(std::string time);
	void addTimeAdj(std::string time, std::string relatedWord);

	bool checkIfTime(std::string time);
	bool checkIfTimeInSentence(std::string sentence);
	bool checkIfTimeInVector(std::vector<std::string> vectorSentence);

	std::string getRelatedWord(std::string time);

protected:
private:
	std::vector<TIME_ADVERBS> _timeAdverbsList;
};
#endif//TIME_ADVERBS_H