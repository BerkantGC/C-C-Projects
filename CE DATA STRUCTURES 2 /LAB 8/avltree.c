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
		printf("%d\n", node->key);
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

NODE bst_insert_rec(NODE node, int key, void *data){
	if(node == NULL){
		node = bst_init_node(key, data);
	}
	else{
		if(key < node->key){
			node->left = bst_insert_rec(node->left, key, data);
		}
		else if(key > node->key){
			node->right = bst_insert_rec(node->right, key, data);
		}
		else{
			printf("Duplicate key: %d. Ignoring...\n\n\n", key);
		}
	}
	return node;
}

void bst_insert(BST t, int key, void *data){
	if(t == NULL){
		printf("ERROR. Uninitialized tree\n");
	}
	else{
		if(t->root == NULL){
			t->root = bst_init_node(key, data);
		}
		else{
			t->root = bst_insert_rec(t->root, key, data);
		}
	}
}

void bst_delete_unbalanced_iterative(BST t, int key, void *data){
	if(t == NULL){
		printf("ERROR. Uninitialized tree\n");
	}
	else{

		NODE parent = (NODE)t;
		NODE curr = t->root;
		while((curr != NULL) && (key != curr->key)){
			if(key < curr->key){
				parent = curr;
				curr = curr->left;
			}
			else if(key > curr->key){
				parent = curr;
				curr = curr->right;
			}
		}

		if(curr == NULL){
			printf("The key is not found.\n");
		}
		else{
			/* NO CHILD */
			if( (curr->left == NULL) && (curr->right == NULL) ){
				if(curr == parent->left){
					parent->left = NULL;
				}
				else{
					parent->right = NULL;
				}
				//bst_free_node(curr);
				free(curr->data); /* !? */
				free(curr);

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
				while(max->right != NULL){
					max = max->right;
				}
				max->right = curr->right;

				if(curr == parent->left){
					parent->left = curr->left;
				}
				else{
					parent->right = curr->left;
				}
			}
		}
	}
}

