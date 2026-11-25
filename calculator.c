#include <stdio.h>
int main()
{
    int a,b;
    char op;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &op);
    if(op == '+')
        printf("%d + %d = %d\n", a, b, a + b);
    else if(op == '-')
        printf("%d - %d = %d\n", a, b, a - b);
    else if(op == '*')
        printf("%d * %d = %d\n", a, b, a * b);
    else if(op == '/')
        printf("%d / %d = %.2f\n", a, b, (float)a / b);
    else
        printf("Invalid operator!\n");
}