#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "graph.h"



pnode build_graph_cmd(int numOfNodes){
    node *head = NULL;
    pnode newNode , tmpNode = NULL;
    int i;
    head = (pnode)malloc(sizeof(node));
    if (head == NULL)
    {
        perror("malloc failed");
        exit(0);
    }
    head->node_num=0;
    head->edges = NULL;
    head->next = NULL;

    tmpNode = head;

    for (i = 1; i < numOfNodes; i++)
    {
        newNode = (pnode)malloc(sizeof(node));
        if (newNode == NULL)
        {
        perror("malloc failed");
        exit(0);
        }

        newNode->node_num = i;
        newNode->edges = NULL;
        newNode->next= NULL;
        tmpNode->next= newNode;
        tmpNode= tmpNode->next;
    }
    return head;
}

void printGraph_cmd(pnode head){//for self debug
    pnode tempNode = head;
    while (tempNode != NULL)
    {
        printf("Node: %d {", tempNode->node_num);
        pedge tempEdge = tempNode->edges;
        while (tempEdge != NULL)
        {
            printf("dest: %d weight: %d ", tempEdge->endpoint->node_num, tempEdge->weight);
            tempEdge = tempEdge->next;
        }
        printf("}");
        tempNode = tempNode->next;
    }
}

void deleteGraph_cmd(pnode *head){
    pnode tempNode = *head;
    while (tempNode != NULL)
    {
        pedge tempEdge = tempNode->edges;
        while (tempEdge != NULL)
        {
            pedge tempEdgefree = tempEdge;
            tempEdge = tempEdge->next;
            free(tempEdgefree);
        }
        node *tempFree = tempNode;
        tempNode = tempNode->next;
        free(tempFree);
    }
    free(tempNode);
}
