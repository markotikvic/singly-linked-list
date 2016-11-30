#include <stdio.h>
#include <stdlib.h>
#include "../include/list.h"

struct node {
	int val;
	struct node *next;
};

struct node *new_list(int val)
{
	struct node *head = (struct node*) malloc(sizeof(struct node*));

	head = (struct node*) malloc(sizeof(struct node));
	head->val = val;
	head->next = NULL;
	return head;
}

void add_node(struct node **head, int val)
{
	if (*head == NULL) {
		insert_first(head, val);
		return;
	}

	struct node *curr = *head;
	struct node *n = (struct node*) malloc(sizeof(struct node));
	n->val = val;
	while (curr->next)
		curr = curr->next;
	curr->next = n;
}

// This is only a copy of a pointer.
// Changing its value doesn't change the value
// of the pointer passed from main function.
void insert_first(struct node **head, int val)
{
	struct node *n = (struct node*) malloc(sizeof(struct node));
	n->val = val;
	n->next = *head;
	*head = n;
}

void insert_before(struct node **head, int key, int val)
{
	struct node *curr = *head;
	struct node *prev = curr;
	struct node *n;

	while (curr != NULL) {
		if (curr->val == key) {
			n = (struct node*) malloc(sizeof(struct node));
			n->val = val;
			n->next = curr;
			prev->next = n;
			break;
		}
		prev = curr;
		curr = curr->next;
	}
}

void insert_after(struct node **head, int key, int val)
{
	struct node *curr = *head;
	struct node *n;

	while (curr != NULL) {
		if (curr->val == key) {
			n = (struct node*) malloc(sizeof(struct node));
			n->val = val;
			n->next = curr->next;
			curr->next = n;
			break;
		}
		curr = curr->next;
	}
}

void remove_first(struct node **head)
{
	struct node *to_del = *head;
	*head = (*head)->next;
	free(to_del);
}

void remove_last(struct node **head)
{
	struct node *n = *head;
	while (n->next->next != NULL)
		n = n->next;
	free(n->next);
	n->next = NULL;
}

void remove_before(struct node **head, int key)
{
	struct node *curr = *head;
	struct node *prev = curr;

	while (curr->next != NULL) {
	       	if (curr->next->val == key) {
			prev->next = curr->next;
			free(curr);
		}
		prev = curr;
		curr = curr->next;
	}
}

void remove_after(struct node **head, int key)
{
	struct node *curr = *head;

	while (curr != NULL) {
		if (curr->val == key) {
			struct node *tmp = curr->next;
			curr->next = curr->next->next;
			free(tmp);
			break;
		}
		curr = curr->next;
	}
}

void remove_node(struct node **head, int key)
{
	while (*head != NULL) {
		if ((*head)->val == key) {
			struct node *tmp = *head;
			*head = (*head)->next;
			free(tmp);
			break;
		}
		head = &(*head)->next;
	}
}

void print_list(struct node **head)
{
	struct node *n = *head;
	printf("Linked list:\n");
	while (n != NULL) {
		printf("-> %d\n", n->val);
		n = n->next;
	} 
}

void destroy_list(struct node **head)
{
	struct node *prev = *head;
	while (*head != NULL) {
		prev = *head;
		*head = (*head)->next;
		free(prev);
		prev = NULL;
	}
}

void sort_list_by_value(struct node **head, int dir)
{
	struct node *curr;
	int done = 0, temp;

	while (!done) {
		curr = *head;
		done = 1;
		while (curr->next != NULL) {
			if (dir*curr->val > dir*curr->next->val) {
				done = 0;
				temp = curr->val;
				curr->val = curr->next->val;
				curr->next->val = temp;
			}
			curr = curr->next;
		}
	}
}

void sort_list_by_reference(struct node **head, int dir)
{
	struct node *back, *middle, *front;
	int done = 0;

	while (!done) {
		middle = *head;
		front = (*head)->next;
		back = NULL;
		done = 1;
		while (front != NULL) {
			if (dir*middle->val > dir*front->val) {
				done = 0;
				middle->next = front->next;
				front->next = middle;

				if (back != NULL)
					back->next = front;
				else
					*head = front;
				back = front;
				front = middle->next;
				break;
			}
			back = middle;
			middle = front;
			front = front->next;
		}
	}
}
