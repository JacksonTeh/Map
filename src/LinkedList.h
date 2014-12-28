#ifndef LinkedList_H
#define LinkedList_H

typedef enum {ERR_NO_ERROR, ERR_LIST_UNAVAILABLE} Error;

typedef struct LinkedList LinkedList;

struct LinkedList
{
    void *data;
    LinkedList *next;
};

int compareStudent(void *dataInCollection, void *data);

LinkedList *createdNewLinkedList(void *data);
void destroyAllLinkedLists(LinkedList *firstList);
LinkedList *findLinkedList(LinkedList **listPtr, void *data, int (*compare)(void *dataInCollection, void *data));
void addLinkedList(LinkedList **listPtr, LinkedList *newList);
void removeLinkedList(LinkedList **listPtr, LinkedList **listToRemove);

#endif // LinkedList_H
