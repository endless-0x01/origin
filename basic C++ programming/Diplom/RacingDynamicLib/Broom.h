#pragma once
#include "Transport.h"

class Broom : public Transport
{
public:
	RACINGLIB_API Broom();

	void count_time_racing(int distance) override;
};

