#include <stdio.h>
#include "unity.h"
#include "LinkedList.h"
#include "Student.h"
#include "CException.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_createdNewLinkedList_should_create_a_new_linked_list(void)
{
    LinkedList *list = createdNewLinkedList(NULL);

    TEST_ASSERT_NOT_NULL(list);
    TEST_ASSERT_NULL(list->data);
    TEST_ASSERT_NULL(list->next);

    destroyAllLinkedLists(list);
}

void test_addLinkedList_given_NULL_in_the_list_should_add_ali_to_the_list(void)
{
    Student ali = {.name = "ali", .age = 15};
    LinkedList *list;
    LinkedList *newList = createdNewLinkedList((void *)&ali);

    list = NULL;

	addLinkedList(&list, newList);

    TEST_ASSERT_NOT_NULL(list);
    TEST_ASSERT_NOT_NULL(list->data);
    TEST_ASSERT_NULL(list->next);
    TEST_ASSERT_EQUAL_PTR(newList, list);
    TEST_ASSERT_EQUAL_PTR((void *)&ali, list->data);

    destroyAllLinkedLists(list);
}

void test_addLinkedList_given_abu_in_the_list_should_add_ali_to_the_list_next_to_abu(void)
{
    Student abu = {.name = "abu", .age = 20};
    Student ali = {.name = "ali", .age = 15};
    LinkedList *list = createdNewLinkedList((void *)&abu);
    LinkedList *newList = createdNewLinkedList((void *)&ali);

	addLinkedList(&list, newList);

    TEST_ASSERT_NOT_NULL(list);
    TEST_ASSERT_NOT_NULL(list->data);
    TEST_ASSERT_NOT_NULL(list->next);
    TEST_ASSERT_NOT_NULL(list->next->data);
    TEST_ASSERT_EQUAL_PTR(newList, list->next);
    TEST_ASSERT_EQUAL_PTR((void *)&ali, list->next->data);

    destroyAllLinkedLists(list);
}

void test_addLinkedList_given_abu_and_bobo_in_the_list_should_add_ali_to_the_list_next_to_bobo(void)
{
    Student bobo = {.name = "bobo", .age = 20};
    Student abu = {.name = "abu", .age = 20};
    Student ali = {.name = "ali", .age = 15};
    LinkedList *firstList = createdNewLinkedList((void *)&abu);
    LinkedList *lastList = createdNewLinkedList((void *)&bobo);
    LinkedList *newList = createdNewLinkedList((void *)&ali);

    firstList->next = lastList;

	addLinkedList(&firstList, newList);

    TEST_ASSERT_NOT_NULL(firstList);
    TEST_ASSERT_NOT_NULL(firstList->data);
    TEST_ASSERT_NOT_NULL(firstList->next);
    TEST_ASSERT_NOT_NULL(firstList->next->data);
    TEST_ASSERT_NOT_NULL(firstList->next->next);
    TEST_ASSERT_NOT_NULL(firstList->next->next->data);
    TEST_ASSERT_EQUAL_PTR(newList, firstList->next->next);
    TEST_ASSERT_EQUAL_PTR((void *)&ali, firstList->next->next->data);

    destroyAllLinkedLists(firstList);
}

void test_compareStudent_given_two_same_student_structure_should_return_1(void)
{
    Student ali = {.name = "ali", .age = 15};

    TEST_ASSERT_EQUAL(1, compareStudent((void *)&ali, (void *)&ali));
}

void test_compareStudent_given_two_different_student_structure_should_return_0(void)
{
    Student ali = {.name = "ali", .age = 20};
    Student abu = {.name = "abu", .age = 20};

    TEST_ASSERT_EQUAL(0, compareStudent((void *)&ali, (void *)&abu));
}

