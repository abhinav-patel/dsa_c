#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* left,*right;
};
struct node* allocate(int key)
{
    struct node* new=(struct node*)malloc(sizeof(struct node));
    new->data=key;
    new->left=new->right=NULL;
    return new;
}
struct node* rightRotate(struct node* x)
{
    struct node* y=x->left;
    x->left=y->right;
    y->right=x;
    return y;
}
struct node* leftRotate(struct node* x)
{
    struct node* y=x->right;
    x->right=y->left;
    y->left=x;
    return y;
}
struct node* splay(struct node* root,int key)
{
    if(root==NULL||root->data==key)
        return root;
    //key lies in left subtree
    if(root->data>key)
    {
        if(root->left==NULL)
            return root;
        if(root->left->data >key)
        {
            root->left->left=splay(root->left->left,key);
            root=rightRotate(root);
        }
        else if(root->left->data <key)
        {
            root->left->right=splay(root->left->right,key);
            if(root->left->right!=NULL)
                root->left=leftRotate(root->left);
        }
        return(root->left==NULL)?root:rightRotate(root);
    }
    else
    {
        if(root->right==NULL)
           return root;
        if(root->right->data >key)
        {
            root->right->left=splay(root->right->left,key);
            if(root->right->left!=NULL)
               root->right=rightRotate(root->right);
        }
        else if(root->right->data <key)
        {
            root->right->right=splay(root->right->right,key);
            root=leftRotate(root);
        }
        return(root->right==NULL)?root:leftRotate(root);
    }
}
struct node* search(struct node* root,int key)
{
    return splay(root,key);
}
struct node* insert(struct node* root,int key)
{
    if(root==NULL)
        return allocate(key);
    root=splay(root,key);
    if(root->data==key)
        return root;
    
    struct node* new=allocate(key);
    if(root->data>key)
    {
        new->right=root;
        new->left=root->left;
        root->left=NULL;
    }
    else
    {
        new->left=root;
        new->right=root->right;
        root->right=NULL;
    }
    return new;
}
struct node* delete_key(struct node* root, int key)
{
    struct node* temp;
    if (!root)
        return NULL;
  
    root = splay(root, key);
    if (key != root->data)
        return root;
    if (!root->left) {
        temp = root;
        root = root->right;
    }
    else {
        temp = root;

        root = splay(root->left, key);

        root->right = temp->right;
    }
    free(temp);

    return root;
}
void preOrder(struct node* root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
int main()
{
    struct node* root=allocate(100);
    root->left = allocate(50);
    root->right = allocate(200);
    root->left->left = allocate(40);
    root->left->left->left = allocate(30);
    root->left->left->left->left = allocate(20);
    root = insert(root, 25);
  
    printf("Preorder traversal of the modified Splay tree is \n");
    preOrder(root);
    return 0;
}
