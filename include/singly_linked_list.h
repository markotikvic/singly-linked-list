#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

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

#endif /* SINGLY_LINKED_LIST_H */
