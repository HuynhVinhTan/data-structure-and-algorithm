#include <stdio.h>
#include <string.h>

#define EMPTY_POS -1

struct ElementType {
	char symbol;	
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

void push(Stack S,char e) {
	if (is_full(S)) {
		printf("The stack is full, you cannot push a new item into it anymore!\n");
		return;
	}
	S->stack_array[++S->top_of_stack].symbol = e;
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
//		result.id = EMPTY_POS;
		return result;
	}
	result = S->stack_array[S->top_of_stack--];
	return result;
}

struct ElementType top(Stack S) {
	struct ElementType result;
	if (is_empty(S)) {
		printf("The stack is empty!\n");
//		result.id = EMPTY_POS;
		return result;
	}
	result = S->stack_array[S->top_of_stack];
	return result;
}

//void show_stack(Stack S) {
//	for (int i=0;i<=S->top_of_stack;i++)
//		printf("%d --- %s\n",S->stack_array[i].id,S->stack_array[i].name);
//}

int check_balance(Stack S, char *stat) {
	for (int i=0;i<strlen(stat);i++){
		if(stat[i]=='(' || stat[i]=='[') {
			push(S, stat[i]);
		} else if(stat[i]==')' || stat[i]==']') {
			if(is_empty(S)) {
				return 0;
			} else if(top(S).symbol=='(' && stat[i]==')'){
				pop(S);
			} else if(top(S).symbol=='[' && stat[i]==']') {
				pop(S);
			} else {
				return 0;
			}
		}
	}
	if(!is_empty(S)) {
		return 0;
	}
	return 1;
}

int main() {
	Stack S = create_stack(100);
	struct ElementType std1, std2, std3, result;
	char *stat = "[i + 5*[(17 – j/(6*k))]]";
	int isBalance = check_balance(S,stat);
	if (isBalance)
		printf("The statement is balanced");
	else
		printf("The statement is unbalanced");
	return 0;
}
