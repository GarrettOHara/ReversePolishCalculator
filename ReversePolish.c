#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int stack[100];
int top = -1;

int isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}
int isFull()
{
    if (top == 100)
        return 1;
    else
        return 0;
}
int pop()
{
    int data;
    if(!isEmpty())
    {
        data = stack[top];
        top--;
        return data;
    }
    return 0;
}
int push (data)
{
    if (!isFull())
    {
        top++;
        stack[top] = data;
        return 0;
    }
    return 0;
}
int add(int a, int b)
{
    return a + b;
}
int sub(int a, int b)
{
    return a - b;
}
int mul(int a, int b)
{
    return a * b;
}
int divide(int a, int b)
{
    return a / b;
}
int main(int argc, char *argv[])
{
    printf("\n\nReverse Polish Stack instructions and operations availible:\n\n");
    printf("\t+ (Addition)\n");
    printf("\t- (Subtration)\n");
    printf("\tx (Multiplication)\n");
    printf("\t/ (Division)\n\n");
    printf("Please input Values so they adhere to a Stack stucture (\"last in first out\")\n");
    printf("EX:\n \t 1 2 - outputs 1\n \t 2 1 - outputs -1\n\n");
    if (argc > 3)
    {
        int i;
        for (i = 1; i < argc; i++)
        {
            char argument = *argv[i];
            int value;
            value = atoi(argv[i]);
            if ((isdigit(argument)) != 0)
            {
                push(value);
            }
            else
            {
                switch (argument)
                {
                    case '+':
                    {
                        push(add(pop(), pop()));
                        break;
                    }
                    case '-':
                    {
                        push(sub(pop(), pop()));
                        break;
                    }
                    case 'x':
                    {
                        push(mul(pop(), pop()));
                        break;
                    }
                    case '/':
                    {
                        push(divide(pop(), pop()));
                        break;
                    }
                    default:
                        break;
                }
            }
        }
        int ptr;
        ptr = pop();
        printf("Computation result: %d\n", ptr);
        return ptr;
    }
    else
    {
        printf("Not enough arguments passed for Reverse Polish Calculator to function\n");
        return -1;
    }
}