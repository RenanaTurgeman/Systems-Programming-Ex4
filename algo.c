#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "algo.h"

buildDijkstra(pnode head, int src){
    pdijkstra head = NULL;

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