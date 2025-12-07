#ifndef CLI_H
#define CLI_H

#include <vector>
#include <string>
#include <iostream>
#include <limits>
#include <algorithm>
#include "Student.h"
#include "Apartment.h"
#include "DormSupervisor.h"
#include "SmartMatchAI.h"

// --- ZEN UI COLORS ---
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

using namespace std;

class CLI {
private:
    // Database
    vector<Student*> students;
    vector<Apartment*> apartments;
    DormSupervisor* supervisor; 

    // --- UI Helpers ---
    void clearScreen() const;
    void printHeader(const string& title) const;
    void printLine() const;
    void waitForInput() const;
    void printProgressBar(double percentage) const; 
    void printDashboardCard(const string& title, const string& value, const string& color) const;


    // --- Input Helpers (Robustness) ---
    int inputInt(const string& prompt);
    double inputDouble(const string& prompt);
    string inputString(const string& prompt);
    bool getYesNo(const string& prompt);

    // --- Validation Helpers ---
    bool isStudentIdUnique(int id) const;
    bool isApartmentIdUnique(int id) const;
    bool isStudentInApartment(Student* s, Apartment* a) const;

    // --- Menu Flows ---
    void menuManageStudents();
    void menuManageApartments();
    void menuSmartMatch();
    
    // --- Actions ---
    void actionAddStudent();
    void actionManageTags(Student* s); // NEW: Dedicated Tag Editor
    void actionViewStudentDetails();
    
    void actionAddApartment();
    void actionAssignStudent();
    void actionApartmentDetails();
    void actionShowStats();


    // Helper to find objects
    Student* selectStudent(const string& prompt);
    Apartment* selectApartment(const string& prompt);

    // Seed Data
    void seedData();


public:
    CLI();
    ~CLI();
    void run(); 
};

#endif // CLI_H