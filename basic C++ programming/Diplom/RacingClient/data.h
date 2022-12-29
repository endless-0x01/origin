#include "ShowTransports.h"
#include <vector>
#include "Transport.h"
#include "all_transports.h"


int get_data();

int get_distance_game();

void start_game();


enum class result_checked
{
	succes = 1,
	repeat,
	wrong_type

};

void sort_ts(std::vector<Transport*>& ts);
void ts_in_stock(std::vector<Transport*>& ts);
result_checked check_ts_for_availability(std::vector<Transport*>& ts, Transport* object, int type_game, std::string& repeat_name);
void vehicle_registration(std::vector<Transport*>& ts, int type_game, int distance);