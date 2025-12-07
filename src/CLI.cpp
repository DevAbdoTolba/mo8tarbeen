#include "SakanX/CLI.h"
#include <iomanip> // For std::setw
#include <limits>  // For numeric_limits

// Constructor: Seed some dummy data so the app isn't empty on launch
CLI::CLI() {
    supervisor = new DormSupervisor("Dr. Admin", 1, "Head Supervisor", "Admin Dept");

    // Seed Data
    students.push_back(new Student("Ahmed Fathi", 101, 20, NationalityType::Egyptian, "SSN1", {}, 'm', "CS", 0.8));
    students.push_back(new Student("Mostafa Merzk", 102, 21, NationalityType::Egyptian, "SSN2", {}, 'm', "CS", 0.7));
    students.push_back(new Student("Sara Connor", 103, 19, NationalityType::NonArab, "SSN3", {}, 'f', "Eng", 0.5));

    Location loc("Building A", 1, 101, PolulationType::Students, 50, 50, 50, 50, 2, 1, 2500);
    Apartment* apt = new Apartment(loc);
    apt->setId(101);
    apt->setCapacity(3);
    apt->setRentPrice(2500);
    apartments.push_back(apt);
}

// Destructor: Clean up memory!
CLI::~CLI() {
    delete supervisor;
    for (auto s : students) delete s;
    for (auto a : apartments) delete a;
    std::cout << "System Shutdown. Memory Cleaned." << endl;
}

// --- UTILITIES ---

void CLI::clearScreen() const {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void CLI::printLine() const {
    cout << CYAN << "------------------------------------------------------------" << RESET << endl;
}

void CLI::printHeader(const string& title) const {
    clearScreen();
    cout << BLUE << "============================================================" << RESET << endl;
    cout << BOLD << "   SAKAN-X SYSTEM  |  " << title << RESET << endl;
    cout << BLUE << "============================================================" << RESET << endl;
    cout << endl;
}

void CLI::waitForInput() const {
    cout << "\n" << YELLOW << "[Press Enter to Continue]" << RESET;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void CLI::printProgressBar(double percentage) const {
    int width = 20;
    int progress = (percentage / 100.0) * width;
    
    cout << "Harmony: [";
    for (int i = 0; i < width; ++i) {
        if (i < progress) {
            if (percentage > 80) cout << GREEN << "|" << RESET;
            else if (percentage > 50) cout << YELLOW << "|" << RESET;
            else cout << RED << "|" << RESET;
        } else {
            cout << " ";
        }
    }
    cout << "] " << (int)percentage << "%" << endl;
}

// --- MAIN LOOP ---

void CLI::run() {
    bool running = true;
    while (running) {
        printHeader("MAIN DASHBOARD");
        
        cout << "  " << BOLD << "1." << RESET << " Manage Students\n";
        cout << "  " << BOLD << "2." << RESET << " Manage Apartments\n";
        cout << "  " << BOLD << "3." << RESET << " SmartMatch AI (Find Roommates)\n";
        cout << "  " << BOLD << "4." << RESET << " Supervisor Statistics\n";
        cout << "  " << RED  << "0." << RESET << " Exit Application\n";
        
        cout << "\nSelect Option: ";
        int choice;
        if (!(cin >> choice)) {
            cin.clear(); cin.ignore(10000, '\n'); choice = -1;
        }

        switch (choice) {
            case 1: menuManageStudents(); break;
            case 2: menuManageApartments(); break;
            case 3: menuSmartMatch(); break;
            case 4: 
                printHeader("STATISTICS");
                supervisor->calculateTotalRevenue(apartments);
                waitForInput();
                break;
            case 0: running = false; break;
            default: cout << RED << "Invalid selection!" << RESET << endl; waitForInput();
        }
    }
}

// --- STUDENT MENU ---

void CLI::menuManageStudents() {
    bool back = false;
    while (!back) {
        printHeader("STUDENT MANAGEMENT");
        
        // Minimal List View
        cout << std::left << std::setw(10) << "ID" << std::setw(20) << "Name" << std::setw(10) << "Major" << endl;
        printLine();
        for (const auto& s : students) {
            cout << std::left << std::setw(10) << s->getId() 
                 << std::setw(20) << s->getName() 
                 << std::setw(10) << s->getMajor() << endl;
        }
        printLine();

        cout << "\n[1] Add New Student\n[2] View Full Details\n[0] Back\nChoice: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: actionAddStudent(); break;
            case 2: actionViewDetails(); break;
            case 0: back = true; break;
        }
    }
}

void CLI::actionAddStudent() {
    printHeader("NEW STUDENT WIZARD");
    
    string name, major, ssn;
    int id, age;
    char gender;

    cout << "Enter ID: "; cin >> id;
    cout << "Enter Name: "; cin.ignore(); getline(cin, name);
    cout << "Enter Age: "; cin >> age;
    cout << "Enter Gender (m/f): "; cin >> gender;
    cout << "Enter Major: "; cin >> major;
    cout << "Enter SSN: "; cin >> ssn;

    // Creating a standard Egyptian student by default for simplicity
    Student* s = new Student(name, id, age, NationalityType::Egyptian, ssn, {}, gender, major, 0.5);
    students.push_back(s);

    cout << GREEN << "\nStudent Added Successfully!" << RESET << endl;
    waitForInput();
}

void CLI::actionViewDetails() {
    Student* s = selectStudent("Enter Student ID to view: ");
    if(s) {
        printHeader(s->getName());
        s->displayInfo();
        
        // Show tags
        cout << "\nTags: ";
        for(auto t : s->getTags()) cout << "#" << t->getValue() << " "; // Assuming tag has name, using value for now based on your code
        cout << endl;
        
        waitForInput();
    }
}

// --- APARTMENT MENU ---

void CLI::menuManageApartments() {
    bool back = false;
    while (!back) {
        printHeader("APARTMENT MANAGEMENT");

        cout << std::left << std::setw(10) << "ID" << std::setw(15) << "Capacity" << std::setw(15) << "Price (EGP)" << "Occupancy" << endl;
        printLine();
        for (const auto& apt : apartments) {
            cout << std::left << std::setw(10) << apt->getId() 
                 << std::setw(15) << apt->getCapacity() 
                 << std::setw(15) << apt->getRentPrice()
                 << "[" << apt->getCurrentTenants() << "/" << apt->getCapacity() << "]" << endl;
        }
        printLine();

        cout << "\n[1] Add Apartment\n[2] Assign Student to Apartment\n[0] Back\nChoice: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: actionAddApartment(); break;
            case 2: actionAssignStudent(); break;
            case 0: back = true; break;
        }
    }
}

