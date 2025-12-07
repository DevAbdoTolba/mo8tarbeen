#ifndef CLI_H
#define CLI_H

#include <vector>
#include <string>
#include <iostream>
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
    // The "Database"
    vector<Student*> students;
    vector<Apartment*> apartments;
    
    // We keep one supervisor to act as the "System Admin" logic handler
    DormSupervisor* supervisor; 

    // --- UI Helpers ---
    void clearScreen() const;
    void printHeader(const string& title) const;
    void printLine() const;
    void waitForInput() const;
    void printProgressBar(double percentage) const; // For that sweet AI visualization

    // --- Menu Flows ---
    void menuManageStudents();
    void menuManageApartments();
    void menuSmartMatch();
    
    // --- Actions ---
    void actionAddStudent();
    void actionAddApartment();
    void actionAssignStudent();
    void actionViewDetails();

    // Helper to find objects
    Student* selectStudent(const string& prompt);
    Apartment* selectApartment(const string& prompt);

public:
    CLI();
    ~CLI();
    void run(); // The main loop
};

#endif // CLI_H