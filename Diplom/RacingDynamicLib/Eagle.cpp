#include "Eagle.h"

Eagle::Eagle() : Transport("Îð¸ë", 8, Transport::set_type_racing(2)) {}

void Eagle::count_time_racing(int distance) {

	double result = static_cast<double>(distance) * ((100.0 - 6.0) / 100.0);

	Transport::get_time() = result / static_cast<double>(Transport::get_speed());
}