#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define MAX_SIZE 128

typedef struct ListNode {
    int age;
    char * name;
    struct ListNode * next;
} ListNode;

void printMenu();
void init(ListNode ** head);
ListNode* makeNode(ListNode * head, char * name, int age);
void insertPos(ListNode * head, ListNode * node, int pos);
void insertNode(ListNode * head, char * name, int age);
void printList(ListNode * head);
ListNode* findNode(ListNode * head, char * name);
void delete(ListNode * head, char * name);
void modifyNode(ListNode * head, char * name);

int debug = 1;

int main(void)
{
    ListNode * head = NULL;
    int loop = TRUE, menu, inputAge;
    char inputName[MAX_SIZE];

    init(&head);

    while (loop) {
        printMenu();
        scanf("%d", &menu);
        getchar();
        switch (menu) {
        case 1 :
            printf("Enter the name : ");
            fgets(inputName, MAX_SIZE, stdin);
            inputName[strlen(inputName) - 1] = '\0';
            printf("Enter the age : ");
            scanf("%d", &inputAge);
            insertNode(head, inputName, inputAge);
            break;
        case 2 :
            printf("Enter the name : ");
            fgets(inputName, MAX_SIZE, stdin);
            inputName[strlen(inputName) - 1] = '\0';
            delete(head, inputName);
            break;
        case 3 :
            printList(head);
            break;
        case 4 :
            printf("Enter the name : ");
            fgets(inputName, MAX_SIZE, stdin);
            inputName[strlen(inputName) - 1] = '\0';
            modifyNode(head, inputName);
            break;
        case 5 :
            printf("Exit program!!\n");
            loop = FALSE;
            break;
        default : 
            printf("Wrong input!!\n");
    }

    }

    return 0;
}

void printMenu()
{
    printf("<<<<<< MENU >>>>>>\n");
    printf("1. Insert Node\n2. Delte Node\n3. Print Out List\n4. Modified Node Info\n5. Exit\n");
    printf("Enter the menu : ");
}

void init(ListNode ** head)
{
    (*head) = (ListNode *)malloc(sizeof(ListNode));
    (*head)->age = 0;
    (*head)->name = NULL;
    (*head)->next = NULL;
}

ListNode* makeNode(ListNode * head, char * name, int age)
{
    ListNode * node = (ListNode *)malloc(sizeof(ListNode));
    node->name = (char *)malloc(sizeof(strlen(name) + 1));
    strcpy(node->name, name);
    node->age = age;
    node->next = NULL;

    return node;
}

void insertPos(ListNode * head, ListNode * node, int pos)
{
    ListNode * cur = head;
    int cnt = 0;
    while (cnt != pos) {
        if (cur->next == NULL) {
            printf("Wrong Command. Insert Last!!\n");
            break;
        }
        cur = cur->next;
        cnt ++;
    }
    if (cnt == pos) {
        node->next = cur->next;
        cur->next = node;
    } else cur->next = node;
}

void insertNode(ListNode * head, char * name, int age)
{
    int pos;
    ListNode * newNode = makeNode(head, name, age);

    printf("Enter the position : ");
    scanf("%d", &pos);
    insertPos(head, newNode, pos);
}

void printList(ListNode * head)
{
    ListNode * cur = head;
    printf("<<<<< Print List >>>>>\n");
    if (head->next == NULL) {
        printf("EMPTY\n");
        return;
    }
    for (cur = head->next ; cur->next != NULL ; cur = cur->next) {
        printf("%s -> ", cur->name);
    }
    printf("%s", cur->name);
    printf("\n");
}

ListNode* findNode(ListNode * head, char * name)
{
    ListNode * cur = head;
    if (head->next == NULL) return NULL;
    for (cur = head->next ; cur != NULL ; cur = cur->next) {
        if (strcmp(cur->name, name) == 0) return cur;
    }
    return NULL;
}

void delete(ListNode * head, char * name)
{
    ListNode * posNode = findNode(head, name);
    ListNode * cur = head;

    if (posNode == NULL) printf("%s is not exist.\n", name);
    else {
        while (cur->next != posNode) cur = cur->next;
        cur->next = posNode->next;
        posNode->next = NULL;
        printf("%s is delete.\n", name);
        free(posNode);
    }
}

void modifyNode(ListNode * head, char * name)
{
    int modifyAge;
    char modifyName[MAX_SIZE];
    ListNode * posNode = findNode(head, name);
    if (posNode == NULL) printf("%s is not exist.\n", name);
    else {
        printf("Enter the new age : ");
        scanf("%d", &modifyAge);
        getchar();
        printf("Enter the new name : ");
        fgets(modifyName, MAX_SIZE, stdin);
        modifyName[strlen(modifyName) - 1] = '\0';
        strcpy(posNode->name, modifyName);
        printf("Modified Complete!!\n");
    }
}
