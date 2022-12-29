#pragma once
#include "Transport.h"

class CamelSpeed : public Transport
{
private:
	int movement_to_rest = 10;
	int movement_before_rest{};
public:
	RACINGLIB_API CamelSpeed();

	void count_time_racing(int distance) override;
};

