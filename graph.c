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

    for (int i = 1; i < numOfNodes; i++)
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
    pnode tmpNode = head;

    while (tmpNode =! NULL)
    {
        int num= tmpNode->node_num;
        printf("Node: %d ", num);

        pedge edge = tmpNode -> edges;
        while (edge != NULL)
        {
            pnode dest = edge -> endpoint ->node_num;
            int weight= edge ->weight;
            printf("Dest: %d , Weight: %d ", dest, weight);
            edge = edge->next;
        }

        tmpNode = tmpNode ->next;
        printf("\n");
    }
    
}

void deleteGraph_cmd(pnode *head){
    pnode tmpNode = *head;

    while (tmpNode != NULL)
    {
        pedge nodeEdge = tmpNode -> edges;
        while (nodeEdge =! NULL)
        {
            pedge freeEdge = nodeEdge;
            nodeEdge = nodeEdge->next; 
            free(freeEdge);
        }

        pnode freeNode = tmpNode;
        tmpNode = tmpNode -> next;
        free(freeNode); 
    }
    free(tmpNode);
}
