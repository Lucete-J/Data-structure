#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE -1
#define MAX_BUF_SIZE 8
#define MAX_NAME_SIZE 16

typedef struct {
    int age;
    char name[MAX_NAME_SIZE];
}DequeType;

DequeType deque[MAX_BUF_SIZE];
DequeType item;
int front = 0, rear = 0;

void deque_pro(int n);
void print_menu();
int is_empty();
int is_full();
void add_rear(DequeType item);
void add_front(DequeType item);
DequeType delete_rear();
DequeType delete_front();
void deque_size();
void print_deque();

int main(void)
{
    int menu;

    while (1) {
        print_menu();   
        printf("\nEnter the menu : ");
        scanf("%d", &menu);
        deque_pro(menu);
    }

    return 0;
}

void deque_pro(int n)
{
    switch (n) {
        case 1 :   
            printf("Enter the Name : ");
            scanf("%s", item.name);
            printf("Enter the Age : ");
            scanf("%d", &item.age);
            add_front(item);
            break;
        case 2 : 
            printf("Enter the Name : ");
            scanf("%s", item.name);
            printf("Enter the Age : ");
            scanf("%d", &item.age);
            add_rear(item);
            break;
        case 3 : 
            delete_front();
            break;
        case 4 : 
            delete_rear();
            break;
        case 5 : 
            deque_size();
            break;
        case 6 :
            print_deque();
            break;
        case 7 : 
            printf("Program is end.\n");
            exit(1);
        default :
            printf("Wrong Command.\n");
    }
}

void print_menu()
{
    printf("\n********** Deque Program **********\n");
    printf("\t<<<<<Program Menu>>>>>\n");
    printf("1. Add item (front)\n2. Add item (rear)\n3. Delete item (front)\n");
    printf("4. Delete item (rear)\n5. Printout Deque Size\n6. Printout all of element\n7. Exit Program\n");
}

int is_empty()
{
    return (front == rear);
}

int is_full()
{
    return ((rear + 1) % MAX_BUF_SIZE == front);
}

void add_rear(DequeType item)
{
    if (is_full()) {
        fprintf(stderr, "Deque is full.\n");
        exit(EXIT_FAILURE);
    }
    rear = (rear + 1) % MAX_BUF_SIZE;
    deque[rear] = item;
}

void add_front(DequeType item)
{
    if (is_full()) {
        fprintf(stderr, "Deque is full.\n");
        exit(EXIT_FAILURE);
    }
    deque[front] = item;
    front = (front - 1 + MAX_BUF_SIZE) % MAX_BUF_SIZE;
}

DequeType delete_rear()
{
    int pos_rear;
    pos_rear = rear;
    if (is_empty()) {
        fprintf(stderr, "Deque is empty.\n");
        exit(EXIT_FAILURE);
    }
    rear = (rear - 1 + MAX_BUF_SIZE) % MAX_BUF_SIZE;
    return deque[pos_rear];
}

DequeType delete_front()
{
    if (is_empty()) {
        fprintf(stderr, "Deque is empty.\n");
        exit(EXIT_FAILURE);
    }
    front = (front + 1) % MAX_BUF_SIZE;
    return deque[front];
}

void deque_size()
{
    int size, cnt = 0, i;

    if (front > rear) {
        for (i = front + 1 ; i < MAX_BUF_SIZE ; i ++) cnt ++;
        for (i = 0 ; i <= rear ; i ++) cnt ++;
    } else if (front < rear) {
        for (i = front + 1 ; i <= rear ; i ++) cnt ++;
    } else cnt = 0;
    printf("Deque size is %d.\n", cnt);
}

void print_deque()
{
    int i;

    if (front > rear) {
        for (i = front + 1 ; i < MAX_BUF_SIZE ; i ++) printf("Name : %s Age : %d\n", deque[i].name, deque[i].age);
        for (i = 0 ; i <= rear ; i ++) printf("Name : %s Age : %d\n", deque[i].name, deque[i].age);
    } else if (front < rear) {
        for (i = front + 1 ; i <= rear ; i ++) printf("Name : %s Age : %d\n", deque[i].name, deque[i].age);
    } else printf("Deque is empty.\n");
}
