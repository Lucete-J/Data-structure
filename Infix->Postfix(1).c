#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BUF_SIZE 100
#define RETURN_FAILURE -1

char infix[MAX_BUF_SIZE];
char postfix[MAX_BUF_SIZE];

char stack[MAX_BUF_SIZE];
int top = -1;

void push(char element)
{
    if (top >= MAX_BUF_SIZE - 1) {
        fprintf(stderr, "Stack Full.\n");
        exit(EXIT_FAILURE);
    }
    stack[++ top] = element;
}

char pop()
{
    if (top == -1) {
        fprintf(stderr, "Stack Empty.\n");
        exit(EXIT_FAILURE);
    } 
    return stack[top --];
}

int precedence(char ch)
{
    switch (ch) {
        case '(' : case ')' : return 0;
        case '+' : case '-' : return 12;
        case '*' : case '/' : return 13;
    }
    return RETURN_FAILURE;
}

void infix2postfix(char * infix, char * postfix)
{
    char token, top_element;
    int i, pos = 0;

    for (i = 0 ; i < strlen(infix) ; i ++) {
        token = infix[i];
        if (token == '(') push(token);
        else if (token == ')') {
            top_element = pop();
            while (top_element != '(') {
                postfix[pos ++] = top_element;
                top_element = pop();
            }
        } else if (token == '+' || token == '-' || token == '*' || token == '/') {
            while (precedence(token) <= precedence(stack[top]) && top != -1) {
                postfix[pos ++] = pop();
            }
            push(token);
        } else {
            if (token != '\n')
            postfix[pos ++] = token;
        }
    }
    while (top != -1) {
        postfix[pos ++] = pop();
    }
    top = -1;
}

int main(void)
{
    int i;

    fgets(infix, MAX_BUF_SIZE, stdin);
    infix2postfix(infix, postfix);
    printf("Infix formula : %s", infix);
    printf("Postfix formula : %s\n", postfix);

    return 0;
}
