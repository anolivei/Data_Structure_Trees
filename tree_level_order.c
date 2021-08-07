/*
** Hacker Rank Code
** Tree: Level Order Traversal
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
** Print the values in a single line separated by a space
*/

int	height(struct node* root)
{
	int	l;
	int	r;

	if (!root)
		return (0);
	else
	{
		l = height(root->left);
		r = height(root->right);
	}
	return (l > r ? l + 1 : r + 1);
}

void	printLevel(struct node* root, int level)
{
	if (!root)
		return;
	if (level == 1)
		printf("%d ", root->data);
	else
	{
		printLevel(root->left, level - 1);
		printLevel(root->right, level - 1);
	}
}

void	levelOrder(struct node *root)
{
	int	h;
	int	i;

	h = height(root);
	i = 1;
	printf("%d ", root->data);
	while (i <= h)
	{
		printLevel(root->left, i);
		printLevel(root->right, i);
		i++;
	}
}
