#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include "Tag.h"
#include <string>
#include <vector>
#include <set>
using namespace std;
class Student : public virtual Person {
public:
    static vector<Tag*> availableTags; // Static member for all possible tags
    Student(const string& name, int id, int age, NationalityType nationality, string ssn="", 
                vector<pair<string, string>> contacts, char gender, const string& major, double tolerance);
    ~Student();

    void displayInfo() const override;
    int calculateTotalTagValue() const;
    void addTag(Tag* tag);
    void removeTag(Tag* tag);
    bool findTag(Tag* tag);
    void clearTags();
    const set<Tag*>& Student::getTags() const;
    
    string getMajor() const;
    void setMajor(const string& major);
    double getTolerance();
    void setTolerance(double level);

    void cleanupTags();
private:
    string major;
    double toleranceLevel;
    set<Tag*> tags;
};

#endif // STUDENT_H
