#ifndef ADMIN_H
#define ADMIN_H

#include "Person.h"
#include <string>

class Admin : public virtual Person {
public:
    Admin(const std::string& name, int id, const std::string& department);
    ~Admin();

    void displayInfo() const override;

private:
    std::string department;
};

#endif // ADMIN_H
