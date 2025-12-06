#ifndef PERSON_H
#define PERSON_H

#include <chrono>
#include <iostream>
#include <string>
#include <vector>


using namespace std;

enum class NationalityType {
    Egyptian,
    NonEgyptianArab,
    NonArab // Dollar :D
};

class Person {
public:

    Person(const string& name, int id);
    Person(const string& name, int id, const string& ssn, int age);
    Person(const string& name, int id, int age, NationalityType nationality, const string& ssn, const vector<pair<string, string>>& contacts, char gender);
    Person(const string& name, int id, const string& ssn, int age, NationalityType nationality, const vector<pair<string, string>>& contacts);
    Person(const string& name, int id, const string& ssn, int age, char gender, NationalityType nationality, const vector<pair<string, string>>& contacts);
    virtual ~Person();

    // Pure virtual function
    virtual void sayJoke();
    virtual void displayInfo() const = 0;



    // Setters
    void setSSN(const string& ssn_);
    void setName(const string& name_);
    void setAge(int age_);
    void setId(int id_);
    void setNationality(NationalityType nationality_);
    void setContacts(const vector<pair<string, string>>& contacts_);
    void setGender(char gender);

    // Getters
    const string& getSSN() const;
    const string& getName() const;
    int getAge() const;
    int getId() const;
    char getGender() const;
    NationalityType getNationality() const;
    const vector<pair<string, string>>& getContacts() const;

protected:
    string ssn;
    string name;
    int age;
    int id;

    char gender; // f female, m male


    NationalityType nationality;

    vector<pair<string, string>> contacts; // vector of a pair of (name of contact, value of contact)
                                          // phone number : 01111 , facebok : sha7t ma7t, phone 2 : 02222

    

};

#endif // PERSON_H