void bst_delete_balanced_recursive(NODE curr, NODE parent, int key, void *data)
{
	if(curr == NULL){
		printf("ERROR. Uninitialized tree\n");
	}
	else{
		if(curr == NULL)
			return;

		if(key < curr->key){
			parent = curr;
			bst_delete_balanced_recursive(curr->left, parent, key, data);
		}
		else if(key > curr->key){
			parent = curr;
			bst_delete_balanced_recursive(curr->right, parent, key, data);
		}

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

				//bst_free_node(curr);
				free(curr->data); /* !? */
				free(curr);
				return;
			}

			/* SINGLE CHILD ON THE RIGHT */
			else if( (curr->left == NULL) && (curr->right != NULL) ){

				if(curr == parent->left){
					parent->left = curr->right;
				}
				else{
					parent->right = curr->right;
				}

				return;
			}
			/* SINGLE CHILD ON THE LEFT */
			else if( (curr->left != NULL) && (curr->right == NULL) ){

				if(curr == parent->left){
					parent->left = curr->left;
				}
				else{
					parent->right = curr->left;
				}

				return;
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
}

void backbone(BST tree)
{
    NODE gp = (NODE)tree;
    NODE parent = tree->root;

    while(parent != NULL)
    {
        if(parent->left != NULL)
        {
            NODE child = parent->left;
            
            parent->left = child->right;
            child->right = parent;

            gp->right = child; 
        }

        else
		{
        gp = parent; 
        }

        parent = gp->right;
    }
}

int powOf2(int n)
{
    int result = 1; 
    for (int i = 0; i < n; i++)
    {
        result *= 2;
    }
    
    return result;
}

int floorLogarithm(int n)
{
    int result = 2, i;
    for (i = 0; result <= n; i++)
    {
        result *= 2;
    }
    return i;
}

int getDataCount(BST tree)
{
    NODE iter = tree->root;
    int counter = 0;
    while(iter != NULL)
    {
        iter = iter->left;
        counter++;
    }
    return counter;
}

// void makeLeftRotations(BST tree, int size)
// {
//     NODE gp = (NODE)tree;
//     NODE p = tree->root;
//     NODE c = p->right;

//     while(size > 0)
//     {
//         leftRotation(gp, p ,c);


//         gp = c;
//         p = gp->right;
//         c = p->right;

//         size--;
//     }
// }

// void balanceWithLeftRotations(BST tree)
// {
//     int counter = getDataCount(tree);

//     int m = powOf2(floorLogarithm(counter+1)) - 1;
//     int k = counter - m;

//     makeLeftRotations(tree, k);

//     while(m > 1)
//     {
//         m /= 2;

//         makeLeftRotations(tree, m);
//     }
// }

// void makeRightRotations(BST tree, int size)
// {
//     NODE gp = (NODE)tree;
//     NODE p = tree->root;
//     NODE c = p->left;

//     while(size > 0)
//     {
// 		rightRotation(gp, p, c);
		

//         gp = c;
//         p = c->left;
//         c = p->left;

//         size--;
//     }
// }

// void balanceWithRightRotations(BST tree, int counter)
// {
//     int m = powOf2(floorLogarithm(counter+1)) - 1;
//     int k = counter - m;

//     makeRightRotations(tree, k);

//     while(m > 1)
//     {
//         m /= 2;

//         makeRightRotations(tree, m);
//     }
// }

int height(NODE node){
	if (node == NULL)
		return 0;

	return node->height;
}

int max(int a, int b)
{
	return (a > b) ? a : b;
}

NODE rightRotate(NODE y)
{
	NODE x = y->left;
	NODE T2 = x->right;

	// Perform rotation
	x->right = y;
	y->left = T2;

	// Update heights
	y->height = max(height(y->left),
	height(y->right)) + 1;
	x->height = max(height(x->left),
	height(x->right)) + 1;

	// Return new root
	return x;
}

NODE leftRotate(NODE x)
{
	NODE y = x->right;
	NODE T2 = y->left;

	y->left = x;
	x->right = T2;

	//  Update heights
	x->height = max(height(x->left),
	height(x->right)) + 1;
	y->height = max(height(y->left),
	height(y->right)) + 1;

	// Return new root
	return y;
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
		/* 2. Update height of this ancestor node */
		node->height = 1 + max(height(node->left),height(node->right));

		/* 3. Get the balance factor of this ancestor
		node to check whether this node became
		unbalanced */
		int balance = height(node->left) - height(node->right);

		// If this node becomes unbalanced, then
		// there are 4 cases

		// Left Left Case
		if (balance > 1 && key < node->left->key)
		{
			printf("Left Left\n");
			node = rightRotate(node);
		}

		// Right Right Case
		if (balance < -1 && key > node->right->key)
		{
			printf("Right Right\n");
			node = leftRotate(node);
		}

		// Left Right Case
		if (balance > 1 && key > node->left->key)
		{
			printf("Left Right\n");
			node->left =  leftRotate(node->left);
			node = rightRotate(node);
		}

		// Right Left Case
		if (balance < -1 && key < node->right->key)
		{
			printf("Right Left\n");
			node->right = rightRotate(node->right);
			node = leftRotate(node);
		}

	}
	return node;
}

int main() {
	BST t1 = bst_init();
	t1->root = insert(t1->root, 82);
	t1->root = insert(t1->root, 67);
	t1->root = insert(t1->root, 40);
	t1->root = insert(t1->root, 39);
	t1->root = insert(t1->root, 15);
	t1->root = insert(t1->root, 3);
	t1->root = insert(t1->root, 42);
	t1->root = insert(t1->root, 38);
	t1->root = insert(t1->root, 35);
	t1->root = insert(t1->root, 23);
	t1->root = insert(t1->root, 10);
	t1->root = insert(t1->root, 1);

	bst_print(t1->root, 0);
	return 0;
}