#include<stdio.h>
#include<stdlib.h>
struct node
{
	int key;
	struct node *left;
	struct node *right;
	int height;
};
int height(struct node *N)
{
	if (N == NULL)
		return 0;
	return N->height;
}
int max(int a, int b)
{
	return (a > b)? a : b;
}
struct node* newNode(int key)
{
	struct node* n = (struct node*)malloc(sizeof(struct node));
	n->key = key;
	n->left = NULL;
	n->right = NULL;
	n->height = 1; // new node is initially added at leaf
	return(n);
}
struct node *rightRotate(struct node *y)
{
	struct node *x = y->left;
	struct node *T2 = x->right;

	x->right = y;
	y->left = T2;

	y->height = max(height(y->left), height(y->right))+1;
	x->height = max(height(x->left), height(x->right))+1;

	return x;
}
struct node *leftRotate(struct node *x)
{
	struct node *y = x->right;
	struct node *T2 = y->left;

	y->left = x;
	x->right = T2;

	x->height = max(height(x->left), height(x->right))+1;
	y->height = max(height(y->left), height(y->right))+1;

	return y;
}
int getBalance(struct node *N)
{
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}
struct node* insert(struct node* node, int key)
{
	/* 1. Perform the normal BST rotation */
	if (node == NULL)
		return(newNode(key));

	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);
	else // Equal keys not allowed
		return node;

	/* 2. Update height of this ancestor node */
	node->height = 1 + max(height(node->left),height(node->right));

	/* 3. Get the balance factor of this ancestor node to check whether this node became unbalanced */
	int balance = getBalance(node);

	// If this node becomes unbalanced, then there are 4 cases
	// Left Left Case
	if (balance > 1 && key < node->left->key)
		return rightRotate(node);

	// Right Right Case
	if (balance < -1 && key > node->right->key)
		return leftRotate(node);

	// Left Right Case
	if (balance > 1 && key > node->left->key)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	// Right Left Case
	if (balance < -1 && key < node->right->key)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	/* return the (unchanged) node pointer */
	return node;
}
struct node* minValueNode(struct node* n)
{
	struct node* current = n;
	while (current->left != NULL)
		current = current->left;
	return current;
}
struct node* deleteNode(struct node* root, int key)
{
	// STEP 1: PERFORM STANDARD BST DELETE
	if (root == NULL)
		return root;

	if ( key < root->key )
		root->left = deleteNode(root->left, key);

	else if( key > root->key )
		root->right = deleteNode(root->right, key);

	else
	{
		// node with only one child or no child
		if( (root->left == NULL) || (root->right == NULL) )
		{
			struct node *temp = root->left ? root->left :root->right;

			// No child case
			if (temp == NULL)
			{
				temp = root;
				root = NULL;
			}
			else // One child case
			    *root = *temp; // Copy the contents of the non-empty child
			free(temp);
		}
		else
		{
			// node with two children: Get the inorder successor (smallest in the right subtree)
			struct node* temp = minValueNode(root->right);

			// Copy the inorder successor's data to this node
			root->key = temp->key;

			// Delete the inorder successor
			root->right = deleteNode(root->right, temp->key);
		}
	}

	// If the tree had only one node then return
	if (root == NULL)
	    return root;

	// STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
	root->height = 1 + max(height(root->left),height(root->right));

	// STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to check whether this node became unbalanced)
	int balance = getBalance(root);

	// If this node becomes unbalanced, then there are 4 cases

	// Left Left Case
	if (balance > 1 && getBalance(root->left) >= 0)
		return rightRotate(root);

	// Left Right Case
	if (balance > 1 && getBalance(root->left) < 0)
	{
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	// Right Right Case
	if (balance < -1 && getBalance(root->right) <= 0)
		return leftRotate(root);

	// Right Left Case
	if (balance < -1 && getBalance(root->right) > 0)
	{
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}
	return root;
}
void preOrder(struct node *root)
{
	if(root != NULL)
	{
		printf("%d ", root->key);
		preOrder(root->left);
		preOrder(root->right);
	}
}
int main()
{
    struct node *root = NULL;

/* Constructing tree given in the above figure */
	root = insert(root, 9);
	root = insert(root, 5);
	root = insert(root, 10);
	root = insert(root, 0);
	root = insert(root, 6);
	root = insert(root, 11);
	root = insert(root, -1);
	root = insert(root, 1);
	root = insert(root, 2);

	/* The constructed AVL Tree would be
		 9
		/ \
	   1   10
	  / \	 \
	 0   5	  11
    /    /\
  -1    2  6                   */

	printf("Preorder traversal of the constructed AVL tree is \n");
	preOrder(root);
	root = deleteNode(root, 10);

	/* The AVL Tree after deletion of 10
		 1
		/ \
	   0   9
	  /	  / \
	-1   5	 11
		/ \
	   2   6                */

	printf("\nPreorder traversal after deletion of 10 \n");
	preOrder(root);
	return 0;
}
