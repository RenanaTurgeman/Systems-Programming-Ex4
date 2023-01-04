void createNewNode();
void deleteNode(int);
int char_to_int(char);

typedef struct node {
    int id;
    int tag;
    struct node *next;
} Node;

Node *Node_alloc(int data, Node *next);
void Node_free(Node *node);
