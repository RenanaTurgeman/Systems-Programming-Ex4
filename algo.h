#define INFINITY 999999999

typedef struct Dijkstra {
    pnode node;
    int weight;
    int tag;
    struct Dijkstra *next;
} dijkstra, *pdijkstra;

int shortsPath_cmd(pnode head, int src , int dest);