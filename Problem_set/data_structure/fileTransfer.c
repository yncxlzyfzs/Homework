#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
    int n;
    scanf ("%d", &n);

    //create list.
    int list[n+1];

    //initialize list.
    int i;
    for (i=0; i<n+1; i++) list [i] = -1;

    //read command.
    char command;
    int root1,root2;
    while (scanf (" %c", &command) && command != 'S')
    {
        scanf ("%d %d", &root1, &root2);
        while (list [root1] != -1)
        {
            if (list [list [root1]] != -1)
                list [root1] = list [list [root1]];
            root1 = list [root1];
        }

        while (list [root2] != -1)
        {
            if (list [list [root2]] != -1)
                list [root2] = list [list [root2]];
            root2 = list [root2];
        }

        switch (command)
        {
            case 'C':
                if (root1 == root2) printf ("yes\n");
                else printf ("no\n");
                break;
            case 'I':
                list [root2] = root1;
                break;
            default :
                return 0;
        }
    }

    //count components.
    int components = 0;
    for (i=1; i<n+1; i++)
        if (list [i] == -1) components++;
    if (components == 1) printf ("The network is connected.\n");
    else printf ("There are %d components.\n", components);

    return 0;
}
