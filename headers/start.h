#ifndef START_H
#define START_H
/*
This will be call when the program starts, this is the main loop handler
For now, the loop is:
while(userWriteSomething)
{
	answer the sentence
}

*/
#include "ai.h"


class Start {
public:
	Start();
	~Start();

	void loop();
protected:
private:
	AI _ai;
};

#endif //START_H
