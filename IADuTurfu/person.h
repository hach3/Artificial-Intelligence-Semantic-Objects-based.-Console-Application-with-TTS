#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
public:
	Person();
	~Person();

	void setName(std::string name);
	std::string getName();

protected:
private:
	std::string _name;

};
#endif