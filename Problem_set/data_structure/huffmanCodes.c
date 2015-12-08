#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#define MIN_DATA 0
#define MAX_N 63
#define MAX_DATA 1001

typedef struct node
{
    char word;
    int data;
    struct node *L;
    struct node *R;
}Node;

typedef struct
{
    Node *ele[MAX_N];
    int top;
}Heap;

void insertEle (Heap *heap, int i, Node *node)
{
    heap->top++;
    if (i == 0) heap->ele[i] = node;
    else
    {
        int pos;
        for (pos=i; pos != 0 && heap->ele[(pos-1)/2]->data > node->data; pos=(pos-1)/2)
            heap->ele[pos] = heap->ele[(pos-1)/2];
        heap->ele[pos] = node;
    }
}

Node *pop (Heap *heap)
{
    Node *result = heap->ele[0];
    Node *tmp = heap->ele[heap->top--];

    int parent, child;
    for (parent=0; 2*parent+1<=heap->top; parent=child)
    {
        child = 2*parent+1;
        if (child != heap->top && heap->ele[child]->data > heap->ele[child+1]->data) child++;
        if (heap->ele[child]->data>=tmp->data) break;
        else heap->ele[parent] = heap->ele[child];
    }

    heap->ele[parent] = tmp;

    return result;
}

int countWPL (Node *tree, int len)
{
    if (!tree) return 0;
    if (!tree->L && !tree->R) return len*tree->data;

    return countWPL (tree->L, len+1)+countWPL (tree->R, len+1);
}

int main (int argc, char *argv[])
{
    int word_num;
    scanf ("%d", &word_num);
    int datas[word_num];

    Heap *heap = (Heap *) malloc (sizeof (Heap));;
    heap->top = -1;
    int i;

    //insert elements.
    char word;
    int data;
    for (i=0; i<word_num; i++)
    {
        scanf (" %c %d", &word, &data);
        Node *node = (Node *) malloc (sizeof (Node));
        node->L = node->R = NULL;
        node->word = word;
        node->data = datas[i] = data;
        insertEle (heap, i, node);
    }

    for (i=0; i<word_num-1; i++)
    {
        Node *tmp_node = (Node *) malloc (sizeof (Node));
        tmp_node->L = pop (heap);
        tmp_node->R = pop (heap);
        tmp_node->data = tmp_node->L->data + tmp_node->R->data;
        insertEle (heap, word_num-2-i, tmp_node);
    }

    Node *h_tree = pop(heap);

    int std_WPL = countWPL (h_tree, 0);

    int test_num;
    scanf ("%d", &test_num);

    //test data.
    int WPL, j;
    char s[word_num][MAX_N+1];
    for (i=0; i<test_num; i++)
    {
        WPL = 0;
        //count WPL.
        for (j=0; j<word_num; j++)
        {
            scanf (" %c %s", &word, s[j]);
            WPL += datas[j] * strlen(s[j]);
        }

        if (std_WPL != WPL)
        {
            printf ("No\n");
            continue;
        }

        //test prefix.
        int k, l, prefix = 0;
        for (k=0; k<word_num-1; k++)
        {
            for (l=k+1; l<word_num; l++)
            {
                if ((strlen(s[k])>strlen(s[l])&&(strstr(s[k],s[l]))==s[k]) ||
                    (strlen(s[k])<strlen(s[l])&&(strstr(s[l],s[k]))==s[l]) ||
                    (strlen(s[k])==strlen(s[l])&&!strcmp(s[k],s[l]))
                    )
                {
                    prefix = 1;
                    break;
                }
            }

            if (prefix) break;
        }

        if (prefix) printf ("No\n");
        else printf ("Yes\n");
    }
}
