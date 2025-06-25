#include <stdio.h>

struct ElementType {
	int id;
	char* name;
};

struct Node {
	struct ElementType e;
	struct Node *next;
};

typedef struct Node *List;
typedef struct Node *Position;

void insert(List *pL, struct ElementType e, Position p) {
	Position newItem = malloc(sizeof(struct Node));
	newItem->e = e;
	if (newItem == NULL) {
		printf("Not enough memory!\n");
		return;
	}
	if (pL == NULL || p == NULL) {
		newItem->next = *pL;
		*pL = newItem;
	} else {
		newItem->next = p->next;
		p->next = newItem;
	}
}

void delete(List *pL, Position p) {
	if (p == *pL) {
		if (p == NULL)
			return;
		*pL = p->next;
		free(p);
	} else {
		Position prevP = *pL;
		while (prevP != NULL && prevP->next != p)
			prevP = prevP->next;
		if (prevP!=NULL) {
			prevP->next = p->next;
			free(p);
		}
	}
}

void display(List pL) {
	while (pL!=NULL) {
		printf("id: %d      name:%s \n",pL->e.id,pL->e.name);
		pL = pL->next;
	}
}

Position find(List pL, int id) {
	while (pL!=NULL && pL->e.id!=id)
		pL = pL->next;
	return pL;
}

int main() {
	List stdList = NULL;
	struct ElementType e1,e2,e3,e4;
	e1.id = 1; e1.name = "Nguyen Van A";
	e2.id = 2; e2.name = "Nguyen Van B";
	e3.id = 3; e3.name = "Nguyen Van C";
	e4.id = 4; e4.name = "Nguyen Van D";
	insert(&stdList,e1,NULL);
	insert(&stdList,e2,NULL);
	insert(&stdList,e3,NULL);
	insert(&stdList,e4,NULL);
	printf("The list is:\n");
	display(stdList);
	Position item = find(stdList,4);
	delete(&stdList,item);
	printf("The list is:\n");
	display(stdList);
	free(stdList);
	return 0;
}
