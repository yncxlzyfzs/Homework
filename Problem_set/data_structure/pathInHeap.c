#include <stdio.h>
#include <stdlib.h>
#define MIN_NUM -10000

int main (int argc, char *argv[])
{
    int n, m;
    scanf ("%d %d", &n, &m);
    
    //create heap.
    int heap [n+1];
    heap [0] = MIN_NUM;

    //insert numbers.
    int i, pos, num;
    for (i=1; i<=n; i++)
    {
        pos = i;
        scanf ("%d", &num);

        while (num < heap [pos/2])
        {
            heap [pos] = heap [pos/2];
            pos /= 2;
        }

        heap [pos] = num;
    }

    //print paths.
    for (i=0; i<m; i++)
    {
        scanf ("%d", &pos);

        printf ("%d", heap [pos]);
        pos /= 2;
        while (pos)
        {
            printf (" %d", heap [pos]);
            pos /= 2;
        }

        printf ("\n");
    }

    return 0;
}
