#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef struct ListNode {
    int age;
    char * name;
    struct ListNode * next;
}ListNode;

void init(ListNode ** head);
void display(char * str, ListNode * head);
void insert(ListNode ** head, char * str, int age);
void delete(ListNode ** head, char * str);
void getAge(ListNode * head, char * str);

int i = 1;

int main(void)
{   
    ListNode * head = NULL;

    init(&head);

    display("List = ", head);
    insert(&head, "홍길동", 20);
    insert(&head, "김길동", 30);
    insert(&head, "최길동", 15);
    display("List = ", head);

    getAge(head, "홍길동");

    delete(&head, "홍길동");
    display("List = ", head);
    getAge(head, "홍길동");
    getAge(head, "최길동");

    return 0;
}


void insert(ListNode ** head, char * str, int age)
{
    ListNode * newNode, * cur;
    newNode = (ListNode *)malloc(sizeof(*newNode));
    newNode->name = (char *)malloc(sizeof(char));
    strcpy(newNode->name, str);
    newNode->age = age;
    newNode->next = NULL;
    if (*head== NULL) {
        *head = newNode;
    } else {
        cur = *head;
        while (cur->next != NULL) cur = cur->next;
        cur->next = newNode;
    }
}

void init(ListNode ** head)
{
    head = (ListNode **)malloc(sizeof(**head));
}

void display(char * str, ListNode * head)
{
    ListNode * cur = head;
    printf("%s() -> %s", __func__, str);
    if (head == NULL) printf("EMPTY\n");
    else {
        while (cur != NULL) {
            printf("%s(%d) ", cur->name, cur->age);
            cur = cur->next;
        }
        printf("\n");
    }
}


void delete(ListNode ** head, char * str)
{
    ListNode * cur = *head, * remove, * pre = *head;
    int check = 0, cnt = 0;
    while (cur != NULL) {
        if (strcmp(cur->name, str) == 0) {
            check = 1;
            break;
        }
        cur = pre;
        pre = pre->next;
        cnt ++;
    }
    if (!check) printf("%s은 현재 리스트에 없습니다.\n", str);
    else {
        if (cur == *head) {
            remove = cur;
            *head = (*head)->next;
        } else {
            remove = cur->next;
            cur->next = remove->next;
        }
        printf("%s이 삭제되었습니다.\n", remove->name);
        free(remove);   
    }
}

void getAge(ListNode * head, char * str)
{
    ListNode * cur = head;
    int check = 0;

    while (cur != NULL) {
        if (strcmp(cur->name, str) == 0) {
            check = 1;
            break;
        }
        cur = cur->next;
    }
    if (check) printf("%s의 나이는 %d세\n", cur->name, cur->age);
    else printf("%s은 현재 리스트에 없습니다.\n", str);
}

