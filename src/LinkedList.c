#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include "LinkedList.h"
#include "Student.h"

int compareStudent(void *dataInCollection, void *data)
{
    Student *studentInTheList = (Student *)dataInCollection;
    Student *studentToBeFound = (Student *)data;

    if(studentInTheList->name == studentToBeFound->name && studentInTheList->age == studentToBeFound->age)
        return 1;
    else if(studentInTheList->name != studentToBeFound->name || studentInTheList->age != studentToBeFound->age)
        return 0;
}

LinkedList *createdNewLinkedList(void *data)
{
    LinkedList *newList;

    newList = malloc(sizeof(LinkedList));
    newList->data = data;
    newList->next = NULL;

    return newList;
}

void destroyAllLinkedLists(LinkedList *firstList)
{
    assert(firstList != NULL);
    if(firstList != NULL)
    {
        if(firstList->next != NULL)
            destroyAllLinkedLists(firstList->next);

        free(firstList);
    }
}

LinkedList *findLinkedList(LinkedList **listPtr, void *data, int (*compare)(void *dataInCollection, void *data))
{
    LinkedList *list = *listPtr;
    LinkedList *foundList = NULL;

    if(list != NULL)
    {
        if(compare(list->data, data))
            foundList = list;
        else
            foundList = findLinkedList(&list->next, data, compare);
    }

    return foundList;
}

void addLinkedList(LinkedList **listPtr, LinkedList *newList)
{
    // printf("yes\n");
    assert(newList != NULL);
    if(*listPtr == NULL)
        *listPtr = newList;
    else
        addLinkedList(&(*listPtr)->next, newList);
}

void removeLinkedList(LinkedList **listPtr, LinkedList *listToRemove)
{
    LinkedList *list = *listPtr;

    if(list == NULL)
        Throw(ERR_LIST_UNAVAILABLE);

    if(list == listToRemove)
        *listPtr = (*listPtr)->next;
    else
        removeLinkedList(&list->next, listToRemove);
}
