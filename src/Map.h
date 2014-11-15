#ifndef Map_H
#define Map_H

#include "LinkedList.h"

typedef struct Map Map;

struct Map
{
    int size;
    LinkedList **table;
};

Map *createMap(int size);
void destroyMap(Map *map);
void addMap(Map *map, void *data, int (*hash)(void *data));
void *findMap(Map *map, void *data, int (*hash)(void *data));
void *delMap(Map *map, void *data, int (*hash)(void *data));

#endif // Map_H
