#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE -1
#define MAX_NAME_SIZE 32

typedef struct {
    int id;
    char name[MAX_NAME_SIZE];
}element;

element * queue;
element item;
int capacity = 2;
int front = 0, rear = 0;


void copy(element * queue, element * new_queue)
{
    int i, pos = 1;
    if (rear == 0) {
        for (i = 1 ; i < capacity ; i ++) new_queue[pos ++] = *(queue + i);
    } else if (rear == capacity - 1) {
        for (i = 0 ; i < capacity - 1 ; i ++) new_queue[pos ++] = *(queue + i);
    } else {
        for (i = rear + 1 ; i < capacity ; i ++) new_queue[pos ++] = *(queue + i);
        for (i = 0 ; i < rear ; i ++) new_queue[pos ++] = *(queue + i);
    }
}

void queue_full()
{
    element * new_queue;

    new_queue = (element *)malloc(sizeof(element) * capacity * 2);
    copy(queue, new_queue);
    
    rear = capacity;
    front = 0;
    capacity *= 2;
    free(queue);
    queue = new_queue;
    queue[rear] = item;
}


void enqueue(element * q, element item)
{
    rear = (rear + 1) % capacity;
    if (front == rear) {
        printf("Queus is full.\n");
        printf("Size Up!!\n");
        queue_full();
    }
    q[rear] = item;
}

element dequeue(element * q)
{
    if (front == rear) {
        printf("Queue empty.\n");
    }
    front = (front + 1) % capacity;
    return q[front];
}

void print_front(element * q)
{
    printf("ID : %d, Name : %s\n", q[(front + 1) % capacity].id, q[(front + 1) % capacity].name);
}

void print_back(element * q)
{
    printf("ID : %d, Name : %s\n", q[rear].id, q[rear].name);
}

void queue_size()
{
    int size;
    if (front > rear) {
        size = (capacity - 1 - front) + rear;
    } else if (front < rear) {
        size = rear - front;
    } else {
        size = 0;
    }
    printf("Queue size is %d\n", size);
}

void print_menu()
{
    printf("********** Circular Queue (Memory Allocation) **********\n");
    printf("\t\t<<< Menu >>>\n");
    printf("\t1. Add Queue \n\t2. Delete Queue \n\t3. PrintOut front element \n\t4. PrintOut back element \n");
    printf("\t5. PrintOut number of element in Queue\n\t6. PrintOut all of Queue element \n\t7. Exit Program\n");
}

void print_queue()
{
    int i = 0;
    if (front > rear) {
        for (i = front + 1 ; i < capacity ; i ++) printf("ID : %d, Name : %s\n", queue[i].id, queue[i].name);
        for (i = 0 ; i <= rear ; i ++) printf("ID : %d, Name : %s\n", queue[i].id, queue[i].name);
    }else {
        for (i = front + 1 ; i <= rear ; i ++) printf("ID : %d, Name : %s\n", queue[i].id, queue[i].name);
    }
}

void queue_pro(int n)
{
    switch (n) {
        case 1 : 
            printf("Enter the ID : ");
            scanf("%d", &item.id);
            printf("Enter the Name : ");
            scanf("%s", item.name);
            enqueue(queue, item);
            break;
        case 2 : 
            if (front == rear) {
                printf("Queue is empty.\n");
                break;
            }
            dequeue(queue);
            break;
        case 3 :
            if (front == rear) {
                printf("Queue is empty.\n");
                break;
            } else print_front(queue);
            break;
        case 4 :
            if (front == rear) {
                printf("Queue is empty.\n");
                break;
            } else print_back(queue);
            break;
        case 5 : 
            queue_size();
            break;
        case 6 :
            if (front == rear) {
                printf("Queue is empty.\n");
                break;
            } else print_queue();
            break;
        case 7 : 
            printf("********************* Exit Program *********************\n");
            exit(-1);
        default : 
            printf("Wrong Command.\n");
    }
}


int main(void)
{
    int menu;
    queue = (element *)malloc(sizeof(element) * capacity);
    while (1) {
        print_menu();
        printf("Enter the menu : ");
        scanf("%d", &menu);
        queue_pro(menu);
    }
    return 0;
}
