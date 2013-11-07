#include "stdio.h"

void main() {
	int fibPrev1=2;
	int fibPrev2=1;
	int sumOfEvens=2;
	int fibTemp=0;

	while (fibPrev1 < 4000000) {
		fibTemp  = fibPrev2;
		fibPrev2 = fibPrev1;
		fibPrev1 = fibPrev1 + fibTemp;
		if (fibPrev1%2 == 0) {
			sumOfEvens += fibPrev1;
		}   
	}

	printf("Sum was: %d", sumOfEvens);
	return;
} 
