#ifndef RECIPROCAL_H
#define RECIPROCAL_H

#include <vector>
#include <string>

typedef struct {
	std::string reciprocal;
	
	bool subjectIncluded;
} RECIPROCAL_PRONOUN;

class Reciprocal_Pronoun {

public:
	Reciprocal_Pronoun();
	~Reciprocal_Pronoun();

	bool isReciprocal(std::string word);

	void addReciprocal(std::string reciprocal);
	void addReciprocal(std::string reciprocal, bool subjectIncluded);

protected:
private:
	std::vector<RECIPROCAL_PRONOUN> _reciprocalPronounsList;

};
#endif //RECIPROCAL_H