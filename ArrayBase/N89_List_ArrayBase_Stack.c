#include <stdio.h>

#define EMPTY_POS -1

struct ElementType {
	int id;
	char *name;	
};

struct StackInfo {	
	unsigned int capacity;
	int top_of_stack;
	struct ElementType *stack_array;
};

typedef struct StackInfo *Stack;

Stack create_stack(unsigned int capacity) {
	Stack S = malloc(sizeof(struct StackInfo));
	if (S == NULL) {
		printf("Not enough memory!\n");
		return NULL;
	}	
	S->capacity = capacity;
	S->top_of_stack = EMPTY_POS;
	S->stack_array = malloc(sizeof(struct ElementType)*capacity);
	if (S->stack_array == NULL) {
		printf("Not enough memory!\n");
		return NULL;
	}	
	return S;
}

void push(Stack S,struct ElementType e) {
	if (is_full(S)) {
		printf("The stack is full, you cannot push a new item into it anymore!\n");
		return;
	}
	S->stack_array[++S->top_of_stack] = e;
}
int is_empty(Stack S) {
	return S->top_of_stack == EMPTY_POS;
}

int is_full(Stack S) {
	return S->top_of_stack == S->capacity - 1;
}

struct ElementType pop(Stack S) {
	struct ElementType result;
	if (is_empty(S)) {
		printf("The stack is empty!\n");
		result.id = EMPTY_POS;
		return result;
	}
	result = S->stack_array[S->top_of_stack--];
	return result;
}

struct ElementType top(Stack S) {
	struct ElementType result;
	if (is_empty(S)) {
		printf("The stack is empty!\n");
		result.id = EMPTY_POS;
		return result;
	}
	result = S->stack_array[S->top_of_stack];
	return result;
}

void show_stack(Stack S) {
	for (int i=0;i<=S->top_of_stack;i++)
		printf("%d --- %s\n",S->stack_array[i].id,S->stack_array[i].name);
}

int main() {
	Stack S = create_stack(100);
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
