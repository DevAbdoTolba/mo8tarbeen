#ifndef TAG_H
#define TAG_H

#include <string>
using namespace std;
class Tag{
    int id;
    string name;
    int value;
public:
    Tag(int id, string name, int value);
    ~Tag();
    int getValue() const;
};
#endif // TAG_H