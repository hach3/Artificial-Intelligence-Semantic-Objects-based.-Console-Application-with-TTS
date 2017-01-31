#ifndef DEGREE_ADVERBS_H
#define DEGREE_ADVERBS_H

#include <vector>
#include <string>

typedef struct {
	std::string adv;

}DEGREE_ADVERBS;

class Degree_Adverbs {
public:
	Degree_Adverbs();
	~Degree_Adverbs();

	void init();
	void addDegree(std::string adv);

	bool isDegree(std::string adv);
	bool isDegreeInSentence(std::string sentence);
	bool isDegreeInVector(std::vector<std::string> vectorSentence);


protected:
private:
	std::vector<DEGREE_ADVERBS> _degreeAdverbsList;
};
#endif//DEGREE_ADVERBS_H