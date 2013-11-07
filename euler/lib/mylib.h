/** @file mylib.h
	* @brief My custom library of common functions 
	*/
#ifndef _MYLIB_H
#define _MYLIB_H

#include "stddef.h"
#include "assert.h"
#include "stdlib.h"
#include "stdio.h"

// data
struct Node {
	struct Node *left;
	long long value;
	int isEmptyTree;
	struct Node *right;
};

struct ListEl {
	struct ListEl *next;
	long long value;
};

// function prototypes

/** @brief Create an element to place in a stack
	*
	* @return A pointer to the stack element
	*/
struct ListEl* createListEl();

/** @brief Add an element to a list (stack)
	*
	* @param value The number to add to the stack
	* @param list The root of the list to add to
	* @return A pointer to the added list element (the new root)
	*/
void push( long long value, struct ListEl** root );

void readList( struct ListEl* );

long long pop( struct ListEl **root );

/** @brief Allocate memory to create a node element
  * 
	* @return A pointer to the node element created
  */
struct Node* createNode();

/** @brief Add node to tree
	*
	* @param value The value to add as a node 
	* @param root The root of the tree to add node to
	* @return A pointer to the node
	*/
struct Node* addNode( long long value, struct Node* root );

/** @brief Print out all the nodes in the tree
	*
	* @return void
	*/
void printTree();

/** @brief Destroy the tree and free its memory
	*
  * @param root Root of the tree to destroy
	* @return void
	*/
void destroyTree( struct Node* root );

#endif
