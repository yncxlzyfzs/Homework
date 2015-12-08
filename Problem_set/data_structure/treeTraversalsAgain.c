#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

void order (int *pre, int *in, int *post, int pre_head, int in_head, int post_head, int n)
{
    if (n == 0) return ;
    else if (n == 1)
    {
        post [post_head] = pre [pre_head];
        return ;
    }

    post [post_head+n-1] = pre [pre_head];

    //find two parts' head.
    int i=in_head;
    while (i<in_head+n && in [i] != pre [pre_head]) i++;

    order (pre, in, post, pre_head+1, in_head, post_head, i-in_head);
    order (pre, in, post, pre_head+i-in_head+1, i+1, post_head+i-in_head, n-i+in_head-1);
}

int main (int argc, char *argv[])
{
    char s[10];
    int node, n, i;

    scanf ("%d", &n);

    //initialize stack.
    int stack [n], pre[n], in[n];
    int top, pre_top, in_top;
    top = pre_top = in_top = -1;

    for (i=0; i<2*n; i++)
    {
        scanf ("%s", s);
        if (!strcmp (s, "Push")) 
        {
            if (top == n-1)
                return 0;

            scanf ("%d", &node);
            stack [++top] = node;
            pre [++pre_top] = node;
        }
        else if (!strcmp (s, "Pop"))
        {
            if (top == -1)
                return 0;

            in [++in_top] = stack [top--];
        }
        else
        {
            return 0;
        }

    }

    //create postorder traversal.
    int post [n];
    order (pre, in, post, 0, 0, 0, n);

    //print postorder traversal.
    for (i=0; i<n; i++)
    {
        if (i) printf (" %d", post [i]);
        else printf ("%d", post [i]);

        if (i == n-1) printf ("\n");
    }


    return 0;
}
