#include <iostream>
//#include "Location.h"
//
using namespace std;

class Location{
    private:
        string building;
        int floor;
        int roomNumber;
    public:
        Location(string buidling , int floor , int roomNumber){
            this->roomNumber = roomNumber;
            this->floor = floor;
            this->building = buidling;
        }

        void diplayLocation(){
            cout<< building
                << " , Floor : "<<floor
                <<" , RoomNumber : "<<roomNumber
                <<endl;
        }
};
