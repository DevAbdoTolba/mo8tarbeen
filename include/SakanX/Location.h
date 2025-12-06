#ifndef LOCATION_H
#define LOCATION_H

#include <string>
#include <utility>
#include <random>
#include <ctime>
#include <iostream>

using namespace std;


//  ENUM CLASS
enum class PolulationType{
    Unknown,
    Families_With_Children,
    Young_Professionals,
    Retirees,
    Students,
    Mixed
};

//  EXTERNAL STRUCT
struct LocationMetrices{/// distance in meters
    double nearest_supermarket_m = 0;
    double nearest_pharmacy_m = 0;
    double nearest_mosque_m = 0;
    double nearest_transit_stop_m = 0;
    double nearest_hospital_km = 0.0;
    double nearest_college_km = 0.0;
    double median_prices = 0.0;
    double longitude = 0;
    double altitude = 0;
};

//  MAIN CLASS
class Location{
private:
    std::string building;
    int floor; /// the floor of the apartment
    int roomNumber; /// how many rooms in the apartment
    PolulationType population_type; /// the majority of the population in this location
    LocationMetrices lm; // and object to access the Location Metrices struct


    static double generate_random_coord(double min, double max); // to generate a rondom coordinates to be later used in other function
    static double generate_random_longitude(); // to generate a random longitude value
    static double generate_random_latitude(); // to generate a ranom latitude value
    std::string get_population_type_string() const; // to get the value of the population_type ENUM

public:
    // Constructor Declaration
    Location(std::string buidling , int floor , int roomNumber,
             PolulationType pop_type,
             double sup_m, double ph_m, double msq_m, double trn_m,
             double hosp_km, double coll_km, double prices);

    // Public Method Declaration
    void displayLocation() const;
    string Location_get_population_type_string() ;

    // GETTERS ////
    // for the variables declared inside of the class
    const std::string& getBuilding() const ;
    int getFloor() const ;
    int getRoomNumber() const ;
    PolulationType getPopulationType() const ;
        // the struct getters
        double getLongitude() const ;
        double getAltitude() const ;
        double getNearestSupermarketM() const ;
        double getNearestPharmacyM() const ;
        double getNearestMosqueM() const ;
        double getNearestTransitStopM() const ;
        double getNearestHospitalKM() const ;
        double getNearestCollegeKM() const ;
        double getMedianPrices() const ;

    // SETTERS ///
    // for the variables ceclared inside of the class
    void setBuilding(const std::string& newBuilding);
    void setFloor(int newFloor);
    void setRoomNumber(int newRoomNumber);
    void setPopulationType(PolulationType newPopType);
    void setLongitude(double val);
    void setAltitude(double val);
    void setNearestSupermarketM(double val);
    void setNearestPharmacyM(double val);
    void setNearestMosqueM(double val);
    void setNearestTransitStopM(double val);
    void setNearestHospitalKM(double val);
    void setNearestCollegeKM(double val);
    void setMedianPrices(double val);
    ~Location(){} // destructor
};

#endif
