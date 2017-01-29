#ifndef PHRASAL_H
#define PHRASAL_H


#include <vector>
#include <string>

typedef struct {
	std::string infinitiveForm;
	std::vector<std::string> presentForm;

	std::vector<std::string> relatedWords;

} PHRASAL_VERB;

class Phrasal_Verb {
public:
	Phrasal_Verb();
	~Phrasal_Verb();

	void init();

	bool isPhrasal(std::string word);

	void addPhrasal(std::string infinitiveForm);
	void addPhrasal(std::string infinitiveForm, std::vector<std::string> presentForm);

	void addRelateWord(std::string word, std::string relatedWord);
	bool isRelated(std::string phrasal, std::string word);



	std::string getPhrasalAtPerson(std::string phrasal, int person);



protected:
private:
	std::vector<PHRASAL_VERB> _modalVerbsList;
};


#endif //PHRASAL_H