#include <stdio.h>
#include "unity.h"
#include "LinkedList.h"
#include "Student.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_addLinkedList_given_NULL_in_the_list_should_add_ali_to_the_list(void)
{
    Student ali = {.name = "ali", .age = 15};
    LinkedList *list;
    LinkedList *newList;

    list->next = NULL;
    list->data = NULL;
    newList->next = NULL;
    newList->data = (Student *)&ali;

	// addLinkedList(&list, &newList);
}
