#ifndef FREQUENCY_ADVERBS_H
#define FREQUENCY_ADVERBS_H

#include <vector>
#include <string>

typedef struct {
	std::string adv;
	double valueOfAdv;
}FREQUENCY_ADVERBS;

class Frequency_Adverbs {
public:
	Frequency_Adverbs();
	~Frequency_Adverbs();

	void init();
	void addFrequency(std::string frequency);
	void addFrequency(std::string frequency, double value);

	bool isFrequency(std::string frequency);
	bool isFrequencyInSentence(std::string sentence);
	bool isFrequencyInVector(std::vector<std::string> vectorSentence);

	double getValueOfFrequency(std::string frequency);

protected:
private:
	std::vector<FREQUENCY_ADVERBS> _frequencyAdverbsList;
};
#endif//DEGREE_ADVERBS_H