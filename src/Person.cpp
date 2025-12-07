#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <chrono>
#include <cstdlib>
#include "SakanX/Person.h"

using namespace std;

Person::Person(const string& name, int id) : name(name), id(id) {
    if (name.empty() || id < 0) {
        throw std::invalid_argument("Invalid Person constructor arguments");
    }
}
Person::Person(const string& name, int id, const string& ssn, int age)
    : name(name), id(id), ssn(ssn), age(age) {
    if (name.empty() || id < 0 || ssn.empty() || age < 0) {
        throw std::invalid_argument("Invalid Person constructor arguments");
    }
}
Person::Person(const string& name, int id, int age, NationalityType nationality, const string& ssn, const vector<pair<string, string>>& contacts, char gender)
    : name(name), id(id), age(age), nationality(nationality), ssn(ssn), contacts(contacts), gender(gender) {
    if (name.empty() || id < 0 || age < 0 || ssn.empty()) {
        throw std::invalid_argument("Invalid Person constructor arguments");
    }
}


Person::Person(const string& name, int id, const string& ssn, int age, char gender, NationalityType nationality, const vector<pair<string, string>>& contacts)
    : name(name), id(id), ssn(ssn), age(age), gender(gender), nationality(nationality), contacts(contacts) {
    if (name.empty() || id < 0 || ssn.empty() || age < 0) {
        throw std::invalid_argument("Invalid Person constructor arguments");
    }
}

Person::Person(const string& name, int id, const string& ssn, int age, NationalityType nationality, const vector<pair<string, string>>& contacts)
    : name(name), id(id), ssn(ssn), age(age), nationality(nationality), contacts(contacts) {
    if (name.empty() || id < 0 || ssn.empty() || age < 0) {
        throw std::invalid_argument("Invalid Person constructor arguments");
    }
}

void Person::sayJoke(){
    // No output as per requirements
}


Person::~Person() {}


// Setters
void Person::setSSN(const string& ssn_) { 
    if (ssn_.empty()) throw std::invalid_argument("SSN cannot be empty");
    ssn = ssn_; 
}
void Person::setName(const string& name_) { 
    if (name_.empty()) throw std::invalid_argument("Name cannot be empty");
    name = name_; 
}
void Person::setAge(int age_) { 
    if (age_ < 0) throw std::invalid_argument("Age must be non-negative");
    age = age_; 
}
void Person::setId(int id_) { 
    if (id_ < 0) throw std::invalid_argument("ID must be non-negative");
    id = id_; 
}
void Person::setNationality(NationalityType nationality_) { nationality = nationality_; }
void Person::setContacts(const vector<pair<string, string>>& contacts_) { contacts = contacts_; }
void Person::setGender(char gender_){ gender = gender_ ; }

// Getters
const string& Person::getSSN() const { return ssn; }
const string& Person::getName() const { return name; }
int Person::getAge() const { return age; }
int Person::getId() const { return id; }
char Person::getGender() const { return gender; }
NationalityType Person::getNationality() const { return nationality; }
const vector<pair<string, string>>& Person::getContacts() const { return contacts; }
