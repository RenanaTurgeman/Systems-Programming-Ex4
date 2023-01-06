#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "nodes.h"

int char_to_int(char c) {
    return c - '0';
}

void delete_node_cmd(pnode *head){
    pnode tempNode = head;

    while (tempNode != NULL)
    {
        pedge tempEdge= tempNode -> edges;
        while (tempEdge != NULL)
        {
            pedge tempEdgeFree = tempEdge;
            tempEdge = tempEdge-> next;
            free(tempEdgeFree);
        }

        node *tempFree = tempNode;
        tempNode = tempNode->next;
        free(tempFree);
    }
    free(tempNode);
}