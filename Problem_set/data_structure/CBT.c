#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_NUM 2000
#define MIN(X, Y) (X)<(Y)?(X):(Y)

int *tree, *list;

//bubble sort.
void sort (int n)
{
    int i, j, tmp;
    for (i=n-1; i>0; i--)
        for (j=0; j<i; j++)
            if (list [j] > list [j+1])
            {
                //swap
                tmp = list [j];
                list [j] = list [j+1];
                list [j+1] = tmp;
            }
}

int getLeftNum (int n)
{
    int h, x;
    
    //get layer.
    h = (int)(log(n+1)/log(2));
    x = n-pow (2, h)+1;

    return pow (2, h-1)-1+(MIN (pow (2, h-1), x));
}

void insertion (int TLeft, int TRight, int root)
{
    int n, left_num, root_num;
    n = TRight - TLeft + 1;

    //stop mark.
    if (n == 0) return;

    left_num = getLeftNum (n);
    tree [root] = list [TLeft + left_num];

    //create subtree.
    insertion (TLeft, TLeft+left_num-1, root*2+1);
    insertion (TLeft+left_num+1, TRight, root*2+2);

}

void createTree (int n)
{
    insertion (0, n-1, 0);
}

int main (int argc, char *argv[])
{
    int n, i;

    scanf ("%d", &n);
    list = (int *) malloc (sizeof (int) * n);
    tree = (int *) malloc (sizeof (int) * n);

    //get data.
    for (i=0; i<n; i++) scanf ("%d", list+i);

    //sort.
    sort (n);

    //create CBT.
    createTree (n);

    //print tree.
    for (i=0; i<n; i++)
    {
        if (!i) printf ("%d", tree [i]);
        else printf (" %d", tree [i]);
    }
    printf ("\n");

    return 0;
}
