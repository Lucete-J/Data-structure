#include <stdio.h>

#define MAX_BUF_SIZE 100

// Precedence enum
typedef enum {lparen, rparen, plus, minus, times, divide, eos, operand} precedence;

// In stack precedence
static int isp[] = {0, 19, 12, 12, 13, 13, 0};
// In coming precedence
static int icp[] = {20, 19, 12, 12, 13, 13, 0};

char expr[MAX_BUF_SIZE];
precedence stack[MAX_BUF_SIZE];
int top = -1;

// Infix formula -> Postfix formula
void postfix()
{
    precedence cur;
    char token;
    int n = 0;

    // Push end of string (스택의 맨 밑에 eos을 넣어서 pop()함수의 제한을 검)
    push(eos);
    // If cur is not eos, execute while loop
    while ((cur = getToken(&token, &n)) != eos) {
        // If cur is operand(A, B ...) printout
        if (cur == operand) printf("%c", token);
        else if (cur == rparen) {               // if cur is right paren(')'), execute pop function
            while (stack[top] != lparen) 
                printf("%c", precedence2char(pop()));
            pop();  
        }
        else {                                  // if cur is operator (+, /, +, -), printout
            while (isp[stack[top]] >= icp[cur]) 
                printf("%c", precedence2char(pop()));
            push(cur);
        }
    }
    // Pop what's left on the stack
    while ((cur = pop()) != eos)
        printf("%c", precedence2char(cur));
    // Initialize the stack
    top = -1;
}

// Get token and return precedence
precedence getToken(char *token, int *n)
{
    *token = expr[(*n)++];
    switch (*token) {
        case '(': return lparen;
        case ')': return rparen;
        case '+': return plus;
        case '-': return minus;
        case '*': return times;
        case '/': return divide;
        case '\0': return eos;
        default: return operand;
    }
}

// push function
void push(precedence item)
{
    // Error handling is omitted to reduce the length of the code
    stack[++top] = item;
}

// pop function
precedence pop()
{
    // Error handling is omitted to reduce the length of the code
    return stack[top --];
}

// Exchange precedence -> char
char precedence2char(precedence item)
{
    switch (item) {
        case lparen: return '(';
        case rparen: return ')';
        case plus: return '+';
        case minus: return '-';
        case times: return '*';
        case divide: return '/';
    }
    return '\0';
}

// main function
int main(void)
{
    // Enter the formula 
    scanf("%s", expr);
    postfix();

    // if main function execution clear return 0
    return 0;
}
