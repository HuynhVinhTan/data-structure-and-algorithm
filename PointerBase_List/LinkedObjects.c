#include <stdio.h>
#include <stdlib.h>

struct Symbol {
	char *name;
	unsigned long value;
};

struct Node {
	struct Node *next;
	struct Symbol *element;
};

struct Node *nodeA;
struct Node *nodeB;
struct Node *nodeC;

int main() {
	nodeA = (struct Node*)malloc(sizeof(struct Node));
	nodeB = malloc(sizeof(struct Node));
	nodeC = malloc(sizeof(struct Node));
	
	struct Symbol oneSym; oneSym.name = "One"; oneSym.value = 1;
	struct Symbol twoSym; twoSym.name = "Two"; twoSym.value = 2;
	struct Symbol threeSym; threeSym.name = "Three"; threeSym.value = 3;
	
	nodeA->next = nodeB;
	nodeA->element = &oneSym;
	
	nodeB->next = nodeC;
	nodeB->element = &twoSym;
	
	nodeC->next = NULL;
	nodeC->element = &threeSym;
	
	struct Node *nodeP;
	nodeP = nodeA;
	while (nodeP!=NULL) {
		printf("Name: %s, Value: %ld\n",nodeP->element->name,nodeP->element->value);
		nodeP = nodeP->next;
	}
	
	return 0;
}