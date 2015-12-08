#include <stdio.h>

int main ()
{
    int n,i;
    scanf ("%d", &n);
    int seq[n];

    for (i=0; i<n; i++)
        scanf ("%d", seq+i);

    int sum = 0, result = 0, first = seq[0], last = seq[n-1];
    int start = 0, starter = first;
    for (i=0; i<n; i++)
    {
        sum += seq[i];

        if (sum == 0 && result == 0 && seq[i] == 0)
        {
            if (!start)
            {
                first = last = starter = seq[i];
                start = 1;
            }
            else
            {
                last = seq[i];
            }
        }

        if (!start && sum>=0)
        {
            starter = seq[i];
            start = 1;
        }

        if (sum > result)
        {
            first = starter;
            result = sum;
            last = seq[i];
        }
        else if (sum<0)
        {
            sum = 0;
            start = 0;
        }
    }

    printf ("%d %d %d\n", result, first, last);

    return 0;
}
