#ifndef AUXILIARY_H
#define AUXILIARY_H

#include <vector>
#include <string>

typedef struct {
	std::string infinitiveForm;
	std::vector<std::string> presentForm;


} AUXILIARY_VERB;

class Auxiliary_Verb {
public:
	Auxiliary_Verb();
	~Auxiliary_Verb();

	void init();
	
	bool isAuxiliary(std::string word);

	void addAuxiliary(std::string infinitiveForm);
	void addAuxiliary(std::string infinitiveForm, std::vector<std::string> presentForm);

	std::string getAuxiliaryAtPerson(std::string auxiliary, int person);
	void setPresentForm(std::string auxiliary, std::vector<std::string> presentForm);

	bool isBe(std::string word);
	bool isBeInSentence(std::string sentence, std::string &verb);
	bool isHave(std::string word);
	bool isDo(std::string word);
protected:
private:
	std::vector<AUXILIARY_VERB> _auxiliaryVerbsList;
};

#endif //AUXILIARY_H