#ifndef LOCATION_H
#define LOCATION_H

#include <string>
#include <utility>
#include <random>
#include <ctime>
#include <iostream>


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
    void diplayLocation();

    // GETTERS ////
    // for the variables declared inside of the class
    const std::string& getBuilding() const { return building; }
    int getFloor() const { return floor; }
    int getRoomNumber() const { return roomNumber; }
    PolulationType getPopulationType() const { return population_type; }
        // the struct getters
        double getLongitude() const { return lm.longitude; }
        double getAltitude() const { return lm.altitude; }
        double getNearestSupermarketM() const { return lm.nearest_supermarket_m; }
        double getNearestPharmacyM() const { return lm.nearest_pharmacy_m; }
        double getNearestMosqueM() const { return lm.nearest_mosque_m; }
        double getNearestTransitStopM() const { return lm.nearest_transit_stop_m; }
        double getNearestHospitalKM() const { return lm.nearest_hospital_km; }
        double getNearestCollegeKM() const { return lm.nearest_college_km; }
        double getMedianPrices() const { return lm.median_prices; }

    // SETTERS ///
    // for the variables ceclared inside of the class
    void setBuilding(std::string newBuilding) { building = std::move(newBuilding); }
    void setFloor(int newFloor) { floor = newFloor; }
    void setRoomNumber(int newRoomNumber) { roomNumber = newRoomNumber; }
    void setPopulationType(PolulationType newPopType) { population_type = newPopType; }
        // the struct setters and in case of admin set values for the longitude and latitude
        // then the defaulut values will be updated
        void setLongitude(double val) { lm.longitude = val; }
        void setAltitude(double val) { lm.altitude = val; }
        void setNearestSupermarketM(double val) { lm.nearest_supermarket_m = val; }
        void setNearestPharmacyM(double val) { lm.nearest_pharmacy_m = val; }
        void setNearestMosqueM(double val) { lm.nearest_mosque_m = val; }
        void setNearestTransitStopM(double val) { lm.nearest_transit_stop_m = val; }
        void setNearestHospitalKM(double val) { lm.nearest_hospital_km = val; }
        void setNearestCollegeKM(double val) { lm.nearest_college_km = val; }
        void setMedianPrices(double val) { lm.median_prices = val; }
    ~Location(){} // destructor
};

#endif
