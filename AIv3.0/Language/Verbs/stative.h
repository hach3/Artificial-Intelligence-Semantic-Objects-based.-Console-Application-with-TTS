#ifndef STATIVE_H
#define STATIVE_H


#include <vector>
#include <string>

typedef struct {
	std::string infinitiveForm;
	std::vector<std::string> presentForm;
	std::string mainRelatedWord;

	std::vector<std::string> relatedWords;

} STATIVE_VERB;

class Stative_Verb {
public:
	Stative_Verb();
	~Stative_Verb();

	void init();

	bool isStative(std::string word);

	void addStative(std::string infinitiveForm);
	void addStative(std::string infinitiveForm, std::string mainRelatedWord);
	void addStative(std::string infinitiveForm, std::vector<std::string> presentForm);
	void addStative(std::string infinitiveForm, std::vector<std::string> presentForm, std::string mainRelatedWord, std::vector<std::string> relatedWords);

	void addRelateWord(std::string word, std::string relatedWord);
	bool isRelated(std::string stative, std::string word);

	void setMainRelatedWord(std::string stative, std::string mainRelatedWord);
	std::string getMainRelatedWord(std::string stative);

	std::string getStativeAtPerson(std::string stative, int person);



protected:
private:
	std::vector<STATIVE_VERB> _modalVerbsList;
};

#endif //STATIVE_H