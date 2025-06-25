#include <stdio.h>

struct ElementType {
	int id;
	char* name;
};

struct Node {
	struct ElementType e;
	struct Node *next;
	struct Node *prev;
};

typedef struct Node *List;
typedef struct Node *Position;

void insert(struct ElementType e, Position p) {
	Position newItem = malloc(sizeof(struct Node));
	newItem->e = e;
	if (newItem == NULL) {
		printf("Not enough memory!\n");
		return;
	}
	newItem->next = p->next;
	newItem->prev = p;
	if (p->next!=NULL)
		p->next->prev = newItem;
	p->next = newItem;
}

void delete(List pL, Position p) {
	if (p!=NULL) {
		if (p->next!=NULL)
			p->next->prev = p->prev;
		p->prev->next = p->next;
		free(p);
	}
}

List createList() {
	List headerNode = malloc(sizeof(struct Node));
	if (headerNode == NULL) {
		printf("Not enough memory!\n");
		return NULL;
	}
	headerNode->next = NULL;
	headerNode->prev = NULL;
	return headerNode;
}

void display(List pL) {
	pL = pL->next;
	while (pL!=NULL) {
		printf("id: %d      name:%s \n",pL->e.id,pL->e.name);
		pL = pL->next;
	}
}

Position find(List pL, int id) {
	pL = pL->next;
	while (pL!=NULL && pL->e.id!=id)
		pL = pL->next;
	return pL;
}

int main() {
	List stdList = createList();
	struct ElementType e1,e2,e3,e4;
	e1.id = 1; e1.name = "Nguyen Van A";
	e2.id = 2; e2.name = "Nguyen Van B";
	e3.id = 3; e3.name = "Nguyen Van C";
	e4.id = 4; e4.name = "Nguyen Van D";
	insert(e1,stdList);
	insert(e2,stdList);
	insert(e3,stdList);
	insert(e4,stdList);
	printf("The list is:\n");
	display(stdList);
	Position item = find(stdList,2);
	delete(stdList,item);
	printf("The list is:\n");
	display(stdList);
	free(stdList);
	return 0;
}
