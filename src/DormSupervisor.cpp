#include "SakanX/DormSupervisor.h"
#include <iostream>

DormSupervisor::DormSupervisor(const std::string& name, int id, const std::string& major, const std::string& department)
    : Person(name, id), Student(name, id, major), Admin(name, id, department) {
    // TODO: [Mostafa Merzk] needs to implement logic here.
}

DormSupervisor::~DormSupervisor() {
    // TODO: [Mostafa Merzk] needs to implement logic here.
}

void DormSupervisor::displayInfo() const {
    // TODO: [Mostafa Merzk] needs to implement logic here.
}
