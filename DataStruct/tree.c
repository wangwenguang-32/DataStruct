#include<stdint.h>
#include<stdlib.h>
#include<stdbool.h>
#include"tree.h"
#include"queue.h"

BiTree* tree_create()
{
	BiTree* root = (BiTree*)malloc(sizeof(BiTree));
	root->left = NULL;
	root->left = NULL;
	return root;
}

void preorder(BiTree* root)
{
	if (root == NULL)
		return;
	printf("%d ", root->data);
	preorder(root->left);
	preorder(root->right);
}

void inorder(BiTree* root)
{
	if (root == NULL)
		return;
	inorder(root->left);
	printf("%d ", root->data);
	inorder(root->right);
}

void postorder(BiTree* root)
{
	if (root == NULL)
		return;
	postorder(root->left);
	printf("%d ", root->data);
	postorder(root->right);
}


void tree_bfs(BiTree* root)
{
	if (root == NULL)
		return;
	Queue* queue = InitQueue();
	EnQueue(queue, root);
	while (!Empty(queue))
	{
		BiTree* node = (BiTree*)DeQueue(queue);
		printf("%d ", node->data);
		if (node->left != NULL)
			EnQueue(queue, node->left);
		if (node->right != NULL)
			EnQueue(queue, node->right);
	}
}

