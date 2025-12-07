#include "SakanX/DormSupervisor.h"
#include <iostream>

using namespace std;

DormSupervisor::DormSupervisor(const std::string &name, int id, const std::string &major, const std::string &department)
        : Person(name, id),
            Student(name, id, 18, NationalityType::Egyptian, "", {}, 'm', major, 0.0),
            Admin(name, id, "", 18, department) {
        if (name.empty() || id < 0 || major.empty() || department.empty()) {
                throw std::invalid_argument("Invalid DormSupervisor constructor arguments");
        }
}

DormSupervisor::DormSupervisor(const string &name, int id, const string &ssn,
                                                             int age, const string &major, const string &department)
        : Person(name, id, ssn, age),
            Admin(name, id, ssn, age, department),
            Student(name, id, age, NationalityType::Egyptian, ssn, {}, 'm', major, 0.0) {
        if (name.empty() || id < 0 || ssn.empty() || age < 18 || major.empty() || department.empty()) {
                throw std::invalid_argument("Invalid DormSupervisor constructor arguments");
        }
}

DormSupervisor::DormSupervisor(const string &name, int id, const string &ssn,
                                                             int age, NationalityType nationality,
                                                             const string &major, const string &department,
                                                             const vector<pair<string, string>> &contacts)
        : Person(name, id, ssn, age, nationality, contacts),
            Student(name, id, age, nationality, ssn, contacts, 'm', major, 0.0),
            Admin(name, id, ssn, age, department) {
        if (name.empty() || id < 0 || ssn.empty() || age < 18 || major.empty() || department.empty()) {
                throw std::invalid_argument("Invalid DormSupervisor constructor arguments");
        }
}

int DormSupervisor::countEmptyApartments(const vector<Apartment *> &apartments) const
{
    int count = 0;
    for (auto *apt : apartments)
    {
        if (apt->getCurrentTenants() == 0)
            count++;
    }
    return count;
}

// Count of apartments that has students
int DormSupervisor::countFullApartments(const vector<Apartment *> &apartments) const
{
    int count = 0;
    for (auto *apt : apartments)
    {
        if (apt->getCurrentTenants() > 0)
            count++;
    }
    return count;
}

// Find apartment by student
Apartment *DormSupervisor::findApartmentByStudent(Student *student,
                                                  const vector<Apartment *> &apartments) const
{
    if (student == nullptr)
        return nullptr;

    for (auto *apt : apartments)
    {
        vector<Student *> residents = apt->getStudents();
        for (auto *resident : residents)
        {
            if (resident == student)
                return apt;
        }
    }
    return nullptr;
}

// Find cheapest apartment
Apartment *DormSupervisor::findCheapestApartment(const vector<Apartment *> &apartments) const
{
    Apartment *cheapest = nullptr;
    int minRent = 999999999;

    for (auto *apt : apartments)
    {
        double rent = apt->getRentPrice();
        if (rent < minRent)
        {
            minRent = rent;
            cheapest = apt;
        }
    }
    return cheapest;
}


HousingStats DormSupervisor::generateReport(const vector<Apartment *> &apartments) const {
    HousingStats stats = {0.0, 0.0, 0.0, 0, 0, 0, 0};
    
    stats.totalApartments = apartments.size();

    for (const auto* apt : apartments) {
        // 1. Financials
        int tenants = apt->getCurrentTenants();
        int cap = apt->getCapacity();
        double price = apt->getRentPrice();

        stats.currentTenants += tenants;
        stats.totalCapacity += cap;
        stats.totalRevenue += (tenants * price);
        
        // Potential: Revenue + (Empty Beds * Price)
        stats.potentialRevenue += (cap * price); 

        // 2. Maintenance Checks
        // If it had rats before or bad botgaz, flag it for review
        if (apt->hadRats() || !apt->isGoodBotgaz()) {
            stats.maintenanceIssues++;
        }
    }

    // 3. Occupancy Rate Calculation
    if (stats.totalCapacity > 0) {
        stats.occupancyRate = (static_cast<double>(stats.currentTenants) / stats.totalCapacity) * 100.0;
    }

    return stats;
}



DormSupervisor::~DormSupervisor() {}

void DormSupervisor::displayInfo() const
{
    // No output as per requirements
}