void CLI::actionAddApartment() {
    printHeader("ADD APARTMENT");
    // Simplified logic for brevity
    int id, cap, price;
    cout << "ID: "; cin >> id;
    cout << "Capacity: "; cin >> cap;
    cout << "Price: "; cin >> price;

    Location loc("New Bldg", 1, 1, PolulationType::Students, 0,0,0,0,0,0,0);
    Apartment* apt = new Apartment(loc);
    apt->setId(id);
    apt->setCapacity(cap);
    apt->setRentPrice(price);
    
    apartments.push_back(apt);
    cout << GREEN << "Apartment Added!" << RESET << endl;
    waitForInput();
}

void CLI::actionAssignStudent() {
    Student* s = selectStudent("Enter Student ID to assign: ");
    if (!s) return;

    Apartment* a = selectApartment("Enter Apartment ID: ");
    if (!a) return;

    // Use the Supervisor Privilege logic
    cout << "\nAttempting assignment..." << endl;
    try {
        supervisor->assignStudentToApartment(s, a);
        // Note: Your Admin.cpp prints "Admin X assigned...", which is good feedback.
    } catch (...) {
        cout << RED << "Assignment Failed!" << RESET << endl;
    }
    waitForInput();
}

// --- SMART MATCH MENU ---

void CLI::menuSmartMatch() {
    printHeader("SMART MATCH AI");
    cout << "Select two students to check compatibility." << endl;
    
    Student* s1 = selectStudent("Enter First Student ID: ");
    if(!s1) return;
    
    Student* s2 = selectStudent("Enter Second Student ID: ");
    if(!s2) return;

    cout << "\nAnalyzing Compatibility..." << endl;
    double score = SmartMatchAI::calculateHarmony(*s1, *s2);
    
    printProgressBar(score);
    
    if (score > 80) cout << GREEN << "Recommendation: Perfect Roommates!" << RESET << endl;
    else if (score > 50) cout << YELLOW << "Recommendation: Compatible." << RESET << endl;
    else cout << RED << "Recommendation: High conflict risk." << RESET << endl;

    waitForInput();
}

// --- HELPERS ---

Student* CLI::selectStudent(const string& prompt) {
    int id;
    cout << prompt;
    cin >> id;
    for (auto s : students) {
        if (s->getId() == id) return s;
    }
    cout << RED << "Student not found!" << RESET << endl;
    waitForInput();
    return nullptr;
}

Apartment* CLI::selectApartment(const string& prompt) {
    int id;
    cout << prompt;
    cin >> id;
    for (auto a : apartments) {
        if (a->getId() == id) return a;
    }
    cout << RED << "Apartment not found!" << RESET << endl;
    waitForInput();
    return nullptr;
}