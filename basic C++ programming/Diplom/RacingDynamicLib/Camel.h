#pragma once
#include "Transport.h"

class Camel : public Transport
{
private:
	int movement_to_rest = 30;
	int movement_before_rest{};
public:
	 RACINGLIB_API Camel();

	 void count_time_racing(int distance) override;
};

