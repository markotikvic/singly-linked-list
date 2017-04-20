#include "list.h"

int main(void)
{
	struct node *head = new_list(1);
	add_node(&head, 9);
	add_node(&head, 0);
	add_node(&head, 1);
	add_node(&head, 8);
	add_node(&head, 6);
	add_node(&head, 3);
	add_node(&head, 2);
	add_node(&head, 1);
	print_list(&head);

	delete_node(&head, 1);
	//delete_first(&head);
	//insert_first(&head, 2222);
	//delete_after(&head, 9);
	//delete_before(&head, 9);
	//delete_node(&head, 2);
	//delete_node(&head, 3);
	//delete_node(&head, 4);

	//add_node(&head, 7);

	//delete_first(&head);
	//delete_last(&head);
	//delete_after(&head, 8);
	//delete_before(&head, 4);

	//sort_list_by_reference(&head, 1);
	//sort_list_by_value(&head, 1);
	//sort_list_by_value(&head, -1);
	sort_list_by_reference(&head, -1);

	add_node(&head, 22);
	print_list(&head);

	destroy_list(&head);

	return 0;
}
