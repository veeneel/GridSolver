#include <stdio.h>
#include <limits.h>

unsigned int factorial(unsigned char x)
{
    unsigned int result = x;
    while (x > 1)
    {
        x--;
        unsigned int result2 = result * x;
        if (result2 < result)
        {
            printf("Aritmetic Overflow\n");
            result = -1;
        }
        else
            result = result2;
    }

    return result;
}

unsigned int factorial_r(unsigned char x)
{
    unsigned int result = 0;
    if (x == 1)
        result = 1;
    else
    {
        unsigned int prev = factorial_r(x - 1);
        result = x * factorial_r(x - 1);
        if (result < prev)
        {
            printf("Aritmetic Overflow\n");
            result = -1;
        }
    }

    return result;
}

void main(void)
{
    unsigned char x = 5;

    for (int i = 0; i < 20; ++i)
    {
        unsigned int y = factorial(i);
        printf("%d! = %d\n", i, y);
        if ((int)(y) < 0) break;
    }
}
