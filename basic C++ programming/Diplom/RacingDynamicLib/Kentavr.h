#pragma once
#include "Transport.h"

class Kentavr : public Transport
{
private:
	int movement_to_rest = 8;
	int movement_before_rest{};
public:
	RACINGLIB_API Kentavr();

	void count_time_racing(int distance) override;
};

