#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    int coefficient;
    int exponent;
    struct list *next;
}List;

int isEmpty (List *list)
{
    return list->next == NULL;
}

List *createList (int n)
{
    int i;
    List *list, *current_list;
    list = (List *) malloc (sizeof (List));
    current_list = list;

    //get polynomial
    for (i=0; i<n; i++)
    {
        current_list->next = (List *) malloc (sizeof (List));
        current_list = current_list->next;
        scanf ("%d %d", &current_list->coefficient, &current_list->exponent);
    }

    current_list->next = NULL;

    return list;
}

void freeList (List *list)
{
    List *tmp_list;
    while (list)
    {
        tmp_list = list->next;
        free (list);
        list = tmp_list;
    }
}

void printList (List *list)
{
    if (isEmpty (list))
    {
        printf ("0 0\n");
        return ;
    }

    list = list->next;
    printf ("%d %d", list->coefficient, list->exponent);

    while (list->next)
    {
        list = list->next;
        printf (" %d %d", list->coefficient, list->exponent);
    }

    printf ("\n");
}

List *addList (List *first_num, List *second_num)
{
    List *result, *current_list;
    List *current_first, *current_second;
    int coefficient;

    result = (List *) malloc (sizeof (List));
    current_list = result;
    current_first = first_num;
    current_second = second_num;

    if (!current_first->next)
    {
        while (current_second->next)
        {
            current_second = current_second->next;
            current_list->next = (List *) malloc (sizeof (List));
            current_list = current_list->next;

            *current_list = *current_second;
            current_list->next = NULL;
        }

        return result;
    }
    else if (!current_second->next)
    {
        while (current_first->next)
        {
            current_first = current_first->next;
            current_list->next = (List *) malloc (sizeof (List));
            current_list = current_list->next;

            *current_list = *current_first;
            current_list->next = NULL;
        }

        return result;
    }

    current_first = current_first->next;
    current_second = current_second->next;

    //add
    while (current_first && current_second)
    {

        if (current_first->exponent == current_second->exponent)
        {
            coefficient = current_first->coefficient+current_second->coefficient;
            if (!coefficient)
            {
                current_first = current_first->next;
                current_second = current_second->next;
                continue;
            }

            current_list->next = (List *) malloc (sizeof (List));
            current_list = current_list->next;
            current_list->coefficient = coefficient;
            current_list->exponent = current_first->exponent;
            current_list->next = NULL;
            current_first = current_first->next;
            current_second = current_second->next;
        }
        else if (current_first->exponent > current_second->exponent)
        {
            current_list->next = (List *) malloc (sizeof (List));
            current_list = current_list->next;
            *current_list = *current_first;
            current_list->next = NULL;
            current_first = current_first->next;
        }
        else
        {
            current_list->next = (List *) malloc (sizeof (List));
            current_list = current_list->next;
            *current_list = *current_second;
            current_list->next = NULL;
            current_second = current_second->next;
        }
    }

    if (!current_first)
    {
        while (current_second)
        {
            current_list->next = (List *) malloc (sizeof (List));
            current_list = current_list->next;
            *current_list = *current_second;
            current_list->next = NULL;
            current_second = current_second->next;
        }
    }
    else
    {
        while (current_first)
        {
            current_list->next = (List *) malloc (sizeof (List));
            current_list = current_list->next;
            *current_list = *current_first;
            current_list->next = NULL;
            current_first = current_first->next;
        }
    }

    return result;
}

List *multiplyList (List *first_num, List *second_num)
{
    List *result, *free_list, *tmp_list, *tmp_tmp_list, *current_list;
    List *current_first, *current_second;
    current_second = second_num;
    result = (List *) malloc (sizeof (List));
    result->next = NULL;

    int coefficient, exponent;
    while (current_second->next)
    {
        tmp_list = (List *) malloc (sizeof (List));
        tmp_tmp_list = tmp_list;
        current_second = current_second->next;
        coefficient = current_second->coefficient;
        exponent = current_second->exponent;

        current_first = first_num;
        while (current_first->next)
        {
            current_first = current_first->next;
            tmp_list->next = (List *) malloc (sizeof (List));
            tmp_list = tmp_list->next;

            *tmp_list = *current_first;
            tmp_list->next = NULL;

            tmp_list->coefficient *= coefficient;
            tmp_list->exponent += exponent;
        }

        tmp_list = tmp_tmp_list;

        free_list = result;
        result = addList (free_list, tmp_list);
        freeList (free_list);
        freeList (tmp_list);
    }

    return result;
}

int main ()
{
    List *first_num, *second_num;
    int n;
    scanf ("%d", &n);
    first_num = createList(n);

    scanf ("%d", &n);
    second_num = createList(n);

    printList (multiplyList (first_num, second_num));
    printList (addList (first_num, second_num));

    return 0;
}
