#include "SakanX/CLI.h"
#include <iomanip>

// Constructor
CLI::CLI() {
    supervisor = new DormSupervisor("System Admin", 1, "Head Supervisor", "Admin Dept");
    seedData();
}

CLI::~CLI() {
    delete supervisor;
    for (auto s : students) delete s;
    for (auto a : apartments) delete a;
    cout << "System Shutdown. Memory Cleaned." << endl;
}

// --- SEED DATA (For Presentation) ---
void CLI::seedData() {
    // Create Students
    Student* s1 = new Student("Ahmed Fathi", 101, 21, NationalityType::Egyptian, "SSN101", {}, 'm', "CS", 0.8);
    // Add some tags to s1
    if(Student::availableTags.size() > 0) s1->addTag(Student::availableTags[0]); // Early Bird
    if(Student::availableTags.size() > 2) s1->addTag(Student::availableTags[2]); // Study Focused
    
    Student* s2 = new Student("Mostafa Merzk", 102, 22, NationalityType::Egyptian, "SSN102", {}, 'm', "CS", 0.6);
    if(Student::availableTags.size() > 10) s2->addTag(Student::availableTags[10]); // Gamer

    students.push_back(s1);
    students.push_back(s2);

    // Create Apartment
    Location loc("Tower A", 3, 305, PolulationType::Students, 100, 50, 200, 10, 1.5, 0.5, 3000);
    Apartment* apt = new Apartment(loc);
    apt->setId(501);
    apt->setCapacity(3);
    apt->setRentPrice(3000);
    apt->setApartmentArea(120);
    apt->setHasWifi(true);
    apartments.push_back(apt);
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

// --- ROBUST INPUTS ---

int CLI::inputInt(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            return value;
        }
        cout << RED << "Invalid input. Please enter a number." << RESET << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

double CLI::inputDouble(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            return value;
        }
        cout << RED << "Invalid input. Please enter a number." << RESET << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

string CLI::inputString(const string& prompt) {
    string value;
    cout << prompt;
    cin.ignore(); 
    getline(cin, value);
    return value;
}

bool CLI::getYesNo(const string& prompt) {
    char c;
    cout << prompt << " (y/n): ";
    cin >> c;
    return (c == 'y' || c == 'Y');
}

// --- VALIDATION HELPERS ---

bool CLI::isStudentIdUnique(int id) const {
    for (const auto& s : students) {
        if (s->getId() == id) return false;
    }
    return true;
}

bool CLI::isApartmentIdUnique(int id) const {
    for (const auto& a : apartments) {
        if (a->getId() == id) return false;
    }
    return true;
}

bool CLI::isStudentInApartment(Student* s, Apartment* a) const {
    const vector<Student*>& residents = a->getStudents();
    for(auto* res : residents) {
        if(res && res->getId() == s->getId()) return true;
    }
    return false;
}

// --- MAIN LOOP ---

void CLI::run() {
    bool running = true;
    while (running) {
        printHeader("MAIN DASHBOARD");
        
        cout << "  " << BOLD << "1." << RESET << " Manage Students " << CYAN << "(Create, Tags, View)" << RESET << "\n";
        cout << "  " << BOLD << "2." << RESET << " Manage Apartments " << CYAN << "(Create, Assign, Details)" << RESET << "\n";
        cout << "  " << BOLD << "3." << RESET << " SmartMatch AI " << CYAN << "(Check Compatibility)" << RESET << "\n";
        cout << "  " << BOLD << "4." << RESET << " Supervisor Stats " << CYAN << "(Revenue, Occupancy)" << RESET << "\n";
        cout << "  " << RED  << "0." << RESET << " Exit\n";
        
        int choice = inputInt("\nSelect Option: ");

        switch (choice) {
            case 1: menuManageStudents(); break;
            case 2: menuManageApartments(); break;
            case 3: menuSmartMatch(); break;
            case 4: 
                printHeader("STATISTICS");
                supervisor->calculateTotalRevenue(apartments);
                cout << "Empty Apartments: " << supervisor->countEmptyApartments(apartments) << endl;
                cout << "Full Apartments: " << supervisor->countFullApartments(apartments) << endl;
                waitForInput();
                break;
            case 0: running = false; break;
            default: cout << RED << "Invalid selection!" << RESET << endl; waitForInput();
        }
    }
}

// ==========================================
// ============ STUDENT LOGIC ===============
// ==========================================

void CLI::menuManageStudents() {
    bool back = false;
    while (!back) {
        printHeader("STUDENT MANAGEMENT");
        
        // Headers
        cout << std::left << std::setw(8) << "ID" << std::setw(20) << "Name" << std::setw(10) << "Major" << std::setw(10) << "Tags" << endl;
        printLine();
        
        for (const auto& s : students) {
            cout << std::left << std::setw(8) << s->getId() 
                 << std::setw(20) << s->getName() 
                 << std::setw(10) << s->getMajor() 
                 << std::setw(10) << s->getTags().size() << endl;
        }
        printLine();

        cout << "\n[1] Add New Student\n[2] Manage Student Tags\n[3] View Details\n[0] Back\n";
        int choice = inputInt("Choice: ");

        switch (choice) {
            case 1: actionAddStudent(); break;
            case 2: {
                Student* s = selectStudent("Enter Student ID to Edit Tags: ");
                if(s) actionManageTags(s);
                break;
            }
            case 3: actionViewStudentDetails(); break;
            case 0: back = true; break;
        }
    }
}

void CLI::actionAddStudent() {
    printHeader("NEW STUDENT WIZARD");
    
    // 1. Basic Inputs
    int id = inputInt("Enter Unique ID: ");
    
    // VALIDATION: Unique ID
    if (!isStudentIdUnique(id)) {
        cout << RED << "Error: Student ID " << id << " already exists!" << RESET << endl;
        waitForInput();
        return;
    }

    string name = inputString("Enter Name: ");
    int age = inputInt("Enter Age: ");
    string major = inputString("Enter Major: ");
    
    char gender;
    cout << "Enter Gender (m/f): "; cin >> gender;
    
    string ssn; 
    cout << "Enter SSN: "; cin >> ssn;

    // 2. Creation
    try {
        Student* s = new Student(name, id, age, NationalityType::Egyptian, ssn, {}, gender, major, 0.5);
        
        // 3. Prompt for Tags immediately
        if(getYesNo("Do you want to add personality tags now?")) {
            actionManageTags(s);
        }

        students.push_back(s);
        cout << GREEN << "\nStudent Created Successfully!" << RESET << endl;
    } catch (...) {
        cout << RED << "Failed to create student due to internal error." << RESET << endl;
    }
    
    waitForInput();
}

void CLI::actionManageTags(Student* s) {
    bool done = false;
    while(!done) {
        printHeader("EDIT TAGS FOR: " + s->getName());
        
        cout << "Current Tags: ";
        const set<Tag*>& currentTags = s->getTags();
        if(currentTags.empty()) cout << "None";
        for(auto t : currentTags) cout << "[" << t->getValue() << "] ";
        cout << "\n\nAvailable Tags to Toggle:\n";
        
        // Display all available static tags
        for(size_t i = 0; i < Student::availableTags.size(); ++i) {
            Tag* t = Student::availableTags[i];
            bool hasTag = s->findTag(t);
            
            // Visual Toggle Indicator
            string status = hasTag ? (GREEN "[EQUIPPED]" RESET) : (YELLOW "[        ]" RESET);
            
            cout << i << ". " << status << " Val:" << std::setw(3) << t->getValue() << " | ";
            // Simple logic to print tag name if your Tag class supported it publicly, 
            // but relying on ID/Index for now based on your provided Tag.cpp
            cout << Student::availableTags[i]->getName() << endl; 
        }

        cout << "\nEnter Tag Index to toggle (or -1 to finish): ";
        int idx;
        if(cin >> idx) {
            if(idx == -1) {
                done = true;
            } else if (idx >= 0 && idx < Student::availableTags.size()) {
                Tag* target = Student::availableTags[idx];
                if(s->findTag(target)) {
                    s->removeTag(target);
                    cout << RED << "Removed Tag." << RESET << endl;
                } else {
                    s->addTag(target);
                    cout << GREEN << "Added Tag." << RESET << endl;
                }
            } else {
                cout << RED << "Invalid Index." << RESET << endl;
            }
        } else {
            cin.clear(); cin.ignore();
            done = true;
        }
    }
}

void CLI::actionViewStudentDetails() {
    Student* s = selectStudent("Enter Student ID: ");
    if(!s) return;

    printHeader("DETAILS: " + s->getName());
    s->displayInfo();
    cout << "Age: " << s->getAge() << ", Gender: " << s->getGender() << endl;
    cout << "SSN: " << s->getSSN() << endl;
    cout << "\n--- Personality Profile ---\n";
    cout << "Total Tag Value: " << s->calculateTotalTagValue() << endl;
    cout << "Tags equipped: " << s->getTags().size() << endl;
    waitForInput();
}

// ==========================================
// ============ APARTMENT LOGIC =============
// ==========================================

void CLI::menuManageApartments() {
    bool back = false;
    while (!back) {
        printHeader("APARTMENT MANAGEMENT");

        cout << std::left << std::setw(8) << "ID" << std::setw(15) << "Bldg/Floor" << std::setw(12) << "Rent" << "Occupancy" << endl;
        printLine();
        for (const auto& apt : apartments) {
            string locStr = apt->getLocation().getBuilding() + "/" + to_string(apt->getLocation().getFloor());
            cout << std::left << std::setw(8) << apt->getId() 
                 << std::setw(15) << locStr
                 << std::setw(12) << apt->getRentPrice()
                 << "[" << apt->getCurrentTenants() << "/" << apt->getCapacity() << "]" << endl;
        }
        printLine();

        cout << "\n[1] Add Apartment\n[2] Assign Student\n[3] View Details\n[0] Back\nChoice: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: actionAddApartment(); break;
            case 2: actionAssignStudent(); break;
            case 3: actionApartmentDetails(); break;
            case 0: back = true; break;
        }
    }
}

