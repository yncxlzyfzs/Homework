#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void ErrorReport ();

int main (int argc, char *argv[])
{
    Queue q = NULL;
    Status status;
    Elemtype e;
    int i;
    int op = 1;

    while (op)
    {
        system ("reset");
        printf("\n\n");
        printf("      Menu for Circular Queue On Sequence Structure \n");
        printf("-------------------------------------------------\n");
        printf("          1. Init       6. GetHead \n");
        printf("          2. Destroy    7. EnQueue\n");
        printf("          3. Clear      8. DeQueue \n");
        printf("          4. IsEmpty    9. Traversal\n");
        printf("          5. Length\n");
        printf("          0. Exit\n");
        printf("-------------------------------------------------\n");

        printf ("operation: ");
        scanf (" %d", &op);

        switch (op)
        {
            case 1:
                if (InitQueue (&q) == ABNORMAL)
                    ErrorReport ();
                else
                    printf ("Initializing succeeded.\n");
                printf ("Press Enter to continue...\n");
                getchar();
                getchar();
                break;
            case 2:
                status = DestroyQueue (&q);
                if (status == ABNORMAL)
                    ErrorReport ();
                else if (status == FALSE)
                    ErrorReport ();
                else
                    printf ("Destroying succeeded.\n");
                printf ("Press Enter to continue...\n");
                getchar();
                getchar();
                break;
            case 3:
                if (ClearQueue (q) == ABNORMAL)
                    ErrorReport ();
                else
                    printf ("Clear queue succeeded.\n");
                printf ("Press Enter to continue...\n");
                getchar();
                getchar();
                break;
            case 4:
                status = QueueEmpty (q);
                if (status == ABNORMAL)
                    ErrorReport ();
                else if (status == TRUE) printf ("Queue is empty.\n");
                else printf ("Queue is not empty.\n");
                printf ("Press Enter to continue...\n");
                getchar();
                getchar();
                break;
            case 5:
                i = QueueLength (q);
                if (i == ABNORMAL)
                    ErrorReport ();
                else
                    printf ("Queue's length is : %d\n", i);
                printf ("Press Enter to continue...\n");
                getchar();
                getchar();
                break;
            case 6:
                status = GetHead (q, &e);
                if (status == ABNORMAL)
                    ErrorReport ();
                else if(status == FALSE)
                    printf ("Queue is empty...\n");
                else
                    printf ("Head element is: %d\n", e);
                printf ("Press Enter to continue...\n");
                getchar();
                getchar();
                break;
            case 7:
                printf ("\n");
                printf ("Please input a element: ");
                scanf (" %d", &e);
                status = EnQueue (q, e);
                if (status == ABNORMAL)
                    ErrorReport ();
                else if (status == FALSE)
                    printf ("Queue is full.\n");
                else
                    printf ("EnQueue succeeded.\n");
                printf ("Press Enter to continue...\n");
                getchar();
                getchar();
                break;
            case 8:
                status = DeQueue (q, &e);
                if (status == ABNORMAL)
                    ErrorReport ();
                else if (status == FALSE)
                    printf ("Queue is empty.\n");
                else
                    printf ("DeQueue succeeded.Head element is: %d\n", e);
                printf ("Press Enter to continue...\n");
                getchar();
                getchar();
                break;
            case 9:
                status = QueueTraversal (q);
                if (status == ABNORMAL)
                    ErrorReport ();
                else if (status == FALSE)
                    printf ("Queue is empty.\n");
                else
                printf ("Press Enter to continue...\n");
                getchar();
                getchar();
                break;
            case 0:
                printf ("Press Enter to quit...\n");
                getchar();
                getchar();
                break;
            default:
                printf ("Input Error: Please Input a number between 0 and 9\n");
                printf ("Press Enter to continue...\n");
                getchar();
                getchar();
                break;
        }
    }

    return 0;
}

/*
    未初始化错误
 */
void ErrorReport ()
{
    printf ("Queue does not exist,please initialize first.\n");
}
