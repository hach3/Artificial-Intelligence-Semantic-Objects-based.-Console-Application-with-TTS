#ifndef OBJECTS_H
#define OBJECTS_H

#include <string>
#include <vector>

typedef struct {
	std::string whatWH;
	std::string whenWH;
	std::string whereWH;
	std::string whyWH;
	std::string HowWH;
	std::string WhoWH;
} WH_ANSWERS;

typedef struct {
	std::string objectName;
	std::string verb;
	std::string object;
	std::vector<WH_ANSWERS> whAnswers;

} OBJECTS;

class Objects {
public:
	Objects();
	~Objects();

	void createObject(std::string objectName);
	void createObject(std::string objectName, std::string verb);
	void createObject(std::string objectName, std::string verb, std::string object);
	void createObject(std::string objectName, std::string verb, std::string object, std::vector<WH_ANSWERS> whAnswers);

	void addVerb(std::string objectName, std::string verb);
	void addObject(std::string objectName, std::string verb, std::string object);
	void addWHanswer(std::string objectName, std::string verb, std::string object, std::string wh, std::string whAnswer);

	std::string getWHAnswer(std::string objectName, std::string verb, std::string object, std::string wh);

	bool isVerbInObjet(std::string objectName, std::string verb);
	std::string getVerbForObject(std::string objectName, std::string object);
	std::string getWHForObject(std::string objectName, std::string object, std::string wh);

	bool isObjectInObject(std::string objectName, std::string verb);
	
protected:
private:
	std::vector<OBJECTS> _objectsList;
};


#endif //OBJECTS_H