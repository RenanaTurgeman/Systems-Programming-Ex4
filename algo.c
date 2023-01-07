#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "algo.h"

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