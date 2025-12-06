#include <SakanX/Tag.h>
#include <string>
using namespace std;

Tag::Tag(int id, string name, int value) : id(id), name(name), value(value) {}
Tag::~Tag() {}
int Tag::getValue() const {
    return value;
}