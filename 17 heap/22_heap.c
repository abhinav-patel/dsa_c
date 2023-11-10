#include <stdio.h>
#include <stdlib.h>
//Max heap
struct heap
{
    int* arr;
    int count,size;
    int heap_type;
};
struct heap* create(int size,int type)
{
    struct heap* temp=(struct heap*)malloc(size of(struct heap));
    if(temp==NULL)
        return temp;
    temp->heap_type=type;
    temp->count=0;
    temp->size=size;
    temp->arr=(int*)malloc(sizeof(int)*temp->size);
    return temp;
}
int parent(struct heap* root,int i)
{
    if(i<=0||i>=root->count)
       return  -1;
    return (i-1)/2;
}
int leftchild(struct heap* root,int i)
{
    int left=2*i+1;
    if(left>root->count)
       return -1;
    return left;
}
int rightchild(struct heap* root,int i)
{
    int right=2*i+2;
    if(right>root->count)
       return -1;
    return right;
}
int getMax(struct heap* root)
{
    if(root->count==0)
       return -1;
    return root->arr[0];
}
void heapify(struct heap* root)