void CLI::actionAddApartment() {
    printHeader("ADD APARTMENT WIZARD");
    
    // 1. Core ID Validation
    int id = inputInt("Enter Apartment ID: ");
    if(!isApartmentIdUnique(id)) {
        cout << RED << "ID already exists!" << RESET << endl;
        waitForInput();
        return;
    }

    // 2. Detailed Location Data
    cout << CYAN << "--- Location Details ---" << RESET << endl;
    string bldg = inputString("Building Name: ");
    int floor = inputInt("Floor Number: ");
    int room = inputInt("Room Number: ");
    
    // 3. Apartment Specs
    cout << CYAN << "\n--- Apartment Specs ---" << RESET << endl;
    int cap = inputInt("Max Capacity: ");
    int price = inputInt("Rent Price (EGP): ");
    int area = inputInt("Area (sqm): ");
    bool wifi = getYesNo("Has WiFi?");
    bool rats = getYesNo("History of Rats?"); // Honest landlord check :D

    // Construct Location
    // Providing reasonable defaults for the metric distances as they are hard to input manually
    Location loc(bldg, floor, room, PolulationType::Students, 50, 50, 100, 20, 1.0, 2.0, price);

    Apartment* apt = new Apartment(loc);
    apt->setId(id);
    apt->setCapacity(cap);
    apt->setRentPrice(price);
    apt->setApartmentArea(area);
    apt->setHasWifi(wifi);
    apt->setHadRatsBefore(rats);

    apartments.push_back(apt);
    cout << GREEN << "\nApartment Added Successfully!" << RESET << endl;
    waitForInput();
}

