#include <stdio.h>
#include <stdlib.h>

#define MAX(X, Y) ((X)>(Y) ? (X):(Y))

typedef struct treeNode
{
    int data;
    int height;
    struct treeNode *LTree;
    struct treeNode *RTree;
}AVLTree;

int getHeight (AVLTree *node)
{
    if (node) return node->height;
    else return -1;
}

AVLTree *rotationL (AVLTree *root)
{
    AVLTree *newRoot;
    newRoot = root->RTree;
    root->RTree = newRoot->LTree;
    newRoot->LTree = root;

    //update node height.
    root->height = MAX (getHeight (root->LTree), getHeight (root->RTree))+1;
    newRoot->height = MAX (getHeight (newRoot->LTree), getHeight (newRoot->RTree))+1;

    return newRoot;
}

AVLTree *rotationR (AVLTree *root)
{
    AVLTree *newRoot;
    newRoot = root->LTree;
    root->LTree = newRoot->RTree;
    newRoot->RTree = root;

    //update node height.
    root->height = MAX (getHeight (root->LTree), getHeight (root->RTree))+1;
    newRoot->height = MAX (getHeight (newRoot->LTree), getHeight (newRoot->RTree))+1;

    return newRoot;
}

AVLTree *AVL_insertion (AVLTree *root, int data)
{
    if (root == NULL)
    {
        root = (AVLTree *) malloc (sizeof (AVLTree));
        root->data = data;
        root->height = 0;
        root->LTree = root->RTree = NULL;

        return root;
    }

    if (data < root->data) root->LTree = AVL_insertion (root->LTree, data);
    else if (data > root->data) root->RTree = AVL_insertion (root->RTree, data);

    int balance;
    balance = getHeight (root->LTree) - getHeight (root->RTree);

    if (balance == 2)
    {
        if (data < root->LTree->data)
            root = rotationR (root);
        else
        {
            root->LTree = rotationL (root->LTree);
            root = rotationR (root);
        }
    }
    else if (balance == -2)
    {
        if (data > root->RTree->data)
            root = rotationL (root);
        else
        {
            root->RTree = rotationR (root->RTree);
            root = rotationL (root);
        }
    }

    root->height = MAX (getHeight (root->LTree), getHeight (root->RTree))+1;

    return root;
}

int main (int argc, char *argv[])
{
    int n, i, data;
    scanf ("%d", &n);

    //create AVL Tree.
    AVLTree *root = NULL;
    for (i=0; i<n; i++)
    {
        scanf ("%d", &data);
        root = AVL_insertion (root, data);
    }
    
    //print tree root.
    printf ("%d\n", root->data);

    return 0;
}
