#include "CaretPlane.h"

CaretPlane::CaretPlane() : Transport("Ковёр-самолёт", 10, Transport::set_type_racing(2)) {}

void CaretPlane::count_time_racing(int distance) {
	
	int time_obj{};
	double result{};
	if (distance < 1000) {
		result = static_cast<double>(distance);
	}
	else if (distance < 5000) {
		result = static_cast<double>(distance) * ((100.0 - 3.0) / 100.0);
	}
	else if (distance < 10000) {
		result = static_cast<double>(distance) * ((100.0 - 10.0) / 100.0);
	}
	else if (distance >= 10000) {
		result = static_cast<double>(distance) * ((100.0 - 5.0) / 100.0);
	}

	Transport::get_time() = result / static_cast<double>(Transport::get_speed());
}