#include <stdio.h>
#include <stdlib.h>
#include "linear_table.h"

Status InitialData (Table table);
Status SaveData (Table table);
void ErrorReport ();

int main (int argc, char *argv[])
{
    int op=1;
    int i, e, tmp_e;
    char name[NAME_LEN];
    List l = NULL;

    //初始化多线性表
    Table table;
    table = (Table) malloc (sizeof (struct Multi));
    table->length = 0;
    for (i=0; i<MAX_LIST; i++)
        table->lists[i] = NULL;

    Status status = InitialData (table);

    if (status == TRUE) ;
    else
    {
        if (status == ABNORMAL) 
            printf ("Initailize data failed.\n");
        else
            printf ("Data is not exist.\n");
        printf ("Press Enter to open a new table...\n");
        getchar();
    }

    while (op)
    {
        system ("reset");
        printf("\n\n");
        printf("      Menu for Linear Table On Sequence Structure \n");
        printf("-------------------------------------------------\n");
        printf("          1. IntiaList       7. LocateElement\n");
        printf("          2. DestroyList     8. PriorElement\n");
        printf("          3. ClearList       9. NextElement \n");
        printf("          4. IsEmpty         10. Insert\n");
        printf("          5. Length          11. ListDelete\n");
        printf("          6. GetElement      12. Traversal\n");
        printf("          0. Exit\n");
        printf("-------------------------------------------------\n");

        printf ("operation: ");
        scanf ("%d", &op);


        if (table->length)
        {
            if (!op) ;
            else if (op == 1 && table->length < MAX_LIST)
            i = table->length;
            else if (op == 1 && table->length == MAX_LIST)
            {
                printf ("lists overflowed.\n");
                printf ("Press Enter to rechoose...\n");
                getchar();
                getchar();
                continue;
            }
            else
            {
                printf("-------------------------------------------------\n");
                printf ("Lists: \n");
                for (i=0; i<table->length; i++)
                    printf ("\nlist %d: %s\n\n", i+1, table->lists[i]->name);
                printf ("choose a list: ");
                scanf ("%d", &i);
                if (i<1 || i>table->length)
                {
                    printf ("number overflowed.\n");
                    printf ("Press Enter to rechoose...\n");
                    getchar();
                    getchar();
                    continue;
                }
                else
                {
                    l = table->lists[i-1];
                }
                printf("-------------------------------------------------\n");
            }
        }
        else
        {
            l = NULL;
            i = 0;
        }

        switch (op)
        {
            case 1:
                printf ("please input list name: \n");
                scanf ("%s", name);
                if (InitaList (&(table->lists[i]), name) == ABNORMAL)
                    ErrorReport ();
                else
                {
                    printf ("Initializing succeeded.\n");
                    table->length++;
                }
                printf ("Press Enter to continue...\n");
                getchar();
                getchar();
                break;
            case 2:
                if (DestroyList (&l) == ABNORMAL)
                    ErrorReport ();
                else
                {
                    for (; i<=table->length; i++)
                        table->lists[i-1] = table->lists[i];
                    table->length--;
                    printf ("Destroying succeeded.\n");
                }
                printf ("Press Enter to continue...\n");
                getchar();
                getchar();
                break;
            case 3:
                if (ClearList (l) == ABNORMAL)
                    ErrorReport ();
                else
                    printf ("Clear list succeeded.\n");
                printf ("Press Enter to continue...\n");
                getchar();
                getchar();
                break;
            case 4:
                i = ListEmpty (l);
                if (i == ABNORMAL)
                    ErrorReport ();
                else if (i) printf ("List is empty.\n");
                else printf ("List is not empty.\n");
                printf ("Press Enter to continue...\n");
                getchar();
                getchar();
                break;
            case 5:
                i = ListLength (l);
                if (i == ABNORMAL)
                    ErrorReport ();
                else
                    printf ("List's length is : %d\n", i);
                printf ("Press Enter to continue...\n");
                getchar();
                getchar();
                break;
            case 6:
                printf ("\n");
                printf ("Please input element's position: ");
                scanf ("%d", &i);
                status = GetElem (l, i, &e);
                if (status == ABNORMAL)
                {
                    ErrorReport ();
                    printf ("Press Enter to continue...\n");
                    getchar();
                    getchar();
                }
                else if (status == FALSE)
                {
                    printf ("Getting element failed.\n");
                    printf ("Press Enter to continue...\n");
                    getchar();
                    getchar();
                }else
                {
                    printf ("%d: %d\n", i, e);
                    printf ("Press Enter to continue...\n");
                    getchar();
                    getchar();
                }
                break;
            case 7:
                printf ("\n");
                printf ("Please input element: ");
                scanf ("%d", &e);
                i = LocateElem (l, e);
                if (i == ABNORMAL)
                {
                    ErrorReport ();
                    printf ("Press Enter to continue...\n");
                    getchar();
                    getchar();
                }
                else if (i == 0)
                {
                    printf ("Getting element's position failed.\n");
                    printf ("Press Enter to continue...\n");
                    getchar();
                    getchar();
                }else
                {
                    printf ("%d's position is: %d\n", e, i);
                    printf ("Press Enter to continue...\n");
                    getchar();
                    getchar();
                }
                break;
            case 8:
                printf ("\n");
                printf ("Please input element: ");
                scanf ("%d", &e);
                status = PriorElem (l, e, &tmp_e);
                if (status == ABNORMAL)
                {
                    ErrorReport ();
                    printf ("Press Enter to continue...\n");
                    getchar();
                    getchar();
                }
                else if (tmp_e == MEANINGLESS)
                {
                    printf ("Getting prior element failed.\n");
                    printf ("Press Enter to continue...\n");
                    getchar();
                    getchar();
                }else
                {
                    printf ("%d's prior element is: %d\n", e, tmp_e);
                    printf ("Press Enter to continue...\n");
                    getchar();
                    getchar();
                }
                break;
            case 9:
                printf ("\n");
                printf ("Please input element: ");
                scanf ("%d", &e);
                status = NextElem (l, e, &tmp_e);
                if (status == ABNORMAL)
                {
                    ErrorReport ();
                    printf ("Press Enter to continue...\n");
                    getchar();
                    getchar();
                }
                else if (tmp_e == MEANINGLESS)
                {
                    printf ("Getting next element failed.\n");
                    printf ("Press Enter to continue...\n");
                    getchar();
                    getchar();
                }else
                {
                    printf ("%d's next element is: %d\n", e, tmp_e);
                    printf ("Press Enter to continue...\n");
                    getchar();
                    getchar();
                }
                break;
            case 10:
                printf ("\n");
                printf ("Please input position: ");
                scanf ("%d", &i);
                printf ("Please input element: ");
                scanf ("%d", &e);
                status = ListInsert (l, i, e);
                if (status == ABNORMAL)
                    ErrorReport ();
                else if (status == TRUE)
                    printf ("Inserting succeeded.\n");
                else
                    printf ("Inserting failed.\n");
                printf ("Press Enter to continue...\n");
                getchar();
                getchar();
                break;
            case 11:
                printf ("\n");
                printf ("Please input position: ");
                scanf ("%d", &i);
                status = ListDelete (l, i, &e);
                if (status == ABNORMAL)
                    ErrorReport ();
                else if (e != MEANINGLESS)
                    printf ("Deleting succeeded.\n");
                else
                    printf ("Deleting failed.\n");
                printf ("Press Enter to continue...\n");
                getchar();
                getchar();
                break;
            case 12:
                printf ("\n");
                status = ListTraversal (l);
                if (status == ABNORMAL)
                    ErrorReport ();
                printf ("\n");
                printf ("Press Enter to continue...\n");
                getchar();
                getchar();
                break;
            case 0:
                system ("reset");
                if (SaveData (table) == ABNORMAL)
                    printf ("Saving failed.\n");
                else
                    printf ("Saving succeeded.\n");
                printf ("Press Enter to quit...\n");
                getchar();
                getchar();
                break;
            default:
                printf ("Input Error: Please Input a number between 0 and 12\n");
                printf ("Press Enter to continue...\n");
                getchar();
                getchar();
                break;
        }
    }

    return 0;
}

