#ifndef COLLCONCEPTSUBJECT_H
#define COLLCONCEPTSUBJECT_H

#include "CollConcept.h"

class CollConceptSubject : public CollConcept {
public:
    CollConceptSubject();
    ~CollConceptSubject();
    void Init();
    /* Check if the wh exists by checking the name in the whwords vector */
    bool checkIfExist(std::string subject_Name);

    std::string getSubject(int person);
	std::string getSubjectByName(std::string subject);
	void addSubject(std::string name, std::string i, std::string you, std::vector<std::string> he, std::string we, std::string youp, std::string they);

    void deleteAll();
protected:
private:
    std::vector<CONCEPT_SUBJECT> _subjectWords;

};


#endif // COLLCONCEPTSUBJECT_H
