
#ifndef SEMANTICMEMORY_H
#define SEMANTICMEMORY_H
/*

Semantic memory remembers facts and concepts. General knowledge are saved here.
A semantic souvenir is composed by the following :

Object  -> is a : Noun
	    -> is : Adjectives
	    -> has : Noun
	    -> can : Verbs

Example :
Human   -> is a : living organism
		-> is : dumb.
		-> has : hands, arms, legs, head, brain..
		-> can : walk, run, talk...
*/

#include <vector>
#include <string>

typedef struct {
	//std::string whRelatedNoName; //Question what is a human can be answered by different point of view.
	std::string whatWH;
	std::string whenWH;
	std::string whereWH;
	std::string whyWH;
	std::string HowWH;
	std::string WhoWH;
} WH_ANSWERS;

typedef struct {
	std::string object;
	std::vector<WH_ANSWERS> whAnswers;

} OBJECTS;

typedef struct {
	std::string objectName;

	std::vector<std::string> _isA;
	std::vector<OBJECTS> _is;
	std::vector<OBJECTS> _has;
	std::vector<std::string> _can;
} OBJETSEMANTIC;
class semanticMemory {
public:
	semanticMemory();
	~semanticMemory();

	void init();

	bool objectDoesExist(const std::string objectName);
	bool objetCanExist(const std::string objectName, const std::string can);
	bool objetIsExist(const std::string objectName, const std::string object);
	bool objetIsAExist(const std::string objectName, const std::string isA);
	bool objetHasExist(const std::string objectName, const std::string has);

	void createObject(const std::string objectName);

	void addIsA(const std::string objectName, std::string isA);
	void addIs(const std::string objectName, const std::string objectIs);
	void addIs(const std::string objectName, const std::string objectIs, const WH_ANSWERS whAnswers);
	void addHas(const std::string objectName, const std::string objectHas);
	void addHas(const std::string objectName, const std::string objectHas, const WH_ANSWERS whAnswers);
	void addCan(const std::string objectName, const std::string can);

	void addWHAnswer(const std::string objectName, const std::string verb, const std::string noun, const std::string wh, const std::string whAnswer);

	bool getIsA(const std::string objectName, std::string &whAnswer);
	bool getIsA(const std::string objectName, std::vector<std::string> &whAnswers);

	bool getIs(const std::string objectName, const std::string object, const std::string wh, std::string &whAnswer);
	bool getHas(const std::string objectName, const std::string object, const std::string wh, std::string &whAnswer);

	bool getCan(const std::string objectName, std::string &whAnswer);
	bool getCan(const std::string objectName, std::vector<std::string> &whAnswers);

protected:
private:
	std::vector<OBJETSEMANTIC> _semantics;
};






#endif //SEMANTICMEMORY_H