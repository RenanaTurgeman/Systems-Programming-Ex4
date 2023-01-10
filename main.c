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
                    insert_node_funcA_cmd(head, src);
                }
                else
                {
                    break;
                }
            }
            //print_graph(*head);
            function = c;

            //printf("\nend A func\n");

        }
        if (function == 'B')
        {
            //printf("\nstart B FUNC\n");
            insert_node_cmd(head);
            //print_graph(*head);
            continue;
        }
        if (function == 'D')
        {
            // printf("\nstart D FUNC\n");
            delete_node_cmd(head);
            // print_graph(*head);
            continue;
        }
        if (function == 'S')
        {
            // printf("\nstart S FUNC\n");
            int src = -1, dest = -1;
            scanf("%d %d", &src, &dest);
            int dis = shortsPath_cmd(*head, src, dest);
            printf("Dijsktra shortest path: %d \n", dis);
            //print_graph(*head);
        }
        if (function == 'T')
        {
            // printf("\nstart T FUNC\n");
            TSP_cmd(*head);
            // print_graph(*head);
            continue;
        }
    }
    deleteGraph_cmd(head);
    return 0;
}