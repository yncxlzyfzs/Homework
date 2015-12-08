#include <stdio.h>
#include <stdlib.h>

int ctoi (char c)
{
    if (c == '-') return -1;
    return c-'0';
}

int main (int argc, char *argv[])
{
    int n1, n2, i, j;
    int error = 0;
    
    scanf ("%d", &n1);
    char list1[n1+1][3];

    for (i=0; i<n1; i++)
        for (j=0; j<3; j++)
            scanf (" %c", &list1[i][j]);
    list1[n1][0] = '-';

    scanf ("%d", &n2);
    char list2[n2+1][3];

    for (i=0; i<n2; i++)
        for (j=0; j<3; j++)
            scanf (" %c", &list2[i][j]);
    list2[n2][0] = '-';

    //have different node number.
    if (n2 != n1) 
    {
        printf ("No\n");
        return 0;
    }


    for (i=0; i<n2; i++)
    {
        for (j=0; j<n1; j++)
        {
            if (list1[j][0] == list2[i][0]) break;
        }

        //node not found.
        if (j==n1 && list1[j][0] != list2[i][0])
        {
            error = 1;
            break;
        }

        int list1_l = ctoi (list1[j][1]);
        int list1_r = ctoi (list1[j][2]);
        int list2_l = ctoi (list2[i][1]);
        int list2_r = ctoi (list2[i][2]);

        if (list1_l == -1) list1_l = n1;
        if (list1_r == -1) list1_r = n1;
        if (list2_l == -1) list2_l = n2;
        if (list2_r == -1) list2_r = n2;

        if (list2[list2_l][0] == list1[list1_l][0])
        {
            if (list2[list2_r][0] == list1[list1_r][0]) continue;
        }
        else if (list2[list2_l][0] == list1[list1_r][0])
        {
            if (list2[list2_r][0] == list1[list1_l][0]) continue;
        }

        error = 1;
        break;
    }

    if (error) printf ("No\n");
    else printf ("Yes\n");

    return 0;
}
