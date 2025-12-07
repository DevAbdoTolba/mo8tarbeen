#include <iostream>
#include "SakanX/Person.h"
#include "SakanX/Student.h"
#include "SakanX/Admin.h"
#include "SakanX/DormSupervisor.h"
#include "SakanX/Location.h"
#include "SakanX/Apartment.h"
#include "SakanX/SmartMatchAI.h"
#include "SakanX/CLI.h"
#include "TestSuites.h"




int main() {


    // TestSuites::testAggregation();
    // TestSuites::testAI();
    // TestSuites::testComposition();
    // TestSuites::testDiamondProblem();
    // TestSuites::testPersonLogic();
    // TestSuites::testStudentLogic();
    



    CLI app;
    app.run();



    // $Person 
    // $Admin read write 
    // $DormSupervisor => create $Apartment => $Location 
    // $Student ($SmartMatchAI) => Select 


    return 0;
}
