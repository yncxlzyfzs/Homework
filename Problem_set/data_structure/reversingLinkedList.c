#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    int address;
    int data;
    int next_address;
    struct list *next;
}List;

int testEnd (int n, List *list)
{
    int i=0;
    while (list && i<n)
    {
        list = list->next;
        i++;
    }

    if (i == n && list)
        return 1;
    else
        return 0;
}

List *reverse (int n, List *list)
{
    List *new, *old, *tmp;
    new = list->next;
    old = new->next;

    int i;
    for (i=1; i<n; i++)
    {
        tmp = old->next;
        old->next = new;
        old->next_address = new->address;
        new = old;
        old = tmp;
    }
    if (new)
    {
        list->next_address = new->address;
    }
    else
    {
        list->next_address = -1;
    }

    list->next->next = old;
    if (old)
    {
        list->next->next_address = old->address;
    }
    else
    {
        list->next->next_address = -1;
    }

    return new;
}

void printList (List *list)
{
    while (list->next)
    {
        list = list->next;
        if (list->next_address == -1)
        {
            printf ("%05d %d %d\n", list->address, list->data, list->next_address);
        }
        else
        {
            printf ("%05d %d %05d\n", list->address, list->data, list->next_address);
        }
    }
}

int main ()
{
    int first_address, max, reverse_num;
    scanf ("%d %d %d", &first_address, &max, &reverse_num);

    List *inputp, *headp, *current_list, *tmp_list;
    inputp = (List *) malloc (sizeof (List));
    headp = (List *) malloc (sizeof (List));
    
    int i;
    current_list = inputp;
    for (i=0; i<max; i++)
    {
        current_list->next = (List *) malloc (sizeof (List));
        current_list = current_list->next;
        scanf ("%d %d %d", &current_list->address, &current_list->data, &current_list->next_address);
        current_list->next = NULL;
    }

    //order
    current_list = headp;
    tmp_list = inputp;
    do
    {
        current_list->next = NULL;

        if (first_address == -1)
        {
            break;
        }

        tmp_list = inputp;
        for (i=0; i<max; i++)
        {
            if (tmp_list->next->address == first_address)
            {
                current_list->next = tmp_list->next;
                tmp_list->next = tmp_list->next->next;;
                current_list->next->next = NULL;
                break;
            }

            tmp_list = tmp_list->next;;
        }

        current_list = current_list->next;
        first_address = current_list->next_address;
    }
    while (current_list->next_address != -1);

    current_list = headp;
    while (testEnd (reverse_num, current_list))
    {
        current_list->next = reverse (reverse_num, current_list);
        for (i=0; i<reverse_num; i++)
            current_list = current_list->next;
    }

    printList (headp);

    return 0;
}
