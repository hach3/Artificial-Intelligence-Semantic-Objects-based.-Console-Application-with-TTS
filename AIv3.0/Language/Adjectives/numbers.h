#ifndef NUMBERS_H
#define NUMBERS_H

#include <vector>
#include <string>
typedef struct {
	std::string alphaForm;
	std::string nbForm;
	std::string thAlphaForm;
	std::string thNbForm;
}NUMBERS_ADJECTIVES;
class Numbers {
public:
	Numbers();
	~Numbers();

	void init();

	void addNumber(std::string alphaForm, std::string nbForm,
		std::string thAlphaForm, std::string thNbForm);

	bool isNumber(std::string nb);
	bool isNumberInVector(std::vector<std::string> vectorSentence);
	/*
	TODO:
	bool isAlpha,
	bool isNbForm,
	bool isThAlpha,
	bool isThNb
	*/
protected:
private:
	std::vector<NUMBERS_ADJECTIVES> _numberAdjList;
};
#endif//NUMBERS_H