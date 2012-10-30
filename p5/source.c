#include <mylib.h>

int main(void) {
	int i;
	long long check;
	int primeMultiple;
	char found = 0;

	primeMultiple = 19 * 17 * 13 * 11 * 2;
	
	for (i = 1; (found==0); ++i) {
		check = i * primeMultiple;
		if (((check % 20) == 0) &&
				((check % 18) == 0) &&
				((check % 16) == 0) &&
				((check % 15) == 0) &&
				((check % 14) == 0) &&
				((check % 12) == 0) 
			 )
			{
				found = 1;
			}
		printf("%d ITERATIONS\n",i);
	}

	printf("NUMBER IS: %lld",check);
	return 0;
} 
