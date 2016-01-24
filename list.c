
#include <assert.h>
#include <stdlib.h>

#include "list.h"

// Takes a valid, sorted list starting at `head` and adds the element
// `new_element` to the list. The list is sorted based on the value of the
// `index` member in ascending order. Returns a pointer to the head of the list
// after the insertion of the new element.
//1->2->3, 4/

list_t* insert_sorted(list_t* head, list_t* new_element) {
	assert(head != NULL);
	assert(new_element != NULL);
	list_t* larger = head;
	list_t* smaller = head;
	while (larger != NULL && larger->index < new_element->index) {
		smaller = larger;
		larger = smaller->next;
	}
	if (smaller == larger) {
		new_element->next= smaller;
		head = new_element;
	}
	else {
		smaller->next = new_element;
		new_element->next = larger;
	}

	return head;
}

// Reverses the order of the list starting at `head` and returns a pointer to
// the resulting list. You do not need to preserve the original list.
list_t* reverse(list_t* head) {
	assert(head != NULL);
	list_t* cur;
	list_t* next;
	list_t* prev;
	prev = head;
	cur = head->next;
	prev->next = NULL;
	while (cur != NULL && cur->next != NULL) {
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	if (cur != NULL) {
		cur->next = prev;
		head = cur;
	}
	else head = prev;

	return head;
}
