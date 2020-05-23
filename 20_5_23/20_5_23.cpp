#include <stdio.h>

int main()
{
    union AB
    {
        int a;
        char b;
    }c;

    c.a = 1;
    if(c.b == 1)
    {
        printf("小端\n");
    }
    else
    {
        printf("大端\n");
    }
    return 0;
}