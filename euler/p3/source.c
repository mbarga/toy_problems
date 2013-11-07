#include <mylib.h>
#include <math.h>

void factorize( struct Node* );

int main(int argc, char *argv[]) {
	long long factorTarget = 600851475143;
	struct Node *tree = 0;

	tree = createNode();	
	tree->value = factorTarget;

	factorize( tree );

	printTree( tree );
	destroyTree( tree );
	printf("FINISHED");
	return 0;
}

void factorize( struct Node *factorTree ) {
	long long current = factorTree->value;
	long long factorOne = 0;
	long long factorTwo = 0;
	long long divisor = 0;
	struct Node* factorNode1 = 0;
	struct Node* factorNode2 = 0;

	if (current == 2) {
		return;
	}
	
	// if current is even, divide it by 2 
	if ( (current % 2) == 0 ) {
			factorOne = 2;
			factorTwo = current / 2;
	}
	// else check all odd numbers from 2 -> sqrt(current)
	else {
		divisor = floor( sqrt(current) );
		
		// if divisor is even, subtract 1 to make it odd
		if ( (divisor % 2) == 0 ) --divisor;

		while ( (divisor > 2) && 
						(factorOne*factorTwo == 0) ) 
		{
			if ( (current % divisor) == 0 ) {
				factorOne = divisor;
				factorTwo = current / divisor;
			}
			divisor -= 2;
		}	
		
		// if no factors are found, the number is prime so return
		if ( factorOne*factorTwo == 0 ) {
			return;
		}
	}

	factorNode1 = addNode( factorOne, factorTree );
	factorNode2 = addNode( factorTwo, factorTree );

	if ( factorNode1 != NULL ) {
		factorize( factorNode1 );
	}
	if ( factorNode2 != NULL ) {
		factorize( factorNode2 );
	}

	return; 
} 
