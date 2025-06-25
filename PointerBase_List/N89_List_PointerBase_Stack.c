#include <stdio.h>

#define EMPTY_ID -1

struct ElementType {
	int id;
	char *name;	
};

struct ListNode {	
	struct ElementType e;
	struct ListNode *next;
};

typedef struct ListNode *Stack;

Stack create_stack() {
	Stack S = malloc(sizeof(struct ListNode));
	if (S==NULL) {
		printf("Not enough memory!\n");
		return NULL;
	}	
	S->next = NULL;
	return S;
}

void push(Stack S,struct ElementType e) {
	struct ListNode *new_item = malloc(sizeof(struct ListNode));
	if (new_item == NULL) {
		printf("Not enough memory!\n");
		return NULL;
	}
	new_item->e = e;
	new_item->next = S->next;
	S->next = new_item;
}
int is_empty(Stack S) {
	return S->next == NULL;
}

struct ElementType pop(Stack S) {
	struct ElementType result;
	if (is_empty(S)) {
		printf("The stack is empty");
		struct ElementType result;
		result.id = EMPTY_ID;
		return result;
	}
	result = S->next->e;
	struct ListNode *temp = S->next;
	S->next = S->next->next;
	free(temp);
	return result;
}

struct ElementType top(Stack S) {
	struct ElementType result;
	if (is_empty(S)) {
		printf("The stack is empty");
		struct ElementType result;
		result.id = EMPTY_ID;
		return result;
	}
	result = S->next->e;
	return result;
}

void show_stack(Stack S) {
	while (S->next!=NULL) {
		printf("%d  ---  %s\n",S->next->e.id,S->next->e.name);
		S = S->next;
	}
}

int main() {
	Stack S = create_stack();
	struct ElementType std1, std2, std3, result;
	std1.id = 1; std1.name = "Nguyen Van An";
	std2.id = 2; std2.name = "Nguyen Van Binh";
	std3.id = 3; std3.name = "Nguyen Van Cuong";
	push(S, std1);
	push(S, std2);
	push(S, std3);
	
	printf("The stack is:\n");
	show_stack(S);
	
	result = pop(S);
	printf("The top element is %d --- %s\n",result.id,result.name);
	
	printf("The stack is:\n");
	show_stack(S);
}
