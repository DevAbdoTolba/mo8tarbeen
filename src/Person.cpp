#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <chrono>
#include <cstdlib>
#include "SakanX/Person.h"

using namespace std;

Person::Person(const string& name, int id) : name(name), id(id) {
    cout << "[Person Constructor] Created user: " << name << " (ID: " << id << ")" << endl;
}
Person::Person(const string& name, int id, const string& ssn, int age)
    : name(name), id(id), ssn(ssn), age(age) {
    cout << "[Person Constructor] Created user: " << name << " (ID: " << id << ", SSN: " << ssn << ", Age: " << age << ")" << endl;
}
Person::Person(const string& name, int id, int age, NationalityType nationality, const string& ssn, const vector<pair<string, string>>& contacts, char gender)
    : name(name), id(id), age(age), nationality(nationality), ssn(ssn), contacts(contacts), gender(gender) {
    cout << "[Person Constructor] Created user: " << name << " (ID: " << id << ", Age: " << age << ", Nationality: " << static_cast<int>(nationality) << ", SSN: " << ssn << ", Contacts: " << contacts.size() << ", Gender: " << gender << ")" << endl;
}


Person::Person(const string& name, int id, const string& ssn, int age, char gender, NationalityType nationality, const vector<pair<string, string>>& contacts)
    : name(name), id(id), ssn(ssn), age(age), gender(gender), nationality(nationality), contacts(contacts) {
    cout << "[Person Constructor] Created user: " << name << " (ID: " << id << ", SSN: " << ssn << ", Age: " << age << ", Gender: " << gender << ", Nationality: " << static_cast<int>(nationality) << ", Contacts: " << contacts.size() << ")" << endl;
}

Person::Person(const string& name, int id, const string& ssn, int age, NationalityType nationality, const vector<pair<string, string>>& contacts)
    : name(name), id(id), ssn(ssn), age(age), nationality(nationality), contacts(contacts) {
    cout << "[Person Constructor] Created user: " << name << " (ID: " << id << ", SSN: " << ssn << ", Age: " << age << ", Nationality: " << static_cast<int>(nationality) << ", Contacts: " << contacts.size() << ")" << endl;
}

void Person::sayJoke(){
            vector<string> jokes{
            "One Egyptian asks another: 'Why are you late?' He replies: 'The traffic light turned red, so I waited for it to turn green again... twice!'",
            "Teacher: 'Why are you always late?' Student: 'Because I live in Egypt, miss!'",
            "An Egyptian goes to the doctor and says: 'Doctor, every time I drink tea, my eye hurts.' Doctor: 'Try taking the spoon out of the cup!'",
            "In Egypt, if you want to cross the street, just close your eyes and pray. If you open them, you'll never cross!",
            "Egyptian logic: If you can't find parking, just double park and leave your number. If someone calls, pretend you don't hear the phone.",
            "Why do Egyptians never play hide and seek? Because good luck hiding from your neighbors!",
            "Egyptian Wi-Fi: Strongest signal in the kitchen, weakest in your room.",
            "In Egypt, if you ask for directions, you'll get a story, a cup of tea, and still be lost.",
            "Egyptian dad: 'When I was your age, I used to walk to school barefoot... uphill... both ways!'",
            "Egyptian elevator: Works perfectly... as long as you don't need to go up or down.",
            "Why did the Egyptian bring a ladder to the café? Because he heard the coffee was on the house!",
            "In Egypt, GPS means 'Guess, Pray, and Swerve.'",
            "Egyptian ATM: Out of service, but the security guard will lend you 50 pounds if you ask nicely.",
            "Why do Egyptians never get lost? Because wherever they go, someone will shout, 'Where are you going?!'",
            "Egyptian wedding: Starts at 8pm, but the bride arrives at midnight.",
            "Why did the Egyptian student bring a pillow to class? To be ready for the lecture nap!",
            "In Egypt, if you drop your sandwich, someone will pick it up and add more tahini.",
            "Egyptian taxi meter: Decorative only.",
            "Why did the Egyptian cross the road? To get to the other koshary shop.",
            "Egyptian time: If they say 5 minutes, expect them in an hour.",
            "In Egypt, if you ask for directions, you’ll get three different routes and a family invitation.",
            "Egyptian Wi-Fi password: '12345678', but it still won’t connect.",
            "Why do Egyptians love traffic? It gives them time to finish their phone calls.",
            "Egyptian elevator music: The sound of the elevator not working.",
            "In Egypt, every street is a parking lot.",
            "Why did the Egyptian bring bread to the cinema? To make a sandwich during the movie.",
            "Egyptian logic: If it’s broken, hit it. If it still doesn’t work, hit it harder.",
            "In Egypt, if you forget your umbrella, it will rain. If you bring it, it won’t.",
            "Egyptian shopping: Bargain for an hour, buy nothing, drink tea.",
            "Why do Egyptians never finish their tea? Because there’s always someone to talk to before the last sip."
        };

        srand(static_cast<unsigned int>(chrono::system_clock::now().time_since_epoch().count()));
        int idx = rand() % jokes.size();
        cout << jokes[idx] << endl;

}


Person::~Person() {
    cout << "[Person Destructor] Cleaning up user: " << name << endl;
}


// Setters
void Person::setSSN(const string& ssn_) { ssn = ssn_; }
void Person::setName(const string& name_) { name = name_; }
void Person::setAge(int age_) { age = age_; }
void Person::setId(int id_) { id = id_; }
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
