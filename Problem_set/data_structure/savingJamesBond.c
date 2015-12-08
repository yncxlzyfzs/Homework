#include <stdio.h>
#include <stdlib.h>
#define islandDiameter 15

typedef struct dot
{
    int x;
    int y;
    int visited;
}Dot;

int jumpLength;



int jumpable (Dot *startDot, Dot *aimDot)
{
    return 0;
}

int canBeSaved (Dot *dots[], int n)
{
    //test first jump.
    if (jumpLength+islandDiameter/2 >= 50) return 1;
    Dot *tmpDots[n];
    int i;
    for (i=0; i<n; i++) tmpDots[i] = NULL;

    Dot *origin;                                    //set origin.
    origin = (Dot *) malloc (sizeof (Dot));
    origin->x = origin->y = 0;
    origin->visited = 1;

    int j=0;                            //find first jump reachable dots.
    for (i=0; i<n; i++)
        {
            if (jumpable (origin, dots[i]))
                tmpDots[j++] = dots[i];
        }

    //test following jumps.
}

int main (int argc, char *argv[])
{
    int n, i;
    scanf ("%d %d", &n, &jumpLength);

    //initialize dots.
    Dot *newDot, *dots[n];
    for (i=0; i<n; i++)
    {
        newDot = (Dot *) malloc (sizeof (Dot));
        scanf (" %d %d", &newDot->x, &newDot->y);
        newDot->visited = 0;

        dots[i] = newDot;
    }

    //judge if he can be saved.
    if (canBeSaved (dots, n)) printf ("Yes\n");
    else printf ("No\n");

    return 0;
}
