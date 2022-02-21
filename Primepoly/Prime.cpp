#include "Prime.h"
#include <math.h>
char* Prime::int2bin(uint a) {
	uint n=(uint)ceil((log(a) / log(2)));

	if (n<=0)return (char*)"0";

	char* s = new char[n + 1];
	s[n] = 0;
	for (int i = n - 1; i >= 0; i--) {
		s[i] = a % 2+'0';
		a /= 2;
	}
	return s;
}