void CLI::actionAssignStudent() {
    printHeader("ASSIGN STUDENT TO APARTMENT");

    Student* s = selectStudent("Enter Student ID: ");
    if (!s) return;

    Apartment* a = selectApartment("Enter Apartment ID: ");
    if (!a) return;

    // VALIDATION: Duplicate Check
    if (isStudentInApartment(s, a)) {
        cout << RED << "\nERROR: This student is ALREADY in this apartment!" << RESET << endl;
        waitForInput();
        return;
    }

    // Attempt Assignment
    try {
        // The Admin class has the logic, let's use the supervisor instance
        cout << "Processing..." << endl;
        supervisor->assignStudentToApartment(s, a);
        // Note: Apartment::addStudent writes to cout, so we see the result
    } catch (const char* msg) {
        cout << RED << "Error: " << msg << RESET << endl;
    } catch (...) {
        cout << RED << "Unknown error occurred." << RESET << endl;
    }
    
    waitForInput();
}

void CLI::actionApartmentDetails() {
    Apartment* a = selectApartment("Enter Apartment ID: ");
    if(!a) return;
    
    printHeader("APARTMENT " + to_string(a->getId()));
    a->displayApartmentInfo(); // This prints internal details
    cout << "\nTotal Harmony Score: " << a->totalHarmonyScore() << endl;
    waitForInput();
}

// ==========================================
// ============ SMART MATCH LOGIC ===========
// ==========================================

void CLI::menuSmartMatch() {
    printHeader("SMART MATCH AI");
    
    if(students.size() < 2) {
        cout << RED << "Not enough students to compare." << RESET << endl;
        waitForInput();
        return;
    }

    Student* s1 = selectStudent("Enter First Student ID: ");
    if(!s1) return;
    
    Student* s2 = selectStudent("Enter Second Student ID: ");
    if(!s2) return;

    if(s1 == s2) {
        cout << RED << "You cannot match a student with themselves!" << RESET << endl;
        waitForInput();
        return;
    }

    cout << "\nRunning Algorithm..." << endl;
    double score = SmartMatchAI::calculateHarmony(*s1, *s2);
    
    printProgressBar(score);
    
    cout << "Details:\n";
    cout << "S1 Tags: " << s1->calculateTotalTagValue() << " | S2 Tags: " << s2->calculateTotalTagValue() << endl;
    
    if (score > 80) cout << GREEN << "Verdict: HIGH COMPATIBILITY" << RESET << endl;
    else if (score > 50) cout << YELLOW << "Verdict: MODERATE" << RESET << endl;
    else cout << RED << "Verdict: LOW COMPATIBILITY" << RESET << endl;

    waitForInput();
}

// --- SELECTORS ---

Student* CLI::selectStudent(const string& prompt) {
    int id = inputInt(prompt);
    for (auto s : students) {
        if (s->getId() == id) return s;
    }
    cout << RED << "Student ID not found." << RESET << endl;
    waitForInput();
    return nullptr;
}

Apartment* CLI::selectApartment(const string& prompt) {
    int id = inputInt(prompt);
    for (auto a : apartments) {
        if (a->getId() == id) return a;
    }
    cout << RED << "Apartment ID not found." << RESET << endl;
    waitForInput();
    return nullptr;
}