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
	node_t *root = (node_t *)malloc(sizeof(node_t));
	root->key = NULL;
	root->data = NULL;
	root->left = NULL;
	root->right = NULL;
	return 0;
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
		printf("%s\n",*node->left->data);
		printf("%s\n",*node->data);
		printf("%s\n",*node->right->data);
	}
	else{
		print_node(node->left);
		print_node(node->right);
	}
}

void visit_tree(node_t *node, void (*fp)(node_t *root))
{
	node_t *current = node;
	while (current->left != root && current->right != root)
	{
		visit_tree(current->left, (*fp)(root));
		visit_tree(current->right, (*fp)(root));
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
	while (node->left != root && node->right != root)
	{
		destroy_tree(node->left, (*fdestroy)(root));
		destroy_tree(node->right, (*fdestroy)(root));
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
