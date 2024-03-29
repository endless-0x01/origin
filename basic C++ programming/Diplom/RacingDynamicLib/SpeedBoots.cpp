﻿#include "SpeedBoots.h"

SpeedBoots::SpeedBoots() : Transport("Ботинки-быстроходы", 6, Transport::set_type_racing(1)) {
	movement_before_rest = Transport::get_speed() * movement_to_rest;
}

void SpeedBoots::count_time_racing(int distance)
{
	int count_stop = distance / movement_before_rest;
	int time_camel{};
	int distance_camel_moved{};
	for (int i = 0; i < count_stop; i++) {

		distance_camel_moved += movement_before_rest;
		if (distance_camel_moved == distance) {
			break;
		}
		if (i == 0)
			time_camel += 10;
		else
			time_camel += 5;;

	}
	Transport::get_time() = time_camel + (static_cast<double>(distance) / Transport::get_speed());
}