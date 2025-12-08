#ifndef DORMSUPERVISOR_H
#define DORMSUPERVISOR_H

#include "Student.h"
#include "Admin.h"
#include "Apartment.h"
#include <vector>
#include <string>

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
    HousingStats generateReport(const vector<Apartment *> &apartments) const;

    // Dorm Supervisor specific capabilities
    void manage_apartment(Apartment* apartment, Student* toAssign = nullptr, Student* toRemove = nullptr, bool flagMaintenance = false);
    void enforce_dorm_rules(const vector<Student*>& students, const string& rule) const;
    void report_issues(const string& issue, Apartment* apartment = nullptr) const;
    bool access_controls(const Student* requester, const string& resource) const;
  
    ~DormSupervisor();

    void displayInfo() const override;
};

#endif // DORMSUPERVISOR_H
