#pragma once
#include "Transport.h"

class Eagle : public Transport
{
public:
	RACINGLIB_API Eagle();
	
	void count_time_racing(int distance) override;
};

