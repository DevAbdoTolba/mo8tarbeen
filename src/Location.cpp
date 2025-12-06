#include <iostream>
#include <string>
#include <utility>
#include <random>
#include <ctime>
#include <iomanip>

using namespace std;

enum class PolulationType{
    Unknown,
    Families_With_Children,
    Young_Professionals,
    Retirees,
    Students,
    Mixed
};

struct LocationMetrices{
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

class Location{
private:
    string building;
    int floor;
    int roomNumber;
    PolulationType population_type;
    LocationMetrices lm;

    /// generate random default values for longitude and altitude
    static double generate_random_coord(double min, double max) {
        static mt19937 generator(time(nullptr));
        uniform_real_distribution<double> distribution(min, max);
        return distribution(generator);
    }

    static double generate_random_longitude() {
        return generate_random_coord(-180.0, 180.0);
    }

    static double generate_random_latitude() {
        return generate_random_coord(-90.0, 90.0);
    }
    /// determines the values of the population_type ENUMS
    string get_population_type_string() const {
        switch (population_type) {
            case PolulationType::Families_With_Children: return "Families_With_Children";
            case PolulationType::Young_Professionals: return "Young_Professionals";
            case PolulationType::Retirees: return "Retirees";
            case PolulationType::Students: return "Students";
            case PolulationType::Mixed: return "Mixed";
            case PolulationType::Unknown:
            default: return "Unknown";
        }
    }
public:
    //// constructor with default values for the longtiude and alitude
    Location(string buidling , int floor , int roomNumber,
             PolulationType pop_type,
             double sup_m, double ph_m, double msq_m, double trn_m,
             double hosp_km, double coll_km, double prices)
        : building(std::move(buidling)),
          floor(floor),
          roomNumber(roomNumber),
          population_type(pop_type),
          // Initialize lm, calling random functions for coordinates
          lm({sup_m, ph_m, msq_m, trn_m, hosp_km, coll_km, prices,
              generate_random_longitude(), generate_random_latitude()})
    {}

    void diplayLocation(){
        cout << fixed << setprecision(2);
        cout<< building
            << " , Floor : "<<floor
            <<" , RoomNumber : "<<roomNumber
            <<endl;
        cout << "  Population Type: " << get_population_type_string() << endl;
        cout << "  Longitude: " << lm.longitude << ", Altitude: " << lm.altitude << endl;
        cout << "  Median Prices: $" << lm.median_prices << endl;
    }


    // GETTERS //
    const string& getBuilding() const { return building; }
    int getFloor() const { return floor; }
    int getRoomNumber() const { return roomNumber; }
    PolulationType getPopulationType() const { return population_type; }

        double getLongitude() const { return lm.longitude; }
        double getAltitude() const { return lm.altitude; }
        double getNearestSupermarketM() const { return lm.nearest_supermarket_m; }
        double getNearestPharmacyM() const { return lm.nearest_pharmacy_m; }
        double getNearestMosqueM() const { return lm.nearest_mosque_m; }
        double getNearestTransitStopM() const { return lm.nearest_transit_stop_m; }
        double getNearestHospitalKM() const { return lm.nearest_hospital_km; }
        double getNearestCollegeKM() const { return lm.nearest_college_km; }
        double getMedianPrices() const { return lm.median_prices; }

    // SETTERS //
    void setBuilding(string newBuilding) { building = std::move(newBuilding); }
    void setFloor(int newFloor) { floor = newFloor; }
    void setRoomNumber(int newRoomNumber) { roomNumber = newRoomNumber; }
    void setPopulationType(PolulationType newPopType) { population_type = newPopType; }

        void setLongitude(double val) { lm.longitude = val; }
        void setAltitude(double val) { lm.altitude = val; }
        void setNearestSupermarketM(double val) { lm.nearest_supermarket_m = val; }
        void setNearestPharmacyM(double val) { lm.nearest_pharmacy_m = val; }
        void setNearestMosqueM(double val) { lm.nearest_mosque_m = val; }
        void setNearestTransitStopM(double val) { lm.nearest_transit_stop_m = val; }
        void setNearestHospitalKM(double val) { lm.nearest_hospital_km = val; }
        void setNearestCollegeKM(double val) { lm.nearest_college_km = val; }
        void setMedianPrices(double val) { lm.median_prices = val; }


    ~Location(){}
};
