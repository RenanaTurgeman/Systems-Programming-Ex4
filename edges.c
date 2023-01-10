#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "graph.h"

void add_edge(pnode newNode, int dest, int weight, pnode *head)
{

    if (newNode->edges == NULL)
    {
        newNode->edges = (pedge)malloc(sizeof(edge));
        if (newNode->edges == NULL)
        {
            perror("malloc didnt work");
            exit(0);
        }
        newNode->edges->weight = weight;
        newNode->edges->next = NULL;
        node *destNode = getNode(dest, head);
        newNode->edges->endpoint = &(*destNode);
    }
    else
    {
        pedge nodeEdges = newNode->edges;
        while (nodeEdges->next != NULL)
        {
            nodeEdges = nodeEdges->next;
        }
        //add the new edge
        nodeEdges->next = (pedge)malloc(sizeof(edge));
        if (nodeEdges->next == NULL)
        {
            perror("malloc didnt work");
        }
        nodeEdges->next->next = NULL;
        nodeEdges->next->weight = weight;
        node *destNode = getNode(dest, head);
        nodeEdges->next->endpoint = &(*destNode);
    }
}

void free_edges(pnode tmpNode)
{
    if (tmpNode->edges != NULL)
    {
        pedge temp = tmpNode->edges;

        while (temp != NULL)
        {
            pedge freeEdge = NULL;
            freeEdge = temp;
            temp = temp->next;
            free(freeEdge);
        }
    }
    else{
        free(tmpNode->edges);
    }
}

void delete_edge(pnode *head, int nodeId)
{
    pnode tempNode = *head;

    while (tempNode != NULL)
    {
        if (tempNode->node_num != nodeId && tempNode->edges != NULL)
        {

            if (tempNode->edges->endpoint->node_num != nodeId)
            {
                pedge tempEdge = tempNode->edges;

                while (tempEdge->next != NULL)
                {
                    if (tempEdge->next->endpoint->node_num == nodeId)
                    {
                        pedge pe = tempEdge->next;
                        tempEdge->next = tempEdge->next->next;
                        free(pe);
                        break;
                    }
                    tempEdge = tempEdge->next;
                }
            }
            else
            {
                if (tempNode->edges->next == NULL)
                {
                    pedge pe = tempNode->edges;
                    tempNode->edges = NULL;
                    free(pe);
                }
                else
                {
                    pedge pe = tempNode->edges;
                    tempNode->edges = pe->next;
                    free(pe);
                }
            }
        }
        tempNode = tempNode->next;
    }
}