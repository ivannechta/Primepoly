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
	
	uint pr[] = { 7, 31,127 };
		/*3	,5	,7	,11	,13	,17	,19	,23	,29,31	,37,
		41	,43,47,53	,59	,61	,67	,71	,73,79	,83	,89	 ,
		97	,101,103,107,109,	113,127,131,137,139	,149	,151 ,
		157,163,167,173,179,	181,191,193,197,199	,211	,223 ,
		227,229,233,239,241,	251,257,263,269,271	,277	,281 ,
		283,293,307,311,313,	317,331,337,347,349	,353	,359 ,
		367,373,379,383,389,	397,401,409,419,421	,431	,433 ,
		439,443,449,457,461,	463,467,479,487,491	,499	,503 ,
		509,521,523,541,547,	557,563,569,571,577	,587	,593 ,
		599,601,607,613,617,	619,631,641,643,647	,653	,659 ,
		661,673,677,683,691,	701,709,719,727,733	,739	,743 ,
		751,757,761,769,773,	787,797,809,811,821	,823	,827 ,
		829,839,853,857,859,	863,877,881,883,887	,907	,911 ,
		919,929,937,941,947,	953,967,971,977,983	,991	,997 };
		*/

	DiscrLog d;
	int N;
	
	for (int prime = 0; prime < sizeof(pr) / sizeof(uint); prime++) {
		N = 0;
		tmp1 = tmp0;
		for (uint i = 3; i < 10; i++) {
			
			tmp1 << 0;

			//printf("Try: i=%d Pow=%d ", i, Pow(2, i, pr[prime]));
			//tmp1.V();
			//printf("\n");
			d.Divide(tmp1, Number(int2bin(pr[prime])));
			//d.Y.V();

			if (Pow(2, i, pr[prime]) == (unsigned int)(d.Y)) {
				//printf("Found %d\n", pr[prime]);
				N++;
			}
			//printf("----------------\n");			
		}
		printf("Prime - %d, count - %d\n", pr[prime], N);
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
