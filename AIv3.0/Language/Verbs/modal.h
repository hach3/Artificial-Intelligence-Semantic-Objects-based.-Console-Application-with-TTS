#ifndef MODAL_H
#define MODAL_H

#include <vector>
#include <string>

typedef struct {
	std::string infinitiveForm;
	std::vector<std::string> presentForm;
	std::string conceptOfModal;

	std::vector<std::string> relatedWords;

} MODAL_VERB;

class Modal_Verb {
public:
	Modal_Verb();
	~Modal_Verb();

	void addModal(std::string infinitiveForm);
	void addModal(std::string infinitiveForm, std::string conceptOfModal);
	void addModal(std::string infinitiveForm, std::vector<std::string> presentForm);

	void addRelateWord(std::string word, std::string relatedWord);
	bool isRelated(std::string modal, std::string word);
	
	bool isConceptOfModal(std::string modal, std::string conceptOf);
	
	std::string getModalAtPerson(std::string modal, int person);



protected:
private:
	std::vector<MODAL_VERB> _modalVerbsList;
};


#endif //MODAL_H