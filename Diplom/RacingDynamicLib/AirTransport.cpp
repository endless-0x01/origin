#include "AirTransport.h"

AirTransport::AirTransport(std::string name, int speed) : 
	Transport(name, speed, Transport::set_type_racing(2)) {}

void AirTransport::count_time_racing(int distance) {

}