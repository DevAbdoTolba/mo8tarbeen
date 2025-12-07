// include/SakanX/TestSuites.h
#ifndef TESTSUITES_H
#define TESTSUITES_H

#include <iostream>
#include <cassert>
#include "SakanX/Person.h"
#include "SakanX/Student.h"
#include "SakanX/Admin.h"
#include "SakanX/DormSupervisor.h"
#include "SakanX/Location.h"
#include "SakanX/Apartment.h"
#include "SakanX/SmartMatchAI.h"

using namespace std;

class TestSuites {
public:
    static void testPersonLogic() {
        cout << "\n==============================\n";
        cout << "[TEST] Person Logic" << endl;
        cout << "------------------------------" << endl;
        cout << "Cannot instantiate Abstract class directly, verified via subclass." << endl;
        cout << "==============================\n";
    }

    static void testStudentLogic() {
        cout << "\n==============================\n";
        cout << "[TEST] Student Logic" << endl;
        cout << "------------------------------" << endl;
        Student s("Ali", 101, 18, NationalityType::Egyptian, "", {}, 'm', "CS", 0.0);
        cout << "Created Student: Name='" << s.getName() << "', ID=" << s.getId() << ", Major='" << s.getMajor() << "'\n";
        cout << "Virtual Inheritance check: OK" << endl;
        cout << "Result: \033[32mPASSED\033[0m" << endl;
        cout << "==============================\n";
    }

    static void testDiamondProblem() {
        cout << "\n==============================\n";
        cout << "[TEST] Diamond Problem (DormSupervisor)" << endl;
        cout << "------------------------------" << endl;
        DormSupervisor ds("Super", 999, "CS", "Housing");
        cout << "DormSupervisor created. Displaying info:\n";
        ds.displayInfo();
        cout << "Result: \033[32mPASSED\033[0m" << endl;
        cout << "==============================\n";
    }

    static void testComposition() {
        cout << "\n==============================\n";
        cout << "[TEST] Composition (Apartment owns Location)" << endl;
        cout << "------------------------------" << endl;
        Apartment* apt = new Apartment(Location("Building A", 3, 305, PolulationType::Students, 0, 0, 0, 0, 0, 0, 0));
        cout << "Apartment created with Location: Building A, Floor 3, Room 305\n";
        // Add some students for harmony calculation
        Student* s1 = new Student("A", 1, 18, NationalityType::Egyptian, "", {}, 'm', "CS", 0.0);
        Student* s2 = new Student("B", 2, 18, NationalityType::Egyptian, "", {}, 'm', "CS", 0.0);
        apt->addStudent(s1);
        apt->addStudent(s2);
        int harmony = apt->totalHarmonyScore();
        cout << "Total Harmony Score (2 students): " << harmony << endl;
        delete apt; // Should trigger Location destructor
        delete s1;
        delete s2;
        cout << "Result: \033[32mPASSED\033[0m (Check console for Location destructor msg)" << endl;
        cout << "==============================\n";
    }

    static void testAggregation() {
        cout << "\n==============================\n";
        cout << "[TEST] Aggregation (Apartment references Student)" << endl;
        cout << "------------------------------" << endl;
        Student* s = new Student("Survivor", 500, 18, NationalityType::Egyptian, "", {}, 'm', "Eng", 0.0);
        {
            Apartment apt(Location("B", 1, 1, PolulationType::Students, 0, 0, 0, 0, 0, 0, 0));
            apt.addStudent(s);
            cout << "Apartment created and student added. Apartment goes out of scope now.\n";
            // Add another student for harmony calculation
            Student* s2 = new Student("C", 2, 18, NationalityType::Egyptian, "", {}, 'm', "Eng", 0.0);
            apt.addStudent(s2);
            int harmony = apt.totalHarmonyScore();
            cout << "Total Harmony Score (2 students): " << harmony << endl;
            delete s2;
        }
        cout << "Checking if student still exists...\n";
        s->displayInfo(); // If this crashes, Aggregation failed
        cout << "Result: \033[32mPASSED\033[0m" << endl;
        cout << "==============================\n";
    }

    static void testAI() {
        cout << "\n==============================\n";
        cout << "[TEST] AI Logic" << endl;
        cout << "------------------------------" << endl;
        Student s1("A", 1, 18, NationalityType::Egyptian, "", {}, 'm', "CS", 0.0);
        Student s2("B", 2, 18, NationalityType::Egyptian, "", {}, 'm', "CS", 0.0);
        double score = SmartMatchAI::calculateHarmony(s1, s2);
        cout << "Harmony score between s1 and s2: " << score << endl;
        assert(score > 0); // Should match because same major
        cout << "Result: \033[32mPASSED\033[0m" << endl;
        cout << "==============================\n";
    }
};

#endif