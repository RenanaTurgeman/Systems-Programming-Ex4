#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "nodes.h"
#include "edges.h"

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

void insert_node_cmd(pnode *head){
   
    int src;
    scanf("%d", &src);
    int dest,weight;
    //check if the node is exsits
    pnode tmpNode = getNode(src,head);

    if(tmpNode == NULL){ //the node not exsists
        pnode nodeInGraph = *head;
        while (nodeInGraph -> next != NULL)
        {
             nodeInGraph = nodeInGraph -> next;
        }

        pnode newNode = (pnode)malloc(sizeof(node));
        if (newNode == NULL)
        {
            perror("malloc didnt work");
            return 0;
        }

        nodeInGraph -> next = newNode;
        newNode-> next =NULL;
        newNode -> edges = NULL; 
        newNode -> node_num = src;     

        //now define the edges (dest,wieght)
        while (scanf("%d",&dest) != 0 && scanf("%d", &weight) != 0)
        {
             if (isalpha(dest) || isalpha(weight)) //checks if a given character is an alphabetic character.
            {
                break;
            }
            add_edge(newNode, dest, weight, head);
        } 
    }
    else{ //node exsits - tmpNode is the new node
        free_edges(tmpNode);
        tmpNode->edges = NULL;
        //now define the new edges (dest,wieght)
        while (scanf("%d",&dest) != 0 && scanf("%d", &weight) != 0)
        {
             if (isalpha(dest) || isalpha(weight)) //checks if a given character is an alphabetic character.
            {
                break;
            }
            add_edge(tmpNode, dest, weight, head);
        } 
    }
}

pnode getNode(int id, pnode *head){

    pnode check = *head;

    while (check != NULL)
    {
        if (check -> node_num ==id)
        {
            return check;
        }
        check = check -> next;
    }
    return NULL;
}
