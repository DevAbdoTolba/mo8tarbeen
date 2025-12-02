#ifndef DORMSUPERVISOR_H
#define DORMSUPERVISOR_H

#include "Student.h"
#include "Admin.h"

class DormSupervisor : public Student, public Admin {
public:
    DormSupervisor(const std::string& name, int id, const std::string& major, const std::string& department);
    ~DormSupervisor();

    void displayInfo() const override;
};

#endif // DORMSUPERVISOR_H