void test_findLinkedList_given_abu_bobo_and_ali_in_the_list_should_find_abu_in_the_list(void)
{
    Student bobo = {.name = "bobo", .age = 20};
    Student abu = {.name = "abu", .age = 20};
    Student ali = {.name = "ali", .age = 15};
    LinkedList *firstList = createdNewLinkedList((void *)&abu);
    LinkedList *secondList = createdNewLinkedList((void *)&bobo);
    LinkedList *lastList = createdNewLinkedList((void *)&ali);
    LinkedList *foundList;

    firstList->next = secondList;
    secondList->next = lastList;

    foundList = findLinkedList(&firstList, (void *)&abu, compareStudent);

    TEST_ASSERT_NOT_NULL(foundList);
    TEST_ASSERT_NOT_NULL(foundList->data);
    TEST_ASSERT_EQUAL_PTR((void *)&abu, foundList->data);

    destroyAllLinkedLists(firstList);
}

void test_findLinkedList_given_abu_bobo_and_ali_in_the_list_should_find_bobo_in_the_list(void)
{
    Student bobo = {.name = "bobo", .age = 20};
    Student abu = {.name = "abu", .age = 20};
    Student ali = {.name = "ali", .age = 15};
    LinkedList *firstList = createdNewLinkedList((void *)&abu);
    LinkedList *secondList = createdNewLinkedList((void *)&bobo);
    LinkedList *lastList = createdNewLinkedList((void *)&ali);
    LinkedList *foundList;

    firstList->next = secondList;
    secondList->next = lastList;

    foundList = findLinkedList(&firstList, (void *)&bobo, compareStudent);

    TEST_ASSERT_NOT_NULL(foundList);
    TEST_ASSERT_NOT_NULL(foundList->data);
    TEST_ASSERT_EQUAL_PTR((void *)&bobo, foundList->data);

    destroyAllLinkedLists(firstList);
}

void test_findLinkedList_given_abu_bobo_and_ali_in_the_list_should_find_ali_in_the_list(void)
{
    Student bobo = {.name = "bobo", .age = 20};
    Student abu = {.name = "abu", .age = 20};
    Student ali = {.name = "ali", .age = 15};
    LinkedList *firstList = createdNewLinkedList((void *)&abu);
    LinkedList *secondList = createdNewLinkedList((void *)&bobo);
    LinkedList *lastList = createdNewLinkedList((void *)&ali);
    LinkedList *foundList;

    firstList->next = secondList;
    secondList->next = lastList;

    foundList = findLinkedList(&firstList, (void *)&ali, compareStudent);

    TEST_ASSERT_NOT_NULL(foundList);
    TEST_ASSERT_NOT_NULL(foundList->data);
    TEST_ASSERT_EQUAL_PTR((void *)&ali, foundList->data);

    destroyAllLinkedLists(firstList);
}

void test_findLinkedList_given_abu_bobo_and_ali_in_the_list_should_find_bubu_in_the_list_and_return_null(void)
{
    Student bubu = {.name = "bubu", .age = 18};
    Student bobo = {.name = "bobo", .age = 20};
    Student abu = {.name = "abu", .age = 20};
    Student ali = {.name = "ali", .age = 15};
    LinkedList *firstList = createdNewLinkedList((void *)&abu);
    LinkedList *secondList = createdNewLinkedList((void *)&bobo);
    LinkedList *lastList = createdNewLinkedList((void *)&ali);
    LinkedList *foundList;

    firstList->next = secondList;
    secondList->next = lastList;

    foundList = findLinkedList(&firstList, (void *)&bubu, compareStudent);

    TEST_ASSERT_NULL(foundList);

    destroyAllLinkedLists(firstList);
}

void test_removeLinkedList_given_abu_bobo_and_ali_in_the_list_should_remove_firstList(void)
{
    Student bobo = {.name = "bobo", .age = 20};
    Student abu = {.name = "abu", .age = 20};
    Student ali = {.name = "ali", .age = 15};
    LinkedList *firstList = createdNewLinkedList((void *)&abu);
    LinkedList *secondList = createdNewLinkedList((void *)&bobo);
    LinkedList *lastList = createdNewLinkedList((void *)&ali);

    firstList->next = secondList;
    secondList->next = lastList;

    removeLinkedList(&firstList, firstList);

    TEST_ASSERT_NOT_NULL(firstList);
    TEST_ASSERT_NOT_NULL(firstList->data);
    TEST_ASSERT_NOT_NULL(firstList->next);
    TEST_ASSERT_NOT_NULL(firstList->next->data);
    TEST_ASSERT_NULL(firstList->next->next);
    TEST_ASSERT_EQUAL_PTR((void *)&bobo, firstList->data);
    TEST_ASSERT_EQUAL_PTR(lastList, firstList->next);
    TEST_ASSERT_EQUAL_PTR((void *)&ali, firstList->next->data);

    destroyAllLinkedLists(firstList);
}

