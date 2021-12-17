#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct node {
	void 	    *data;
	struct node *next;
} 	node_t;

node_t *list_create(void *data)
{
	node_t *new = (node_t *)malloc(sizeof(node_t));
	new->data = data;
	new->next = NULL;
	return new;
}
void list_destroy(node_t **head, void (*fp)(void *data))
{

	node_t *current = *head;
	node_t *new;
	while (current != NULL)
	{
		new = current->next;
		fp(current->data);
		free(current);
		current = new;
	}
	*head = NULL;

}
void list_push(node_t *head, void *data)
{
	node_t *current = head;
	while(current->next != NULL)
	{
		current = current->next;
	}
	node_t *new = (node_t *)malloc(sizeof(node_t));
	new->data = data;
	new->next = NULL;
	current->next = new;
}
void list_unshift(node_t **head, void *data)
{
	node_t *new = (node_t *)malloc(sizeof(node_t));
	new->data = data;
	new->next = *head;
	*head = new;
}
void *list_pop(node_t **head)
{
	node_t *current = *head;
	node_t *previous = NULL;
	if (current->next != NULL)
	{
		previous = current;
		current = current->next;

	}
	previous->next = NULL;
	return current;
}
void *list_shift(node_t **head)
{
	node_t *current = *head;
	*head = current->next;
	free(current);
	return 0;
}
void list_print(node_t *head)
{
	node_t *current = head;
	while(current != NULL)
	{
		printf("%s", (char *)current->data);
		current = current->next;
	}
}
void *list_remove(node_t **head, node_t *ptr)
{
	node_t *current = *head;
	node_t *previous = NULL;
	node_t *node_next = current->next;
	while(current != ptr)
	{
		current = current->next;
		previous = current;
		node_next = current->next->next;
	}
	previous->next = node_next;
	free(current);
	return 0;
}
void list_visitor(node_t *head, void(*fp)(void *data))
{
	node_t *node = head;
	while (node != NULL)
	{
		fp(node->data);
		node = node->next;
	}
}

