#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct node {
	char		*key;
	void		*data;
	struct node	*left;
	struct node	*right;
} 	node_t;


node_t *allocnode()
{
	node_t *node = (node_t *)malloc(sizeof(node_t));
	node->data = NULL;
	node->key = NULL;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

node_t *insert(node_t *root, char *key, void *data)
{
	if (root == NULL)
	{
		node_t *new_node = (node_t *)malloc(sizeof(node_t));
		new_node->key = key;
		new_node->data = data;
		new_node->left = NULL;
		new_node->right = NULL;
		return new_node;
	}
	else{
		if(data <= root->data)
		{
			root->left = insert(root->left,key,data);
		}
		else{
			root->right = insert(root->right,key,data);
		}
		return root;
	}
}

void print_node (node_t *node)
{
	if (node->left == NULL && node->right == NULL)
	{
		printf("%p\n",node->data);
		printf("%s\n",node->key);
	}
	else
	{
		if(node->left != NULL)
		{
			print_node(node->left);
		}
		if(node->right != NULL)
		{
			print_node(node->right);
		}
	}
}

void visit_tree(node_t *node, void (*fp)(node_t *root))
{
	node_t *root = root;
	node_t *current = node;
	while (current->left != root && current->right != root)
	{
		visit_tree(current->left, (*fp));
		visit_tree(current->right, (*fp));
	}
	if (current->left == root)
	{
		fp(current->left->data);
	}
	else if(current->right == root)
	{
		fp(current->right->data);
	}
}

void destroy_tree(node_t *node, void (*fdestroy)(node_t *root))
{
	node_t *root = root;
	while (node->left != root && node->right != root)
	{
		destroy_tree(node->left, (*fdestroy));
		destroy_tree(node->right, (*fdestroy));
	}
	if (node->left == root)
	{
		fdestroy(node->left);
	}
	else if (node->right == root)
	{
		fdestroy(node->right);
	}
}
