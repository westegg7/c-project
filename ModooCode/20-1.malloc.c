#include <stdio.h>
#include <stdlib.h>
struct Node {
	int data;
	struct Node* nextNode;
}

struct Node* CreateNode(int data) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

	newNode->data = data;
	newNode->nextNode = NULL;

	return newNode;
}
