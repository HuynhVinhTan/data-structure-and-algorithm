#include <stdio.h>

struct TreeNode {
	int key;
	struct TreeNode *left, *right, *parent;
};

typedef struct TreeNode *BST;

BST create_bst(int root_key) {
	BST T = malloc(sizeof(struct TreeNode));
	if (T == NULL) {
		printf("Not enough memory!\n");
		return NULL;
	}
	T->key = root_key;
	T->left = NULL;
	T->right = NULL;
	T->parent = NULL;
}

void preorder(BST T) {
	if (T!=NULL) {
		printf("%d, ",T->key);
		preorder(T->left);
		preorder(T->right);
	}
}

void inorder(BST T) {
	if (T!=NULL) {		
		inorder(T->left);
		printf("%d, ",T->key);
		inorder(T->right);
	}
}

void postorder(BST T) {
	if (T!=NULL) {
		inorder(T->left);		
		inorder(T->right);
		printf("%d, ",T->key);
	}
}


int main() {
	BST T = create_bst(10);
	struct TreeNode n5, n30,n2,n25,n45;
	T->left = &n5; T->right = &n30;
	n5.key = 5; n5.left = &n2; n5.right = NULL;
	n2.key = 2; n2.left = NULL; n2.right = NULL;
	n30.key = 30;n30.left = NULL;n30.right = NULL;
	preorder(T);
}