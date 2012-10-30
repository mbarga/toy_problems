#include <mylib.h>

int main(void) {
	int fact1, fact2;
	int prod = 0;
	int max = 0;
	int magnitude = 0;
	int remainder = 0;
	int digit = 0;
	int adjSum = 0;
	int i,j;
	char fail, finished;
	struct ListEl *stack1 = 0;
	struct ListEl *stack2 = 0;

//	fact1 = 999;
//	fact2 = 999;
//	while ((fact1*fact2) > 1) {
	for (fact1 = 999; fact1 > 0; --fact1) {
		for (fact2 = 999; fact2 > 0; --fact2) {
	
			prod = fact1*fact2;

			// single out all the digits and store them separately
			finished = 0;
			adjSum = 0;

			for (magnitude = 1; finished == 0; ++magnitude) {
				remainder = prod % (int) pow( 10, magnitude );
	
				//printf("DETERMINGING DIGIT\n");
				if ( magnitude == 1 ) {
					digit = remainder;
					push( digit, &stack1 );
				}
				else {
					digit = (remainder - adjSum) / pow( 10, (magnitude - 1) );
					push( digit, &stack1 );
				}
				//printf("PUSHED: %d ,",digit);	
				adjSum += digit * pow( 10, (magnitude - 1) );
				//printf("ADJSUM IS : %d\n",adjSum);
				
				if (remainder == prod) {
					finished = 1;
				}
			}
			//printf("\n");
			magnitude--;
			//printf("DETERMINING IF PALINDROME FOR MAGNITUDE %d with PRODUCT %d\n",magnitude,prod);

			/*
			magnitude = 4;
			push( 9, &stack1 );
			push( 0, &stack1 );
			push( 0, &stack1 );
			push( 9, &stack1 );
			prod = 9009;
			*/
			fail = 0;
			for (i = floor(magnitude/2); i > 0; --i) {
				push( pop( &stack1 ), &stack2 );
			}
			if ((magnitude % 2) != 0) {
				pop( &stack1 );
			}
			for (j = floor(magnitude/2); (j > 0) && (fail == 0); --j) {
				if (pop( &stack1 ) != pop( &stack2 )) {
					fail = 1;
				}
			}
		
			if (fail == 0) {
				//printf("FOUND PALINDROME %d",prod);
				if (prod > max) {
					max = prod;
				}
				//return 0;
			}
		}
	}

	printf("MAX PALINDROME IS: %d\n",max);
	//printf("PALINDROME NOT FOUND");
	return 0;
} 
