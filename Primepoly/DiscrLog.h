#pragma once
#include "Number.h"
class DiscrLog {
public:	
	Number Y;	
public:	
	void Divide(Number AX, Number P) {
		Number tmp((char*)"1");
		int i = 1;
		while (tmp.GetSize() < P.GetSize()) {
			tmp << AX[i++];
		}
		while (i < AX.GetSize()) {

			if (tmp.GetSize() < P.GetSize()) {
				tmp << AX[i++];
			}
			else {
				tmp = (tmp + P);
				-tmp;
			}
		}
		if (P < tmp) {
			tmp = (tmp + P);
			-tmp;
		}	
		Y = tmp;
	}
};
