#include "SakanX/DormSupervisor.h"
#include <iostream>

using namespace std;

DormSupervisor::DormSupervisor(const std::string& name, int id, const std::string& major, const std::string& department)
        : Person(name, id),
            Student(name, id, 18, NationalityType::Egyptian, "", {}, 'm', major, 0.0),
            Admin(name, id, "", 18, department) {}

DormSupervisor::DormSupervisor(const string& name, int id, const string& ssn, 
     int age, const string& major, const string& department)
     :Person(name,id,ssn,age),
      Admin(name,id,ssn,age,department),
      Student(name, id, age, NationalityType::Egyptian, ssn, {}, 'm', major, 0.0) {}

DormSupervisor::DormSupervisor(const string& name, int id, const string& ssn,
                                 int age, NationalityType nationality,
                                const string& major, const string& department,
                                const vector<pair<string, string>>& contacts)
    : Person(name,id,ssn,age,nationality,contacts),                   
      Student(name, id, age, nationality, ssn, contacts, 'm', major, 0.0),            
      Admin(name, id, ssn, age, department) {  }   
      

int DormSupervisor::countEmptyApartments(const vector<Apartment*>& apartments) const {
    int count = 0;
    for (auto* apt : apartments) {
        if (apt->getCurrentTenants() == 0) count++;
    }
    return count;
}


// Count of apartments that has students
int DormSupervisor::countFullApartments(const vector<Apartment*>& apartments) const {
    int count = 0;
    for (auto* apt : apartments) {
        if (apt->getCurrentTenants() > 0) count++;
    }
    return count;
}

// Find apartment by student
Apartment* DormSupervisor::findApartmentByStudent(Student* student, 
                                                  const vector<Apartment*>& apartments) const {
    if (student == nullptr) return nullptr;
    
    for (auto* apt : apartments) {
        vector<Student*> residents = apt->getStudents();
        for (auto* resident : residents) {
            if (resident == student) return apt;
        }
    }
    return nullptr;
}

// Find cheapest apartment
Apartment* DormSupervisor::findCheapestApartment(const vector<Apartment*>& apartments) const {
    Apartment* cheapest = nullptr;
    int minRent = 999999999;
    
    for (auto* apt : apartments) {
        double rent = apt->getRentPrice();
        if (rent < minRent) {
            minRent = rent;
            cheapest = apt;
        }
    }
    return cheapest;
}
DormSupervisor::~DormSupervisor() {}

void DormSupervisor::displayInfo() const {
    cout<<"==========================================================\n";
    cout<<"==== Dorm Supervisor Data ===="<<endl;
    cout<<"==========================================================\n";

    // Personal Information (from Person)
    cout << "--- Personal Information ---\n";
    cout << "Name         : " << name << "\n";
    cout << "ID           : " << id << "\n";
    
    if (!ssn.empty()) {
        cout << "SSN          : " << ssn << "\n";
    }
    
    cout << "Age          : " << age << "\n";
    
    // Student Information
    cout << "\n--- Student Role ---\n";
    cout << "Major        : " << Student::getMajor() << "\n";
    
    // Admin/Supervisor Information
    cout << "\n--- Supervisor Role ---\n";
    cout << "Department   : " << Admin::getDepartment() << "\n";
    cout << "Responsibility: Manages student housing and welfare\n";
    
    // Contact Information
    if (!contacts.empty()) {
        cout << "\n--- Contact Information ---\n";
        for (const auto& contact : contacts) {
            cout << "  " << contact.first << ": " << contact.second << "\n";
        }
    }
    
    cout << "\n════════════════════════════════════════════\n\n";
}
