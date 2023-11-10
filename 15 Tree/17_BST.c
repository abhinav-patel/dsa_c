#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 100

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *allocate(int data)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

// creating a stack
struct Stack
{
    int size;
    int top;
    struct Node **array;
};
struct Stack *createStack(int size)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->size = size;
    stack->top = -1;
    stack->array = (struct Node **)malloc(stack->size * sizeof(struct Node *));
    return stack;
}
// All operations of stack
int isFull(struct Stack *stack)
{
    return stack->top - 1 == stack->size;
}
int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}
void push(struct Stack *stack, struct node *n)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = n;
}
struct Node *pop(struct Stack *stack)
{
    if (isEmpty(stack))
        return NULL;
    return stack->array[stack->top--];
}

// Deapth first traversals(DFS)
void preOrder(struct node *root) // recursive
{
    if (root != NULL)
    {
        printf("%d - ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
void preOrder1(struct node *root) // iterative
{
    struct Stack *s3 = createStack(MAX_SIZE);
    struct node *ptr = root;
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        if (ptr->right != NULL)
        {
            push(s3, ptr->right);
        }
        if (ptr->left != NULL)
            ptr = ptr->left;
        else
        {
            ptr = pop(s3);
        }
    }
}

void postOrder(struct node *root) // recursive
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d - ", root->data);
    }
}
void postOrder1(struct node *root) // iterative
{
    if (root == NULL)
        return;
    // Create two stacks
    struct Stack *s1 = createStack(MAX_SIZE);
    struct Stack *s2 = createStack(MAX_SIZE);
    // push root to first stack
    push(s1, root);
    struct node *n;
    // Run while first stack is not empty
    while (!isEmpty(s1))
    {
        // Pop an item from s1 and push it to s2
        n = pop(s1);
        push(s2, n);
        // Push left and right children of removed item to s1
        if (n->left)
            push(s1, n->left);
        if (n->right)
            push(s1, n->right);
    }
    // Print all elements of second stack
    while (!isEmpty(s2))
    {
        n = pop(s2);
        printf("%d ", n->data);
    }
}

void inOrder(struct node *root) // recursive
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d - ", root->data);
        inOrder(root->right);
    }
}
void inOrder1(struct node *root) // iterative
{
}
// counts no of leaf nodes
int countleafNodes(struct node *root)
{
    if (root = NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return countleafNodes(root->left) + countleafNodes(root->right);
}
// checks if binary tree is binary search tree
int isBST(struct node *root)
{
    static struct node *prev = NULL; // so value of prev will not be diff for every recursion
    if (root != NULL)
    {
        if (!isBST(root->left))
            return 0;
        if (prev != NULL && root->data <= prev->data)
            return 0;
        prev = root;
        return (isBST(root->right));
    }
    else
        return 1;
}
int valid_BST(struct tree *root)
{
    if (root == NULL)
        return 1;
    if (root->left != NULL && find_max(root->left) >= root->val)
        return 0;
    if (root->right != NULL && find_min(root->right) <= root->val)
        return 0;
    if (!valid_BST(root->left) || !valid_BST(root->right))
        return 0;
    return 1;
}
// searching for a node
struct node *search1(struct node *root, int key) // recursive
{
    if (root == NULL)
        return NULL;
    if (key == root->data)
        return root;
    else if (key < root->data)
        return search1(root->left, key);
    else
        return search1(root->right, key);
}
struct node *search2(struct node *root, int key) // iterative
{
    while (root != NULL)
    {
        if (key == root->data)
            return root;
        else if (key < root->data)
            return root->left;
        else
            return root->right;
    }
    return NULL;
}
// fun returns height of the tree
int height(struct node *root)
{
    if (root == NULL)
        return -1;
    else
    {
        int lheight = height(root->left);
        int rheight = height(root->right);
        if (lheight > rheight)
            return lheight + 1;
        else
            return rheight + 1;
    }
}
// breadth first traversal(BFS)
//  Print nodes at a current level
void printCurrentLevel(struct node *root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1)
    {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}
void printLevelOrder(struct node *root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
    {
        printCurrentLevel(root, i);
        printf("\n");
    }
}
// Inserting node
void insertBST(struct node *root, int key) // Itretative
{
    struct node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (root->data == key)
            return;
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    struct node *new = allocate(key);
    if (key < prev->data)
        prev->left = new;
    else
        prev->right = new;
}
struct node *insertBST1(struct node *node, int key) // Recursive
{
    if (node == NULL)
        return allocate(key);
    if (key < node->data)
        node->left = insertBST1(node->left, key);
    else if (key > node->data)
        node->right = insertBST1(node->right, key);
    else
        printf("Duplicate key");

    return node;
}
struct node *deleteBST(struct node *root, int key)
{
    if (root == NULL)
        return root;
    if (root->data > key)
    {
        root->left = deleteBST(root->left, key);
        return root;
    }
    else if (root->data < key)
    {
        root->right = deleteBST(root->right, key);
        return root;
    }
    if (root->left == NULL)
    {
        struct node *temp = root->right;
        free(root);
        return temp;
    }
    else if (root->right == NULL)
    {
        struct node *temp = root->left;
        free(root);
        return temp;
    }
    else
    {
        struct node *succParent = root;
        struct node *succ = root->right;
        while (succ->left != NULL)
        {
            succParent = succ;
            succ = succ->left;
        }
        if (succParent != root)
            succParent->left = succ->right;
        else
            succParent->right = succ->right;
        root->data = succ->data;
        free(succ);
        return root;
    }
}
// maximum and min elements
int min(struct node *root)
{
    struct node *temp = root;
    while (root->left != NULL)
    {
        temp = temp->left;
    }
    return temp->data;
}
int max(struct node *root)
{
    struct node *temp = root;
    while (root->right != NULL)
    {
        temp = temp->right;
    }
    return temp->data;
}
// to copy tree into another tree
struct node *copytree(struct node *root, struct node *root2) // used preorder
{
    if (root != NULL)
    {
        root2 = allocate(root->data);
        root2->left = copytree(root->left, root2->left);
        root2->right = copytree(root->right, root2->right);
    }
    return root2;
}
// deleting a tree
void freetree(struct node *root) // used postorder
{
    if (root != NULL)
    {
        freetree(root->left);
        freetree(root->right);
        free(root);
    }
}
// checks if the given tree is height balanced (AVL Tree)
bool isBalanced(struct node *root)
{
    if (root == NULL)
        return NULL;
    int lh = height(root->left);
    int rh = height(root->right);
    if (abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right))
        return 1;
    return 0;
}
int main()
{
    struct node *root = allocate(1);
    root = insertBST1(root, 2);
    root = insertBST1(root, 3);
    root = insertBST1(root, 4);
    root = insertBST1(root, 5);
    printf("Level Order traversal of binary tree is \n");
    printLevelOrder(root);
    preOrder(root);
    preOrder1(root);
    // printLevelOrder(root);
    root = deleteBST(root, 1);
    printLevelOrder(root);
    inOrder(root);
    struct node *root2 = copytree(root, root2);
    printLevelOrder(root2);
    free(root2);
    return 0;
}
