#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200
typedef struct TreeNode {
	int weight;
	struct TreeNode* left;
	struct TreeNode* right;
} TreeNode;
typedef struct {
	TreeNode* ptree;
	int key;
} element;
// 이진 트리 생성 함수
TreeNode* make_tree(TreeNode* left, TreeNode* right) {
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->left = left;
	node->right = right;
	return node;
}
int is_leaf(TreeNode* root) {
	return !(root->left) && !(root->right);
}

void print_array(int codes[], int n) {
	for (int i = 0; i < n; i++)
		printf("%d", codes[i]);
	printf("\n");
}
void preorder_traversal(TreeNode* root)
{
	if (root)
	{
		printf("%c", char(root->weight + 'A'));
		preorder_traversal(root->left);
		preorder_traversal(root->right);
	}
}
void inorder_traversal(TreeNode* root)
{
	if (root)
	{
		inorder_traversal(root->left);
		printf("%c", char(root->weight + 'A'));
		inorder_traversal(root->right);
	}
}
void postorder_traversal(TreeNode* root)
{
	if (root)
	{
		postorder_traversal(root->left);
		postorder_traversal(root->right);
		printf("%c", char(root->weight + 'A'));
	}
}
int main(void) {
	int i, N;
	char left, parent, right;
	int l, p, r;
	TreeNode* node, * x;
	element e[26];
	int codes[100];
	int top = 0;
	scanf("%d", &N);
	for (i = 0; i < N; i++) 
	{
		node = make_tree(NULL, NULL);
		e[i].key = node->weight = i;
		e[i].ptree = node;
	}
	for (i = 0; i < N; i++) 
	{
		scanf(" %c %c %c", &parent, &left, &right);
		x = e[int(parent) - 'A'].ptree;
		if (left != '.' && right != '.')
		{
			x->left = e[int(left) - 'A'].ptree;
			x->right = e[int(right) - 'A'].ptree;
		}
		else if (left == '.' && right != '.')
		{
			x->left = NULL;
			x->right = e[int(right) - 'A'].ptree;
		}
		else if (left != '.' && right == '.')
		{
			x->right = NULL;
			x->left = e[int(left) - 'A'].ptree;
		}
		else
		{
			x->left = NULL;
			x->right = NULL;
		}
	}
	preorder_traversal(e[0].ptree);
	printf("\n");
	inorder_traversal(e[0].ptree);
	printf("\n");
	postorder_traversal(e[0].ptree);
}