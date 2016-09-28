// Keep API consistent (require **head even if only *head would do the job)
#include <stdio.h>
#include <stdlib.h>

struct node {
	int val;
	struct node *next;
};

struct node *create_new_list(int val);
void add_node(struct node **head, int val);
void insert_first(struct node **head, int val);
void insert_before(struct node **head, int key, int val);
void insert_after(struct node **head, int key, int val);
void remove_first(struct node **head);
void remove_last(struct node **head);
void remove_before(struct node **head, int key);
void remove_after(struct node **head, int key);
void remove_node(struct node **head, int key);
void print_list(struct node **head);
void destroy_list(struct node **head);
void sort_list_by_value(struct node **head, int dir);
void sort_list_by_reference(struct node **head, int dir);

int main(void)
{
	struct node *head = create_new_list(1);

	add_node(&head, 9);
	add_node(&head, 0);
	add_node(&head, 8);
	add_node(&head, 6);
	add_node(&head, 3);
	print_list(&head);

	//sort_list_by_value(&head, 1);
	//sort_list_by_reference(&head, 1);
	//sort_list_by_value(&head, -1);
	sort_list_by_reference(&head, -1);
	print_list(&head);

	/*remove_node(&head, 1);
	print_list(&head);

	remove_node(&head, 2);
	print_list(&head);

	remove_node(&head, 3);
	print_list(&head);

	remove_node(&head, 4);
	print_list(&head);

	add_node(&head, 7);
	print_list(&head);*/

	/*remove_first(&head);
	remove_last(&head);
	remove_after(&head, 8);
	remove_before(&head, 4);*/

	destroy_list(&head);

	return 0;
}

struct node *create_new_list(int val)
{
	struct node *head = (struct node*)malloc(sizeof(struct node*));

	head = (struct node*)malloc(sizeof(struct node));
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
	struct node *n = (struct node*)malloc(sizeof(struct node));
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
	struct node *n = (struct node*)malloc(sizeof(struct node));
	n->val = val;
	n->next = *head;
	*head = n;
}

void insert_before(struct node **head, int key, int val)
{
	if (*head == NULL)
		return;

	struct node *curr = *head;
	struct node *prev = curr;
	while (curr != NULL) {
		if (curr->val == key) {
			struct node *n = (struct node*)malloc(sizeof(struct node));
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
	if (*head == NULL)
		return;

	struct node *curr = *head;
	while (curr != NULL) {
		if (curr->val == key) {
			struct node *n = (struct node*)malloc(sizeof(struct node));
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
	if (*head == NULL)
		return;

	struct node *to_del = *head;
	*head = (*head)->next;
	free(to_del);
}

void remove_last(struct node **head)
{
	if (*head == NULL)
		return;

	struct node *n = *head;
	while (n->next->next != NULL)
		n = n->next;
	free(n->next);
	n->next = NULL;
}

void remove_before(struct node **head, int key)
{
	if (*head == NULL)
		return;

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
	if (*head == NULL)
		return;

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
	if (*head == NULL)
		return;

	while (*head != NULL) {
		if ((*head)->val == key) {
			struct node *tmp = *head;
			//curr = curr->next;
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
	if (*head == NULL)
		return;

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

// @TODO
void sort_list_by_reference(struct node **head, int dir)
{
	if (*head == NULL)
		return;

	struct node *a, *b, *c;
	int done = 0;

	while (!done) {
		b = *head;
		c = (*head)->next;
		a = NULL;
		done = 1;
		while (c != NULL) {
			if (dir*b->val > dir*c->val) {
				done = 0;
				b->next = c->next;
				c->next = b;

				if (a != NULL)
					a->next = c;
				else
					*head = c;
				a = c;
				c = b->next;
				break;
			}
			a = b;
			b = c;
			c = c->next;
		}
	}
}
