#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct TreeNode {
	element data;
	struct TreeNode* left, * right;
}TreeNode;

int sum = 0;

TreeNode* makeRootNode(element data, TreeNode* left, TreeNode* right) 
{
	TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
	root->data = data;
	root->left = left;
	root->right = right;
	return root;
}

void preorder_print(TreeNode* root) 
{
	if (root) {
		printf("%d ", root->data);
		preorder_print(root->left);
		preorder_print(root->right);
	}
}

void inorder_sum(TreeNode* root) 
{
	if (root) 
	{
		inorder_sum(root->left);
		sum = sum + root->data;
		inorder_sum(root->right);
	}
}
void postorder_print30(TreeNode* root) 
{
	if (root) 
	{
		postorder_print30(root->left);
		postorder_print30(root->right);
		if (root->data >= 30)
			printf("%d ", root->data);

	}
}

int main() 
{
	TreeNode* n8 = makeRootNode(33, NULL, NULL);
	TreeNode* n9 = makeRootNode(76, NULL, NULL);
	TreeNode* n4 = makeRootNode(8, n8, n9);
	TreeNode* n5 = makeRootNode(14, NULL, NULL);
	TreeNode* n2 = makeRootNode(50, n4, n5);

	TreeNode* n10 = makeRootNode(19, NULL, NULL);
	TreeNode* n11 = makeRootNode(90, NULL, NULL);
	TreeNode* n7 = makeRootNode(42, n10, n11);
	TreeNode* n6 = makeRootNode(28, NULL, NULL);
	TreeNode* n3 = makeRootNode(65, n6, n7);

	TreeNode* n1 = makeRootNode(24, n2, n3);

	printf("������ȸ ���: ");
	preorder_print(n1);

	inorder_sum(n1);
	printf("\n������ȸ ��� ��: %d", sum);

	printf("\n������ȸ 30�̻� ��� ��: ");
	postorder_print30(n1);
	printf("\n\n");
}