void test_removeLinkedList_given_abu_bobo_and_ali_in_the_list_should_remove_secondList(void)
{
    Student bobo = {.name = "bobo", .age = 20};
    Student abu = {.name = "abu", .age = 20};
    Student ali = {.name = "ali", .age = 15};
    LinkedList *firstList = createdNewLinkedList((void *)&abu);
    LinkedList *secondList = createdNewLinkedList((void *)&bobo);
    LinkedList *lastList = createdNewLinkedList((void *)&ali);

    firstList->next = secondList;
    secondList->next = lastList;

    removeLinkedList(&firstList, secondList);

    TEST_ASSERT_NOT_NULL(firstList);
    TEST_ASSERT_NOT_NULL(firstList->data);
    TEST_ASSERT_NOT_NULL(firstList->next);
    TEST_ASSERT_NOT_NULL(firstList->next->data);
    TEST_ASSERT_NULL(firstList->next->next);
    TEST_ASSERT_EQUAL_PTR((void *)&abu, firstList->data);
    TEST_ASSERT_EQUAL_PTR(lastList, firstList->next);
    TEST_ASSERT_EQUAL_PTR((void *)&ali, firstList->next->data);

    destroyAllLinkedLists(firstList);
}

void test_removeLinkedList_given_abu_bobo_and_ali_in_the_list_should_remove_lastList(void)
{
    Student bobo = {.name = "bobo", .age = 20};
    Student abu = {.name = "abu", .age = 20};
    Student ali = {.name = "ali", .age = 15};
    LinkedList *firstList = createdNewLinkedList((void *)&abu);
    LinkedList *secondList = createdNewLinkedList((void *)&bobo);
    LinkedList *lastList = createdNewLinkedList((void *)&ali);

    firstList->next = secondList;
    secondList->next = lastList;

    removeLinkedList(&firstList, lastList);

    TEST_ASSERT_NOT_NULL(firstList);
    TEST_ASSERT_NOT_NULL(firstList->data);
    TEST_ASSERT_NOT_NULL(firstList->next);
    TEST_ASSERT_NOT_NULL(firstList->next->data);
    TEST_ASSERT_NULL(firstList->next->next);
    TEST_ASSERT_EQUAL_PTR((void *)&abu, firstList->data);
    TEST_ASSERT_EQUAL_PTR(secondList, firstList->next);
    TEST_ASSERT_EQUAL_PTR((void *)&bobo, firstList->next->data);

    destroyAllLinkedLists(firstList);
}

void test_removeLinkedList_given_abu_bobo_and_ali_in_the_list_and_remove_list_should_throw_ERR_LIST_UNAVAILABLE(void)
{
    CEXCEPTION_T err;
    Student bubu = {.name = "bubu", .age = 10};
    Student bobo = {.name = "bobo", .age = 20};
    Student abu = {.name = "abu", .age = 20};
    Student ali = {.name = "ali", .age = 15};
    LinkedList *firstList = createdNewLinkedList((void *)&abu);
    LinkedList *secondList = createdNewLinkedList((void *)&bobo);
    LinkedList *lastList = createdNewLinkedList((void *)&ali);
    LinkedList *list = createdNewLinkedList((void *)&bubu);

    firstList->next = secondList;
    secondList->next = lastList;

    Try{
        removeLinkedList(&firstList, list);
        TEST_FAIL_MESSAGE("Should generate an exception due to ERR_LIST_UNAVAILABLE.");
    } Catch(err){
        TEST_ASSERT_EQUAL_MESSAGE(ERR_LIST_UNAVAILABLE, err, "Expected ERR_LIST_UNAVAILABLE exception");
    }

    destroyAllLinkedLists(firstList);
    destroyAllLinkedLists(list);
}
