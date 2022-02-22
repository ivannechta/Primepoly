#pragma once
#include "Number.h"
#include "DiscrLog.h"

typedef unsigned int uint;
uint Pow(uint a, uint x, uint p);

class Prime {
public:
	char *int2bin(uint a);
	uint bin2int(char* s);
	void vivod();
	void GetPowerSet();	
};
