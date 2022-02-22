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

uint Prime::bin2int(char* s) {
	uint tmp = 0;
	for (int i = 0; s[i] != 0; i++) {
		tmp *= 2;
		if ((s[i] == 1) || (s[i] == '1')) {
			tmp++;
		}
	}
	return tmp;
}

void Prime::vivod() {
	Number a((char*)"100011");
	Number p((char*)"1010");
	DiscrLog d;
	d.Divide(a,p);	
	d.Y.V();
}

void Prime::GetPowerSet() {
	Number tmp0((char*)"100"), tmp1;
	
	uint pr[] = { 3,5,7,11,13,17,19,23,29,31,37 };

	for (uint i = 3; i < 10; i++) {
		tmp1 = tmp0;
		tmp0 << 0;
		printf("Try: %d ", Pow(2, i, pr[2]));
		tmp1.V();
		printf("\n");
		if (Pow(2, i, pr[2]) == ((unsigned int)tmp1)) {
			printf("Found %d\n",pr[2]);
		}
	}
}

uint Pow(uint a, uint x, uint p) {
	if (x == 0) return 1;
	int z = Pow(a, x / 2, p);
	if (x % 2 == 0)
		return (z * z) % p;
	else
		return (a * z * z) % p;
}
