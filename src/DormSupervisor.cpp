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

void DormSupervisor::manage_apartment(Apartment* apartment, Student* toAssign, Student* toRemove, bool flagMaintenance) {
    if (!apartment) throw std::invalid_argument("Apartment pointer cannot be null");

    if (toAssign) {
        Admin::assignStudentToApartment(toAssign, apartment);
    }
    if (toRemove) {
        Admin::removeStudentFromApartment(toRemove, apartment);
    }

    if (flagMaintenance) {
        apartment->setHadRatsBefore(true);
    }
}

void DormSupervisor::enforce_dorm_rules(const vector<Student*>& students, const string& rule) const {
    if (rule.empty()) throw std::invalid_argument("Rule must be provided for enforcement");
    for (auto* s : students) {
        if (!s) continue;
        std::cout << "[ENFORCE] Rule: " << rule << " | Student: " << s->getName() << std::endl;
    }
}

void DormSupervisor::report_issues(const string& issue, Apartment* apartment) const {
    if (issue.empty()) throw std::invalid_argument("Issue description cannot be empty");
    std::cout << "[REPORT] From DormSupervisor: " << issue;
    if (apartment) {
        std::cout << " | Apartment ID: " << apartment->getId();
    }
    std::cout << std::endl;
}

bool DormSupervisor::access_controls(const Student* requester, const string& resource) const {
    if (!requester) return false;
    if (resource.empty()) return false;

    bool hasAdminScope = true; // DormSupervisor inherits Admin
    bool sameNationality = requester->getNationality() == this->getNationality();
    bool genderAligned = requester->getGender() == this->getGender();

    if (hasAdminScope) return true;
    if (genderAligned && sameNationality) return true;
    return false;
}

void DormSupervisor::displayInfo() const
{
    // No output as per requirements
}