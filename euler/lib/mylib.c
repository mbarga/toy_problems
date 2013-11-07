#include "mylib.h"

#define _DEADMEM 0xDEADBEEFDEADBEEF
/*
int main(void) {

	struct ListEl *stack = 0; 

	push( 11, &stack );
	push( 22, &stack );
  push( 33, &stack );

	//readList( stack );
	printf("POPPED %lld\n",pop( &stack ));
	printf("POPPED %lld\n",pop( &stack ));
	printf("POPPED %lld\n",pop( &stack ));

	return 0;
}
*/
struct ListEl *createListEl() {
	struct ListEl *el = 0;

	el = (struct ListEl*) malloc(sizeof(struct ListEl));
	el->next = NULL;
	return el;
}

void push( long long value, struct ListEl **root ) {
	struct ListEl *newEl;

	if ( *root == 0 ) {
		*root = createListEl();
		(*root)->value = value;
	}
	else {
		newEl = createListEl();
		newEl->value = value;
		newEl->next = *root;
		*root = newEl;
	}

	return;
}

void readList( struct ListEl *root ) {
	struct ListEl *runner;

	runner = root;
	while( runner != 0 ) {
		printf("FOUND ELEMENT %lld\n",runner->value);
		runner = runner->next;
	}
}

long long pop( struct ListEl **root ) {
	long long poppedValue;
	struct ListEl* temp = 0;

	poppedValue = (*root)->value;
	temp = *root;
	if ( temp == NULL ) {
		printf("REACHED END OF STACK\n");
		return 0;
	}
	else {
		*root = (*root)->next;
		// free the memory held by the previous head
		temp->value = _DEADMEM;
		temp->next = NULL;
		free( temp );
		return poppedValue;
	}
	
	return 0;
}

struct Node* createNode() {
	struct Node *node = 0;
	
	node = (struct Node*) malloc(sizeof(struct Node));
	node->left = NULL;
	node->right = NULL;
	node->isEmptyTree = 0;
	return node;
}

struct Node* addNode( long long newData, struct Node *root ) {
	struct Node *newNode = 0; 

	if (root->isEmptyTree == 1) {
		root->value = newData;
		root->isEmptyTree = 0;
	} 
	else if (newData < root->value) {
	  if (root->left == NULL) {
			newNode = createNode();
			newNode->value = newData;
			root->left = newNode;
			return newNode;
		}
		else {
			return addNode( newData, root->left );
		}
	} 
	else {
		if (root->right == NULL) {
			newNode = createNode();
			newNode->value = newData;
			root->right = newNode;
			return newNode;
		}
		else {
			return addNode( newData, root->right );
		}
	}

	return 0;
}

void printTree( struct Node *root ) {
	if (root == NULL) {
		return;
	}
 	printTree(root->left);
	printf("FOUND LEAF VALUE: %lld\n",root->value);
	printTree(root->right);
}

void destroyTree( struct Node *root ) {
	if (root == NULL) {
		return;
  }
	destroyTree( root->left );
	destroyTree( root->right );
	root->value = _DEADMEM;
	free(root);
}
