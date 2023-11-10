#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
// Computes the number of nodes in a tree.
int size(struct node *node)
{
  if (node == NULL)
    return 0;
  else
    return (size(node->left) + 1 + size(node->right));
}
// insertion done at first position available in level order
struct node *insert(struct node *root, int key)
{
}
// deletion done than by replacing the bottom most and right most node with it
// can also vary with ques
struct node *delete(struct node *root, int key)
{
}
// find maximum element
int findMax(struct Node *root)
{
  if (root == NULL)
    return INT_MIN;
  int res = root->data;
  int lres = findMax(root->left);
  int rres = findMax(root->right);
  if (lres > res)
    res = lres;
  if (rres > res)
    res = rres;
  return res;
}
// find minimum element
int findMin(struct Node *root)
{
  if (root == NULL)
    return INT_MAX;
  int res = root->data;
  int lres = findMin(root->left);
  int rres = findMin(root->right);
  if (lres < res)
    res = lres;
  if (rres < res)
    res = rres;
  return res;
}
int getfullNodeCount(struct Node *root)
{
  if (root == NULL)
    return 0;

  int res = 0;
  if (root->left && root->right)
    res++;

  res += (getfullCount(root->left) +
          getfullCount(root->right));
  return res;
}
int getLeafCount(struct node *node)
{
  if (node == NULL)
    return 0;
  if (node->left == NULL && node->right == NULL)
    return 1;
  else
    return getLeafCount(node->left) + getLeafCount(node->right);
}
// constructing a binary tree from an given array
struct node *construct(int arr[], int size)
{
  struct node *root = NULL;
  struct node *queue[size];
  int front = 0;
  int rear = 0;
  root = allocate(arr[0]);
  queue[rear++] = root;
  for (int i = 1; i < size; i += 2)
  {
    struct node *curr = queue[front++];
    if (arr[i] != -1)
    {

      struct node *left = allocate(arr[i]);
      curr->left = left;
      queue[rear++] = left;
    }
    if (i + 1 < size && arr[i + 1] != -1)
    {
      struct node *right = allocate(arr[i + 1]);
      curr->right = right;
      queue[rear++] = right;
    }
  }
  return root;
}
int main()
{
  struct node *root = allocate(1);
  root->left = allocate(2);
  root->right = allocate(3);
  root->left->left = allocate(4);
  root->left->right = allocate(5);
  printf("Level Order traversal of binary tree is \n");
  return 0;
}
