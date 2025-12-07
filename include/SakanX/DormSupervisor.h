#ifndef DORMSUPERVISOR_H
#define DORMSUPERVISOR_H

#include "Student.h"
#include "Admin.h"
#include "Apartment.h"
#include <vector>

using namespace std;

// A container for all our statistics
struct HousingStats {
    double totalRevenue;
    double potentialRevenue; // If all empty beds were sold
    double occupancyRate;    // Percentage
    int totalCapacity;
    int currentTenants;
    int totalApartments;
    int maintenanceIssues;   // Count of apartments with Rats or Bad Botgaz
};

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
    HousingStats generateReport(const vector<Apartment *> &apartments) const;
  
    ~DormSupervisor();

    void displayInfo() const override;
};

#endif // DORMSUPERVISOR_H
