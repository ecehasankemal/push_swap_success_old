#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int			key;
	struct node	*left;
	struct node	*right;
}				t_node;

t_node	*newNode(int item)
{
	t_node	*temp;

	temp = (t_node *)malloc(sizeof(t_node));
	temp->key = item;
	temp->right = NULL;
	temp->left = temp->right;
	return (temp);
}

void	storeSorted(t_node *root, int *arr, int *index)
{
	if (root != NULL)
	{
		storeSorted(root->left, arr, index);
		arr[(*index)++] = root->key;
		storeSorted(root->right, arr, index);
	}
}

t_node	*insert(t_node *node, int key)
{
	if (node == NULL)
		return (newNode(key));
	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);
	return (node);
}

void	treeSort(int *arr, int n)
{
	t_node	*root;
	int		index;

	index = 0;
	root = NULL;
	root = insert(root, arr[0]);
	while (index < n)
	{
		root = insert(root, arr[index]);
		index++;
	}
	index = 0;
	storeSorted(root, arr, &index);
}

int	main(void)
{
	int	arr[] = {5, 4, 7, 2, 11};
	int	n;
	int	index;

	index = 0;
	n = (sizeof(arr) / sizeof(arr[0]));
	treeSort(arr, n);
	while (index < n)
	{
		printf("%d ", arr[index]);
		index++;
	}
	return (0);
}
