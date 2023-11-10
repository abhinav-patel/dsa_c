#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

node *allocate(int data)
{
    node *temp = new node();
    if (!temp)
    {
        return NULL;
    }
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

node *insert(node* root, int data)
{
    if (root == NULL)
    {
        root = allocate(data);
        return root;
    }
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp->left != NULL)
        {
            q.push(temp->left);
        }
        else
        {
            temp->left = allocate(data);
            return root;
        }
        if (temp->right != NULL)
        {
            q.push(temp->right);
        }
        else
        {
            temp->right = allocate(data);
            return root;
        }
    }
    return root;
}

node *search(node *root, int key)
{
    if (root == NULL || root->data == key)
    {
        return root;
    }
    node *left = search(root->left, key);
    if (left != NULL)
    {
        return left;
    }
    return search(root->right, key);
}

int findDistance(node *root, int key)
{
    if (root == NULL)
    {
        return -1;
    }
    int d = -1;
    queue<node *> q;
    q.push(root);
    unordered_map<node *, int> distance;
    distance[root] = 0;
    while (!q.empty())
    {
        node *curr = q.front();
        q.pop();
        if (curr->data == key)
        {
            d = distance[curr];
            break;
        }
        if (curr->left != NULL)
        {
            q.push(curr->left);
            distance[curr->left] = distance[curr] + 1;
        }
        if (curr->right != NULL)
        {
            q.push(curr->right);
            distance[curr->right] = distance[curr] + 1;
        }
    }
    return d;
}
node *lca(node *root, int n1, int n2)
{
    if (root == NULL || root->data == n1 || root->data == n2)
    {
        return root;
    }
    node *leftResult = lca(root->left, n1, n2);
    node *rightResult = lca(root->right, n1, n2);
    if (leftResult != NULL && rightResult != NULL)
    {
        return root;
    }
    return (leftResult != NULL) ? leftResult : rightResult;
}
int findDistanceNodes(node *root, int n1, int n2)
{
    node *lcaNode = lca(root, n1, n2);
    int d1 = findDistance(lcaNode, n1);
    int d2 = findDistance(lcaNode, n2);
    return d1 + d2;
}

/*node *lca(node *root, int n1, int n2)
{
    if (root == NULL || root->data == n1 || root->data == n2)
    {
        return root;
    }
    node *leftResult = lca(root->left, n1, n2);
    node *rightResult = lca(root->right, n1, n2);
    if (leftResult != NULL && rightResult != NULL)
    {
        return root;
    }
    return (leftResult != NULL) ? leftResult : rightResult;
}*/

int main()
{
    int n;
    cin >> n;
    node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        if (data != -1)
        {
            root = insert(root, data);
        }
    }
    int tim, racks;
    cin >> tim >> racks;
    int rootToTim = findDistance(root, tim);
    int rootToRacks = findDistance(root, racks);
    int timToRacks = findDistanceNodes(root, tim, racks);
    cout << "Distance between root to Tim: " << rootToTim << endl;
    cout << "Distance between root to Racks: " << rootToRacks << endl;
    cout << "Distance between Tim and Racks: " << timToRacks << endl;
    return 0;
}
