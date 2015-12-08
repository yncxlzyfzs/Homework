#include <stdio.h>
#include <stdlib.h>

#define maxTreeSize 1024

int sample [maxTreeSize];
int testData [maxTreeSize];

void createTree (int *tree, int maxSize)
{
    int i, j, root, node;
    
    scanf ("%d", &root);
    tree [1] = root;

    for (i=1; i<maxSize; i++)
    {
        scanf ("%d", &node);

        j=1;
        while (tree [j] != -1)
        {
            if (node < tree [j]) j *= 2;
            else if (node > tree [j]) j = j*2+1;
        }

        tree [j] = node;
    }
}

int main (int argc, char *argv[])
{
    int maxSize, n, result;
    int i, j;

    while (scanf ("%d", &maxSize) != 0 && maxSize != 0)
    {
        scanf ("%d", &n);

        //initialize trees.
        for (j=0; j<maxTreeSize; j++) sample [j] = -1;

        //create sample tree.
        createTree (sample, maxSize);

        for (i=0; i<n; i++)
        {
            result = 1;
            //initialize old testData.
            for (j=0; j<maxTreeSize; j++) testData [j] = -1;

            //create new testData.
            createTree (testData, maxSize);

            //compare two trees.
            for (j=0; j<maxTreeSize; j++)
                if (sample [j] != testData [j]) result = 0;

            if (result) printf ("Yes\n");
            else printf ("No\n");
        }
    }

    return 0;
}
