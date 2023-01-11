#include <stdio.h>
#include "graph.h"

int main()
{
    pnode temp = NULL;
    pnode *head = &temp;
    char function;
    char c;
    int src = 0;
    int numOfNodes = 0;

    while (scanf("%c", &function) != EOF)
    {
        if (function == 'A')
        {
            //if the graph exsites- delete it
            deleteGraph_cmd(head);
            // printf("enter num of verticals:\n");
            scanf("%d", &numOfNodes);
            *head = build_graph_cmd(numOfNodes);

            scanf("%c", &c); //space

             while (scanf("%c", &c) != 0) //0
            {
                if (c == 'n')
                {
                    scanf("%d", &src);
                    insertNodeToGraph(head, src);
                }
                else
                {
                    break;
                }
            }
            function = c;
        }
        if (function == 'B')
        {
            insert_node_cmd(head);
            continue;
        }
        if (function == 'D')
        {
            delete_node_cmd(head);
            continue;
        }
        if (function == 'S')
        {
            int src = -1, dest = -1;
            scanf("%d %d", &src, &dest);
            int dis = shortsPath_cmd(*head, src, dest);
            printf("Dijsktra shortest path: %d \n", dis);
        }
        if (function == 'T')
        {
            TSP_cmd(*head);
            continue;
        }
    }
    deleteGraph_cmd(head);
    return 0;
}