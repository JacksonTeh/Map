#include <stdio.h>
#include <malloc.h>
#include "Map.h"
#include "LinkedList.h"
#include "Student.h"
#include "HashFunction.h"

Map *createMap(int size)
{
    Map *map = malloc(sizeof(Map));
    map->size = size;
    map->table = malloc(sizeof(LinkedList *) * size);

    return map;
}

void destroyMap(Map *map)
{
    int i;

    if(map != NULL)
    {
        for(i = 0; i < map->size; i++)
        {
            destroyAllLinkedLists(map->table[i]);
        }
    }

    free(map->table);
    free(map);
}

void addMap(Map *map, void *data, int (*hash)(void *data))
{
    int hashValue = hash(data);
    printf("hashValue: %d\n", hashValue);
}