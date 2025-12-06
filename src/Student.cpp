#include "SakanX/Student.h"
#include <iostream>

using namespace std;

Student::Student(const string& name, int id, int age, NationalityType nationality, string ssn="", 
    vector<pair<string, string>> contacts, char gender, const string& major, double tolerance)
    :Person(name, id, age, nationality, ssn, contacts, gender), major(major), toleranceLevel(tolerance){}
Student::~Student() {
    Person::~Person();
    this->clearTags();
}
string Student::getMajor() const{
    return major;
}
void Student::setMajor(const string& major){
    this->major = major;
}
double Student::getTolerance(){
    return toleranceLevel;
}
void Student::setTolerance(double level){
    toleranceLevel = level;
}
void Student::displayInfo() const {
    cout<<"Student Name: " << name <<" - Student ID: " << id <<" - Major: " << major << endl;
}
int Student::calculateTotalTagValue() const {
    int total = 0;
    for (const auto& tag : tags) {
        total += tag->getValue();
    }
    return total;
}
void Student::addTag(Tag* tag) {
    tags.insert(tag);
}
void Student::removeTag(Tag* tag) {
    tags.erase(tag);
}
bool Student::findTag(Tag* tag) {
    return(tags.find(tag) != tags.end());
}
const set<Tag*>& Student::getTags() const {
    return tags;
}
void Student::clearTags() {
    tags.clear();
}
double Student::getTolerance() {
    return toleranceLevel;
}
void cleanupTags(){
    for(Tag* tag : Student::availableTags) {
        delete tag;
    }
    Student::availableTags.clear();
}

std::vector<Tag*> Student::availableTags = {
    // Group A: Quiet / Orderly (Values 10–30)
    new Tag(1, "Early Bird", 10),
    new Tag(2, "Bookworm", 12),
    new Tag(3, "Study Focused", 15),
    new Tag(4, "Clean Freak", 20),
    new Tag(5, "Homebody", 18),
    
    // Group B: Moderate / Balanced (Values 40–60)
    new Tag(6, "Casual Socializer", 50),
    new Tag(7, "Movie Buff", 45),
    new Tag(8, "Cooking Enthusiast", 55),
    new Tag(9, "Fitness Junkie", 48),

    // Group C: Active / Loud (Values 80–100)
    new Tag(10, "Night Owl", 85),
    new Tag(11, "Gamer", 80),
    new Tag(12, "Musician", 90),
    new Tag(13, "Party Animal", 100),
    new Tag(14, "Guest Friendly", 95)
};