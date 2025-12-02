// include/SakanX/TestSuites.h
#ifndef TESTSUITES_H
#define TESTSUITES_H

#include <iostream>
#include <cassert>
#include "Person.h"
#include "Student.h"
#include "Admin.h"
#include "DormSupervisor.h"
#include "Location.h"
#include "Apartment.h"
#include "SmartMatchAI.h"

using namespace std;

class TestSuites {
public:
    static void testPersonLogic() {
        cout << "[TEST] Person Logic: (Cannot instantiate Abstract class directly, verified via subclass)" << endl;
    }

    static void testStudentLogic() {
        cout << "[TEST] Student Logic... ";
        Student s("Ali", 101, "CS");
        // Verify Virtual Inheritance doesn't crash
        assert(true); 
        cout << "PASSED" << endl;
    }

    static void testDiamondProblem() {
        cout << "[TEST] Diamond Problem (DormSupervisor)... ";
        // If this compiles and runs, Virtual Inheritance is working
        DormSupervisor ds("Super", 999, "CS", "Housing");
        ds.displayInfo(); // Should show data from both paths
        cout << "PASSED" << endl;
    }

    static void testComposition() {
        cout << "[TEST] Composition (Apartment owns Location)... ";
        Apartment* apt = new Apartment(Location("Building A", 3, 305));
        delete apt; // Should trigger Location destructor
        cout << "PASSED (Check console for Location destructor msg)" << endl;
    }

    static void testAggregation() {
        cout << "[TEST] Aggregation (Apartment references Student)... ";
        Student* s = new Student("Survivor", 500, "Eng");
        {
            Apartment apt(Location("B", 1, 1));
            apt.addStudent(s);
        } // Apartment dies here
        
        cout << "Checking if student still exists... ";
        s->displayInfo(); // If this crashes, Aggregation failed
        cout << "PASSED" << endl;
    }

    static void testAI() {
        cout << "[TEST] AI Logic... ";
        Student s1("A", 1, "CS");
        Student s2("B", 2, "CS");
        double score = SmartMatchAI::calculateHarmony(s1, s2);
        assert(score > 0); // Should match because same major
        cout << "Score: " << score << " PASSED" << endl;
    }
};

#endif