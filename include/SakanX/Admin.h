#ifndef ADMIN_H
#define ADMIN_H

#include "Person.h"
#include "Student.h"
#include "Apartment.h"
#include <string>
#include <vector>

using namespace std;

class Admin : public virtual Person {
public:
    Admin(const string& name, int id, const string& ssn, int age, 
      const string& department);

      Admin(const string& name, int id, const string& ssn, int age, 
      NationalityType nationality, const string& department,
      const vector<pair<string, string>>& contacts = {});
    ~Admin();


    // Getters
    string getDepartment() const;
    int getNumOfStudentsManaged() const;
    
    // Setters
    void setDepartment(const std::string& newDepartment);



    void displayInfo() const ;
    void assignStudentToApartment(Student* student, Apartment* apartment);
    void removeStudentFromApartment(Student* student, Apartment* apartment);
    void viewAllApartments(const vector<Apartment*>& apartments) const;
    void transferStudent(Student* student, Apartment* from, Apartment* to);
    void calculateTotalRevenue(const vector<Apartment*>& apartments) const;

private:
    string department;
    int studentsManaged;  // num of students under my management
};

#endif // ADMIN_H
