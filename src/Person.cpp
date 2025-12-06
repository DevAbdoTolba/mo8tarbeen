#include <iostream>
#include "SakanX/Person.h"

using namespace std;

Person::Person(const string& name, int id) : name(name), id(id) {
    cout << "[Person Constructor] Created user: " << name << " (ID: " << id << ")" << endl;
}

Person::~Person() {
    cout << "[Person Destructor] Cleaning up user: " << name << endl;
}