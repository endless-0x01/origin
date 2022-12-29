#pragma once
#include "Transport.h"

class AirTransport : public Transport
{
public:
	AirTransport(std::string name, int speed);

	void count_time_racing(int distance) override;

};

