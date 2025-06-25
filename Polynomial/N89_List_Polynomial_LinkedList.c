#include <stdio.h>

struct Node {
	int coef;
	int expo;
	struct Node *next;	
};

typedef struct Node *POLYNOMIAL;
typedef struct Node *Position;

POLYNOMIAL create_poly(){
	POLYNOMIAL header_node = malloc(sizeof(struct Node));
	if (header_node == NULL) {
		printf("Not enough memory!");
		return NULL;
	}
	header_node->next = NULL;
	return header_node;
}

Position create_node(int coef, int expo){
	Position new_node = malloc(sizeof(struct Node));
	if (new_node == NULL) {
		printf("Not enough memory!");
		return NULL;
	}
	new_node->next = NULL;
	new_node->coef = coef;
	new_node->expo = expo;
	
	return new_node;
}

void add_node(POLYNOMIAL poly, int coef, int expo) {
	Position new_node = create_node(coef,expo);
	if (new_node == NULL)
		return;
	while (poly->next!=NULL && poly->next->expo>expo)
		poly = poly->next;
	if (poly->next!= NULL && poly->next->expo == expo)
		poly->next->coef += coef;
	else {
		new_node->next = poly->next;
		poly->next = new_node;
	}
}

void show_poly(POLYNOMIAL poly){
	poly = poly->next;
	while (poly!=NULL) {
		printf("%dx^%d ",poly->coef,poly->expo);
		poly = poly->next;
	}
	printf("\n");
}

void add_poly(POLYNOMIAL A, POLYNOMIAL B, POLYNOMIAL C) {
	A = A->next;
	while (A!=NULL) {
		add_node(C,A->coef,A->expo);
		A = A->next;
	}
		
	B = B->next;
	while (B!=NULL) {
		add_node(C,B->coef,B->expo);
		B = B->next;
	}		
}

int main() {
	POLYNOMIAL A,B,C;
	A = create_poly();
	B = create_poly();
	C = create_poly();
	//4x^3 + 5x - 8
	add_node(A,4,3);
	add_node(A,-8,0);
	add_node(A,5,1);
	show_poly(A);
	//5x^3 + 4x^2 + 3
	add_node(B,5,3);
	add_node(B,4,2);
	add_node(B,3,0);
	show_poly(B);
	add_poly(A,B,C);
	
	show_poly(C);
	return 0;
}