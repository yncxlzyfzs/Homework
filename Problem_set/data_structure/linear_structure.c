#include <stdio.h>

void printN (int N)
{
    if (N)
    {
        printN (N-1);
        printf ("%d\n",N);
    }
}

int main ()
{
    int n;
    scanf ("%d",&n);
    printN (n);
    return 0;
}
