#pragma once
#include "Transport.h"


class SpeedBoots : public Transport
{
private:
	int movement_to_rest = 60;
	int movement_before_rest{};
public:
	RACINGLIB_API SpeedBoots();

	 void count_time_racing(int distance) override;
};

