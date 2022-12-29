#include "Broom.h"

Broom::Broom() : Transport("Метла", 20, Transport::set_type_racing(2)) {}

void Broom::count_time_racing(int distance) {


	double result = static_cast<double>(distance) * ((100.0 - 4) / 100.0);

	Transport::get_time() = result / static_cast<double>(Transport::get_speed());
}