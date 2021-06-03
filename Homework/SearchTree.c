#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int element;
typedef struct TreeNode {
	element key;
	struct TreeNode* left, * right;
}TreeNode;

#define MAX_TREE_NODE_NUM 30
element list[MAX_TREE_NODE_NUM];
int size = 0;

TreeNode* new_node(element item) {
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

TreeNode* insert_node(TreeNode* root, element key) {
	if (root == NULL) return new_node(key);

	if (key < root->key)
		root->left = insert_node(root->left, key);
	else if (key > root->key)
		root->right = insert_node(root->right, key);
	else
		printf("\n Ʈ���� ���� Ű�� �ֽ��ϴ�!");

	return root;
}

TreeNode* searchIter(TreeNode* root, element x)
{
	TreeNode* p;
	p = root;
	while (p != NULL) 
	{
		if (x < root->key)
			p = p->left;
		else if (x > root->key)
			p = p->right;
		else
			return p;
	}
	return NULL;
}

void inorder_sort(TreeNode*root)
{
	if (root)
	{
		inorder_sort(root->left);
		list[size++] = root->key;
		inorder_sort(root->right);
	}
}

int main()
{
	TreeNode* root = NULL;
	TreeNode* founded = NULL;
	int i, r;

	srand((unsigned int)time(NULL));

	root = insert_node(root, rand() % 1000);

	for (i = 1; i < MAX_TREE_NODE_NUM; i++) 
	{
		do {
			r = rand() % 1000;
			founded = searchIter(root, r);
			if (founded = NULL)
			{
				root = insert_node(root, r);
				break;
			}
		} while (1);
	}
	printf("\nroot ���: %d\n", root->key);
	
	inorder_sort(root);
	printf("\n���� ���: \n");
	for (i = 0; i < MAX_TREE_NODE_NUM; i++)
	{
		printf("%5d ", list[i]);
		if (i % 5 == 4)
			printf("\n");
	}
}