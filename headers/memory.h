#ifndef MEMORY_H
#define MEMORY_H

/*
This class saves every conversations, eventually create people they meet to remeber them nextly ?

*/
#include <string>

class Memory {
public:
	Memory();
	Memory(std::string, std::string, std::string, std::string, std::string, std::string);
	~Memory();

	std::string getWho();
	std::string getWhat();
	std::string getWhy();
	std::string getWhere();
	std::string getWhen();
	std::string getHow();

	void printtheMemory();
	void explainHow();
protected:
private:
	std::string _who;
	std::string _what;
	std::string _why;
	std::string _where;
	std::string _when;
	std::string _how;
	
	
};
#endif