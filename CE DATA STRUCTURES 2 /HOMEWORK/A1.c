#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct NODE_s *NODE;
typedef struct NODE_s{
	NODE left;
	NODE right;
    int height;
	int key;
	void *data;
} NODE_t[1];

typedef struct{
	NODE root;
} BST_t[1], *BST;

void bst_print(NODE node, int l){
	int i;
	if(node != NULL){
		bst_print(node->right, l+1);
		for (i = 0; i < l; ++i) {
			printf("     ");
		}
		printf("%d(%d)\n", node->key, node->height);
		bst_print(node->left, l+1);
	}
}

BST bst_init(){
	BST t = (BST)malloc(sizeof(BST_t));
	t->root = NULL;
	return t;
}

void bst_free(BST t){
	//Think about what happens to the nodes!?
	free(t);
}

NODE bst_init_node(int key, void *data){
	NODE node = (NODE)malloc(sizeof(NODE_t));
	node->left = NULL;
	node->right = NULL;
	node->key = key;
	node->data = data;
    node->height = 1;
	return node;
}

void bst_free_node(NODE n){
	free(n);
}

int height(NODE node){
	if (node == NULL)
		return 0;

	return node->height;
}

int max(int a, int b)
{
	return (a > b) ? a : b;
}

int calculateBalance(NODE node){
	if(node == NULL)
		return 0;

	return height(node->left) - height(node->right);
}

int search(NODE node, int key)
{
	if(node == NULL)
		return 0;

	if(key < node->key )
	{
		search(node->left, key);
	}

	if(key > node->key )
	{
		search(node->right, key);
	}

	if(node->key == key)
	{
		printf("KEY :%d\n", key);
		return 1;
	}
}

NODE rightRotate(NODE node)
{
	NODE T1 = node->left;
	NODE T2 = T1->right;

	T1->right = node;
	node->left = T2;

	node->height = max(height(node->left),
	height(node->right)) + 1;
	T1->height = max(height(T1->left),
	height(T1->right)) + 1;

	return node;
}

NODE leftRotate(NODE node)
{
	NODE T1 = node->right;
	NODE T2 = T1->left;

	T1->left = node;
	node->right = T2;

	node->height = max(height(node->left),height(node->right)) + 1;
	T1->height = max(height(T1->left), height(T1->right)) + 1;

	return node;
}

NODE insert(NODE node, int key)
{
	if (node == NULL)
	{
		node = bst_init_node(key, NULL);
	}

	else{
			if (key < node->key)
			node->left  = insert(node->left, key);
			else if (key > node->key)
			node->right = insert(node->right, key);
			else {printf("aynisi");}
		
		node->height = 1 + max(height(node->left),height(node->right));

		int balance = height(node->left) - height(node->right);

		
		// there are 4 cases

		// Left Left Case
		if (balance > 1 && key < node->left->key)
			node = rightRotate(node);

		// Right Right Case
		if (balance < -1 && key > node->right->key)
			node = leftRotate(node);

		// Left Right Case
		if (balance > 1 && key > node->left->key)
		{
			node->left =  leftRotate(node->left);
			node = rightRotate(node);
		}

		// Right Left Case
		if (balance < -1 && key < node->right->key)
		{
			node->right = rightRotate(node->right);
			node = leftRotate(node);
		}

	}
	return node;
}

NODE avlDeletion(NODE curr, NODE parent, int key)
{
	if(curr == NULL){
		printf("ERROR. Uninitialized tree\n");
        return curr;
	}
	else{
		if(curr == NULL)
			return curr;

		if(key < curr->key){
			parent = curr;
			avlDeletion(curr->left, parent, key);
		}
		else if(key > curr->key){
			parent = curr;
			avlDeletion(curr->right, parent, key);
		}

		printf("key : %d, curr->key : %d \n", key, curr->key);
		
		if(key == curr->key)	
		{
			/* NO CHILD */
			if( (curr->left == NULL) && (curr->right == NULL) ){

				if(curr == parent->left){
					parent->left = NULL;
				}
				else{
					parent->right = NULL;
				}
			}

			/* SINGLE CHILD ON THE RIGHT */
			else if( (curr->left == NULL) && (curr->right != NULL) ){

				if(curr == parent->left){
					parent->left = curr->right;
				}
				else{
					parent->right = curr->right;
				}

			}
			/* SINGLE CHILD ON THE LEFT */
			else if( (curr->left != NULL) && (curr->right == NULL) ){

				if(curr == parent->left){
					parent->left = curr->left;
				}
				else{
					parent->right = curr->left;
				}

			}

			/* TWO CHILDREN */
			else{
				NODE max = curr->left;
				NODE prevMax = max;

				while(max->right != NULL){
					prevMax = max;
					max = max->right;
				}

				prevMax->right = max->left;
				max->right = curr->right;

				if(curr->left != max)
				{
					max->left = curr->left;
				}
				
				if(curr == parent->left){
					parent->left = curr->left;
				}

				else{
					parent->right = curr->left;
				}	
				
			}
		}
	}

    printf("parent->key : %d, curr->key : %d\n", parent->key , curr->key);

    if(curr == NULL)
        return curr;

    curr->height = 1 + max(height(curr->left),height(curr->right));

    int balance = calculateBalance(curr);

    NODE left = curr->left, right = curr->right;
    int leftBalance = calculateBalance(left), rightBalance = calculateBalance(right);

	if (balance > 1 && key < curr->left->key)
	{
		printf("a\n");
		curr = rightRotate(curr);
	}

	// Right Right Case
	if (balance < -1 && key > curr->right->key)
	{
		printf("b\n");
		curr = leftRotate(curr);
	}

	// Left Right Case
	if (balance > 1 && key > curr->left->key)
	{
		printf("c\n");
		curr->left =  leftRotate(curr->left);
		curr = rightRotate(curr);
	}

	// Right Left Case
	if (balance < -1 && key < curr->right->key)
	{
		printf("d\n");
		curr->right = rightRotate(curr->right);
		curr = leftRotate(curr);
	}

    return curr;
}

int main() {
	BST t1 = bst_init();
	t1->root = insert(t1->root, 9);
	t1->root = insert(t1->root, 5);
	t1->root = insert(t1->root, 10);
	t1->root = insert(t1->root, 0);
	t1->root = insert(t1->root, 6);
	t1->root = insert(t1->root, 11);
	t1->root = insert(t1->root, -1);
	t1->root = insert(t1->root, 1);
	t1->root = insert(t1->root, 2);

	bst_print(t1->root, 0);
    printf("\n\n");

    t1->root = avlDeletion(t1->root,(NODE)t1, 1);
    //deleteNode(t1->root,15);

	bst_print(t1->root, 0);

	search(t1->root, 70);
	return 0;
}