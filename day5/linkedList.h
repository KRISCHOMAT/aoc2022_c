struct Node{
    char data;
    struct Node* next;
};

struct Node* initNode(char data); 

void addNode(struct Node** list, char data);

struct Node* findNode(struct Node* list, char data);

void printList(const struct Node* head);

void freeList(struct Node* head);

struct Node* removeHead(struct Node** list);

void prependNode(struct Node** list, struct Node* node);

void removeFromList(struct Node** target, struct Node** list, int amount);