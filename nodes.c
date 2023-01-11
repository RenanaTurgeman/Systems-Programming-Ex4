#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int char_to_int(char c) {
    return c - '0';
}

void delete_node_cmd(pnode *head)
{
    int id = 0;
    scanf("%d", &id);
    delete_edge(head, id);
    pnode tempNode = *head;
    node *pNode = NULL;
    if (tempNode->node_num != id)
    {
        while (tempNode->next->node_num != id)
        {
            tempNode = tempNode->next;
        }
        pNode = tempNode->next;
        tempNode->next = tempNode->next->next;
        free_edges(pNode);
        free(pNode);
    }
    else
    {
        pNode = *head;
        *head = pNode->next;
        free_edges(pNode);
        free(pNode);
    }
}
void insert_node_cmd(pnode *head)
{
    int src;
    scanf("%d", &src);
    int dest;
    int weight;
    pnode temp = getNode(src, head);
    if (temp == NULL)
    {
        pnode pGraphNode = *head;
        while (pGraphNode->next != NULL)
        {
            pGraphNode = pGraphNode->next;
        }
        pnode newNode = (pnode)(malloc(sizeof(node)));
        if (newNode == NULL)
        {
            perror("malloc didnt work");
            exit(0);
        }
        newNode->node_num = src;
        newNode->edges = NULL;
        newNode->next = NULL;
        pGraphNode->next = newNode;
        while (scanf("%d", &dest) != 0 && scanf("%d", &weight) != 0)
        {
            if (isalpha(dest) || isalpha(weight))
            {
                break;
            }
            add_edge(newNode, dest, weight, head);
        }
    }
    else
    {
        free_edges(temp);
        temp->edges = NULL;
        while (scanf("%d", &dest) != 0 && scanf("%d", &weight) != 0)
        {
            if (isalpha(dest) || isalpha(weight))
            {
                break;
            }
            add_edge(temp, dest, weight, head);
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
void insertNodeToGraph(pnode *head, int src)
{

    int dest;
    int weight;
    pnode temp = getNode(src, head);
    while (scanf("%d", &dest) != 0 && scanf("%d", &weight) != 0)
    {
        if (isalpha(dest) || isalpha(weight))
        {
            break;
        }
        add_edge(temp, dest, weight, head);
    }
}