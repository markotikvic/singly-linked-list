#include "../include/singly_linked_list.h"

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
	sort_list_by_reference(&head, 1);
	//sort_list_by_value(&head, -1);
	//sort_list_by_reference(&head, -1);
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
