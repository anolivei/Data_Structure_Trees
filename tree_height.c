/*
** Hacker Rank Code
** Tree: Height of a Binary Tree
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node
{
	
	int			data;
	struct node	*left;
	struct node	*right;
};

struct node*	insert(struct node* root, int data)
{
	if(root == NULL)
	{
		struct node* node = (struct node*)malloc(sizeof(struct node));
		node->data = data;
		node->left = NULL;
		node->right = NULL;
		return node;
	}
	else
	{
		struct node* cur;
		if(data <= root->data)
		{
			cur = insert(root->left, data);
			root->left = cur;
		}
		else
		{
			cur = insert(root->right, data);
			root->right = cur;
		}
		return (root);
	}
}

/*
** My code
** Your function should return a single integer
** denoting the height of the binary tree
*/

int	maxDepth(struct node* root)
{
	int	r;
	int	l;

	if (!root)
		return(0);
	else
	{
		r = maxDepth(root->right);
		l = maxDepth(root->left);
	}
	return (r > l ? r + 1: l + 1);
}

int	getHeight(struct node* root)
{
	return (maxDepth(root) - 1);
}