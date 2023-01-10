#ifndef GRAPH_
#define GRAPH_
#define INFINITY 999999999

typedef struct GRAPH_NODE_ *pnode;;

typedef struct edge_ {
    int weight;
    pnode endpoint;
    struct edge_ *next;
} edge, *pedge;


typedef struct GRAPH_NODE_ {
    int node_num;
    pedge edges;
    struct GRAPH_NODE_ *next;
} node, *pnode;

typedef struct Dijkstra {
    pnode node;
    int weight;
    int tag;
    struct Dijkstra *next;
} dijkstra, *pdijkstra;


typedef struct node {
    int id;
    int tag;
    struct node *next;
} Node;


pnode build_graph_cmd(int numOfNodes);
void printGraph_cmd(pnode head); //for self debug
void deleteGraph_cmd(pnode *head);

int shortsPath_cmd(pnode head, int src , int dest);
void TSP_cmd(pnode head);

void add_edge(pnode newNode, int dest, int weight, pnode *head);
void free_edges(pnode tmpNode);

void createNewNode();
void deleteNode(int);
int char_to_int(char);

Node *Node_alloc(int data, Node *next);
void Node_free(Node *node);
void delete_node_cmd(pnode *head);
void insert_node_cmd(pnode *head);
pnode getNode(int id, pnode *head);

void delete_edge(pnode *head, int nodeId);
void insert_node_funcA_cmd(pnode *head, int src);


#endif
