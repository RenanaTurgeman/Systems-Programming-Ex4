#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
//****TSP****//
int weight;
int arrlenth;
pnode graph;

///Dijkstra
pdijkstra buildDijkstra(pnode start, int src){
    pdijkstra head = NULL;
    pdijkstra *index = &head; //what it is main?
 while (start != NULL)
    {
        (*index) = (pdijkstra)malloc(sizeof(dijkstra));
        if ((*index) == NULL)
        {
            perror("malloc didnt work");
            exit(0);
        }

        (*index)->node = start;
        if (start->node_num == src)
        {
            (*index)->weight = 0;
        }
        else
        {
            (*index)->weight = INFINITY;
        }
        (*index)->tag = 0;
        (*index)->next = NULL;
        index = &((*index)->next);
        start = start->next;
    }
    return head;
}

pdijkstra minVertical(pdijkstra head)
{
    pdijkstra vertical = NULL;
    while (head != NULL)
    {
        if (!head->tag && head->weight < INFINITY && (vertical == NULL || vertical->weight < head->weight))
        {
            vertical = head;
        }
        head = head->next;
    }
    if (vertical != NULL)
    {
        vertical->tag = 1;
    }
    return vertical;
}

pdijkstra getPdijkstra(pdijkstra head, int id)
{
    while (head != NULL)
    {
        if (head->node->node_num == id)
        {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

void deletateDijkstra(pdijkstra dijkstra)
{
    while (dijkstra != NULL)
    {
        pdijkstra temp = dijkstra;
        dijkstra = dijkstra->next;
        free(temp);
    }
}

int shortsPath_cmd(pnode head, int src , int dest){
    pdijkstra dijkstraHead = buildDijkstra(head, src);
    pdijkstra u = minVertical(dijkstraHead);
    while (u != NULL)
    {
        pedge edgeIndex = u->node->edges;
        while (edgeIndex != NULL)
        {
            // relax
            pdijkstra v = getPdijkstra(dijkstraHead, edgeIndex->endpoint->node_num);
            int newDist = u->weight + edgeIndex->weight;
            if (v->weight > newDist)
            {
                v->weight = newDist;
            }
            edgeIndex = edgeIndex->next;
        }
        u = minVertical(dijkstraHead);
    }
    int distance = getPdijkstra(dijkstraHead, dest)->weight;
    if (distance == INFINITY)
    {
        distance = -1;
    }
    deletateDijkstra(dijkstraHead);
    return distance;
}

//TSP
void deep_copy(int *fromArr, int *toArr, int arrLenght)
{
    for (int i = 0; i < arrLenght; ++i)
    {
        toArr[i] = fromArr[i];
    }
}

void swap(int *arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void permotion(int start, int *arr, int arrLength)
{
    if (start == arrLength - 1)
    {
        calcPermot(arr, arrLength);
        return;
    }
    for (int i = start; i < arrLength; ++i)
    {
        int *arrCopy = (int *)(calloc(arrLength, sizeof(int)));
        deep_copy(arr, arrCopy, arrLength);
        swap(arrCopy, start, i);
        permotion(start + 1, arrCopy, arrLength);
        free(arrCopy);
    }
}

void calcPermot(int *arr, int arrLength)
{
    int tempWeight = 0;
    for (int i = 0; i < arrLength - 1; ++i)
    {
        int distance = shortsPath_cmd(graph, arr[i], arr[i + 1]);
        if (distance == -1)
        {
            tempWeight = INFINITY;
            return;
        }
        tempWeight += distance;
    }
    if (tempWeight < weight)
    {
        weight = tempWeight;
    }
}

void TSP_cmd(pnode head){
    weight = INFINITY;
	arrlenth = -1;
    graph = head;
    scanf("%d", &arrlenth);
    int *arr = (int *)(calloc(arrlenth, sizeof(int)));
    for (int i = 0; i < arrlenth; i++)
    {
        scanf("%d", &arr[i]);
    }
    // for (int i = 0; i < arrlenth; ++i)
    // {
    //      printf("%d , ", arr[i]);
    // }
    // printf("\n");
    int *arrCopy = (int *)(calloc(arrlenth, sizeof(int)));
    deep_copy(arr, arrCopy, arrlenth);
    // for (int i = 0; i < arrlenth; ++i)
    // {
    //     printf("%d , ", arr[i]);
    // }
    // printf("\n");
    permotion(0, arrCopy, arrlenth);
    free(arr);
    free(arrCopy);
    if (weight == INFINITY)
    {
        weight = -1;
    }
    printf("TSP shortest path: %d \n", weight);
}