/*
    加载数据
 */
Status InitialData (Table table)
{
    FILE *fp;
    int i, counter;

    if ((fp = fopen ("table.dat", "rb+")) == NULL)
        return ABNORMAL;
    if ((fread (&counter, sizeof (int), 1, fp)) == EOF)
    {
        fclose (fp);
        return FALSE;
    }
    else
    {
        table->length = counter;
        List l;
        for (i=0; i<counter; i++)
        {
            l = (List) malloc (sizeof (struct Node));
            fread (l, sizeof (struct Node), 1, fp);
            table->lists[i] = l;
        }
    }

    if (fclose (fp) != 0)
        return ABNORMAL;

    return TRUE;
}


/*
    加载数据
 */
Status SaveData (Table table)
{
    FILE *fp;
    int i;

    if ((fp = fopen("table.dat", "wb+")) == NULL)
        return ABNORMAL;
    if (table->length)
    {
        fwrite (&(table->length), sizeof (int), 1, fp);
        for (i=0; i<table->length; i++)
            fwrite (table->lists[i], sizeof (struct Node), 1, fp);
    }
    
    if (fclose (fp) != 0)
        return ABNORMAL;

    return TRUE;
}

/*
    未初始化错误
 */
void ErrorReport ()
{
            printf ("List does not exist,please initialize first.\n");
}
