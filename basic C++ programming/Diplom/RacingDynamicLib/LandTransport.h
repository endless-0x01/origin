#pragma once
#include "Transport.h"

class LandTransport : public Transport
{
protected:
	RACINGLIB_API LandTransport(std::string name_ts, int speed, int type);

	 void count_time_racing(int distance) override;
};

