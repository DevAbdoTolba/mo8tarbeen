#ifndef DORMSUPERVISOR_H
#define DORMSUPERVISOR_H

#include "Student.h"
#include "Admin.h"
#include "Apartment.h"
#include <vector>

using namespace std;

class DormSupervisor : public Student, public Admin
{
public:
    DormSupervisor(const std::string &name, int id, const std::string &major, const std::string &department);
    DormSupervisor(const string &name, int id, const string &ssn, int age,
                   const string &major, const string &department);

    DormSupervisor(const string &name, int id, const string &ssn, int age,
                   NationalityType nationality, const string &major,
                   const string &department,
                   const vector<pair<string, string>> &contacts);
    int countEmptyApartments(const vector<Apartment *> &apartments) const;
    int countFullApartments(const vector<Apartment *> &apartments) const;
    Apartment *findApartmentByStudent(Student *student, const vector<Apartment *> &apartments) const;
    Apartment *findCheapestApartment(const vector<Apartment *> &apartments) const;
    ~DormSupervisor();

    void displayInfo() const override;
};

#endif // DORMSUPERVISOR_H
