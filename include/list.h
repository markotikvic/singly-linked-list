#ifndef LIST_H
#define LIST_H

struct node *new_list(int val);
void add_node(struct node **head, int val);
void insert_first(struct node **head, int val);
void insert_before(struct node **head, int key, int val);
void insert_after(struct node **head, int key, int val);
void delete_first(struct node **head);
void delete_last(struct node **head);
void delete_before(struct node **head, int key);
void delete_after(struct node **head, int key);
void delete_node(struct node **head, int key);
void print_list(struct node **head);
void destroy_list(struct node **head);
void sort_list_by_value(struct node **head, int dir);
void sort_list_by_reference(struct node **head, int dir);

#endif /* LIST_H */
