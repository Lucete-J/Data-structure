#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p, s) \
if (!((p) = malloc(s))) {\
fprintf(stderr, "Insufficient memory");\
exit(EXIT_FAILURE);\
}

#define MAX_QUEUE_SIZE 10

typedef struct list * listPointer;
typedef struct list {
    int data;
    listPointer link;
} Node;

typedef struct queue * queuePointer;
typedef struct queue {
    listPointer nodelink;
    queuePointer queuelink;
} queue;

queuePointer top[MAX_QUEUE_SIZE];
int cnt = 0;
int tmp = 0;

void printList(listPointer ptr);
listPointer createNode(int data, listPointer link);
void addQueue(queuePointer top[], listPointer list);
listPointer deleteQueue();

int main(void)
{
    listPointer ptr1, ptr2, ptr3;

    printf("Linked queue\n");

    ptr1 = createNode(10, createNode(20, createNode(30, createNode(40, NULL))));
    ptr2 = createNode(100, createNode(200, createNode(300, createNode(400, NULL))));
    addQueue(top, ptr1);
    addQueue(top, ptr2);

    ptr3 = deleteQueue();

    printList(ptr3);

    return 0;
}

listPointer createNode(int data, listPointer link)
{
    listPointer ptr;

    MALLOC(ptr, sizeof(*ptr));
    ptr->data = data;
    ptr->link = link;

    return ptr;
}

void addQueue(queuePointer top[], listPointer list)
{
    MALLOC(top[cnt], sizeof(*top[cnt]));
    MALLOC(top[cnt + 1], sizeof(*top[cnt + 1]));
    top[cnt]->nodelink = list;
    top[cnt]->queuelink = top[++ cnt];
}

listPointer deleteQueue()
{
    listPointer front;

    front = top[tmp]->nodelink;
    top[tmp]->nodelink = NULL;
    top[tmp]->queuelink = NULL;

    free(top[tmp ++]);
    
    return front;
}

void printList(listPointer ptr)
{
    int i;
    while (ptr->link != NULL) {
        printf("%d", ptr->data);
        ptr = ptr->link;
    }
}
