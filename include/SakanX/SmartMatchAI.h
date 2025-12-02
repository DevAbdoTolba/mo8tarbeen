#ifndef SMARTMATCHAI_H
#define SMARTMATCHAI_H

#include "Student.h"

class SmartMatchAI {
public:
    static double calculateHarmony(const Student& s1, const Student& s2);

private:
    SmartMatchAI() = delete; // To prevent instantiation
};

#endif // SMARTMATCHAI_H
