#ifndef VERBS_H
#define VERBS_H
#include <string>
#include <vector>



class Verbs {
public:
	Verbs();
	Verbs(std::string verbalBase, std::string ingForm, 
		std::string _pastForm, std::string pastParticipate);
	Verbs(std::string verbalBase, std::string ingForm,
		std::string _pastForm, std::string pastParticipate, 
		std::vector<std::string> simplePresent, std::vector<std::string> simplePast);
	~Verbs();

	std::string getVerbalBase();
	std::string getIngForm();
	std::string getPastForm();
	std::string getPastParticipate();

	std::string getPresentVerbAtPerson(int person);
	std::string getPastVerbAtPerson(int person);

	bool checkIfVerbInSentence(std::string sentence, std::string &verb);
	bool checkIfVerbInSentence(std::vector<std::string> vectorSentence, std::string &verb);

protected:
private:

	std::string _verbalBase;
	std::string _ingForm;
	std::string _pastForm;
	std::string _pastParticipate;

	std::vector<std::string> _simplePresent;
	std::vector<std::string> _simplePast;
	
};

#endif //VERBS_H