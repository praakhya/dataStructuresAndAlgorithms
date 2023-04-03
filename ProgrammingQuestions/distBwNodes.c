#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    struct Node *left, *right;
    int key;
};

struct Node *newNode(int key)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

    /* put in the key  */
    new_node->key = key;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Standard BST insert function
struct Node *insert(struct Node *root, int key)
{
    if (!root)
        root = newNode(key);
    else if (root->key > key)
        root->left = insert(root->left, key);
    else if (root->key < key)
        root->right = insert(root->right, key);
    return root;
}
int findDist(struct Node *root, int a, int b, int ct)

{
    // printf("a=%d b=%d ct%d\n",a,b,ct);
    if (a == -1 && b == -1) // if both a & b are set to -1, that means both have been found, so the distance must have been calculated (in ct)
    {
        return ct;
    }
    if (b == root->key) // Though we were treating a as the first node to be found while traversing, if b is found, we now treat a as the second source to be found
    {
        findDist(root, a, -1, ++ct); // arguement b is set to -1 which means b was found.
    }
    if (a == root->key) // If a is found
    {
        if (ct == -1) // If count has not begun yet(which means, b was not found before a)
        {
            return findDist(root, b, -1, ++ct); // Start the count by setting it to zero and search for b
        }
        else
        {
            return findDist(root, -1, -1, ct); // If a is found but ct was not non zero, that means b was found earlier. So counting can be stopped.
        }
    }
    else if (a < root->key)
    {
        if (ct == -1)
        {
            return findDist(root->left, a, b, ct);
        }
        else
        {
            return findDist(root->left, a, b, ++ct);
        }
    }
    else if (a > root->key)
    {
        if (ct == -1)
        {
            return findDist(root->right, a, b, ct);
        }
        else
        {
            return findDist(root->right, a, b, ++ct);
        }
    }
    return -1;
}
int findDistWrapper(struct Node *root, int a, int b)
{
    int ct = findDist(root, a, b, -1);
    if (a == b)
    {
        return 0;
    }
    if (ct == 0)
    {
        return 1;
    }
    else
    {
        return ct;
    }
}
int main()
{
    int num;
    struct Node *root = NULL;
    int result;
    int a, b;
    scanf("%d", &num);

    int temp = 0;
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &temp);
        root = insert(root, temp);
    }
    scanf("%d %d", &a, &b);
    result = findDistWrapper(root, a, b);
    printf("%d", result);
}