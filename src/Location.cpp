#include "SakanX/Location.h"
#include <iomanip>

using namespace std;

 
// Static member functions
double Location::generate_random_coord(double min, double max) {
    static mt19937 generator(time(nullptr));
    uniform_real_distribution<double> distribution(min, max);
    return distribution(generator);
}

double Location::generate_random_longitude() {
    return generate_random_coord(-180.0, 180.0);
}

double Location::generate_random_latitude() {
    return generate_random_coord(-90.0, 90.0);
}

string Location::get_population_type_string() const {
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

// Constructor
Location::Location(string buidling, int floor, int roomNumber,
                 PolulationType pop_type,
                 double sup_m, double ph_m, double msq_m, double trn_m,
                 double hosp_km, double coll_km, double prices)
        : building(std::move(buidling)),
            floor(floor),
            roomNumber(roomNumber),
            population_type(pop_type),
            lm({sup_m, ph_m, msq_m, trn_m, hosp_km, coll_km, prices,
                    generate_random_longitude(), generate_random_latitude()})
{
    if (building.empty() || floor < 0 || roomNumber < 0 || sup_m < 0 || ph_m < 0 || msq_m < 0 || trn_m < 0 || hosp_km < 0 || coll_km < 0 || prices < 0) {
        throw std::invalid_argument("Invalid Location constructor arguments");
    }
}

void Location::displayLocation() const {
    // No output as per requirements
}


// GETTERS
const std::string& Location::getBuilding() const { return building; }
int Location::getFloor() const { return floor; }
int Location::getRoomNumber() const { return roomNumber; }
PolulationType Location::getPopulationType() const { return population_type; }
double Location::getLongitude() const { return lm.longitude; }
double Location::getAltitude() const { return lm.altitude; }
double Location::getNearestSupermarketM() const { return lm.nearest_supermarket_m; }
double Location::getNearestPharmacyM() const { return lm.nearest_pharmacy_m; }
double Location::getNearestMosqueM() const { return lm.nearest_mosque_m; }
double Location::getNearestTransitStopM() const { return lm.nearest_transit_stop_m; }
double Location::getNearestHospitalKM() const { return lm.nearest_hospital_km; }
double Location::getNearestCollegeKM() const { return lm.nearest_college_km; }
double Location::getMedianPrices() const { return lm.median_prices; }
    
// SETTERS
void Location::setBuilding(const std::string& newBuilding) { 
    if (newBuilding.empty()) throw std::invalid_argument("Building name cannot be empty");
    building = newBuilding; 
}
void Location::setFloor(int newFloor) { 
    if (newFloor < 0) throw std::invalid_argument("Floor must be non-negative");
    floor = newFloor; 
}
void Location::setRoomNumber(int newRoomNumber) { 
    if (newRoomNumber < 0) throw std::invalid_argument("Room number must be non-negative");
    roomNumber = newRoomNumber; 
}
void Location::setPopulationType(PolulationType newPopType) { population_type = newPopType; }
void Location::setLongitude(double val) { lm.longitude = val; }
void Location::setAltitude(double val) { lm.altitude = val; }
void Location::setNearestSupermarketM(double val) { 
    if (val < 0) throw std::invalid_argument("Supermarket distance must be non-negative");
    lm.nearest_supermarket_m = val; 
}
void Location::setNearestPharmacyM(double val) { 
    if (val < 0) throw std::invalid_argument("Pharmacy distance must be non-negative");
    lm.nearest_pharmacy_m = val; 
}
void Location::setNearestMosqueM(double val) { 
    if (val < 0) throw std::invalid_argument("Mosque distance must be non-negative");
    lm.nearest_mosque_m = val; 
}
void Location::setNearestTransitStopM(double val) { 
    if (val < 0) throw std::invalid_argument("Transit stop distance must be non-negative");
    lm.nearest_transit_stop_m = val; 
}
void Location::setNearestHospitalKM(double val) { 
    if (val < 0) throw std::invalid_argument("Hospital distance must be non-negative");
    lm.nearest_hospital_km = val; 
}
void Location::setNearestCollegeKM(double val) { 
    if (val < 0) throw std::invalid_argument("College distance must be non-negative");
    lm.nearest_college_km = val; 
}
void Location::setMedianPrices(double val) { 
    if (val < 0) throw std::invalid_argument("Median prices must be non-negative");
    lm.median_prices = val; 
}