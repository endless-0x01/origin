#pragma once
#include "Transport.h"

class CaretPlane : public Transport
{
public:
	RACINGLIB_API CaretPlane();

	void count_time_racing(int distance) override;
};

