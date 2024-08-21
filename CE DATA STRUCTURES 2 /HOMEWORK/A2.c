#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct NODE_s *NODE;
typedef struct NODE_s{
    int height;
	int key;
	void *data;
} NODE_t[1];

// void bst_print(NODE node, int l){
// 	int i;
// 	if(node != NULL){
// 		bst_print(node->right, l+1);
// 		for (i = 0; i < l; ++i) {
// 			printf("     ");
// 		}
// 		printf("%d(%d)\n", node->key, node->height);
// 		bst_print(node->left, l+1);
// 	}
// }

void printArray(NODE tree, int index, int h)
{
    for(int i = 0; i < 50; i++)
    {
        printf("%d(%d) ", tree[i].key, tree[i].height);
    }
    printf("\n\n\n");
}

int log(int number)
{
    int result = 0;

    for (int i = 2; i <= number; i *= 2)
    {
        result++;
    }
    
    return result;
}

int left(int i)
{   
    return 2*i + 1;
}

int right(int i)
{   
    return 2*i + 2;
}

int search(NODE tree, int index, int key)
{
    if(tree[index].key == NULL)
    {
        printf("couldnt find\n");
        return 0;
    }

    if(key < tree[index].key)
    {
        search(tree, left(index), key);
        return 1;
    }
    if(key > tree[index].key)
    {
        search(tree, right(index), key);
        return 1;
    }

    if(tree[index].key == key)
    {
        printf("key: %d \n", key);
        return 1;
    }
}

int findHeight(NODE array, int data)
{   
    if(array[data].key == NULL)
        return 0;

    else if(array[left(data)].key == NULL && array[right(data)].key == NULL)
        return 1;
    
    else if(array[left(data)].height <= array[right(data)].height)
        return 1+array[right(data)].height;

    else if(array[left(data)].height > array[right(data)].height)
        return 1+array[left(data)].height;
}

int findParent(int child)
{
    if(child-1 <= 1)
        return 0;

    return (child-1)/2;
}

void leftRotate(NODE node, int child)
{
    struct NODE_s tmp = node[child];
    
    int keepRight = right(child);

    node[child] = node[keepRight];

    node[left(child)] = tmp;

    while(node[right(keepRight)].key != NULL || node[right(keepRight)].key != NULL){
        node[keepRight] = node[right(keepRight)];

        node[right(keepRight)] = node[right(right(keepRight))];
        keepRight = right(keepRight);
    }

    node[child].height = findHeight(node, child);
}

void rightRotate(NODE node, int child)
{
    //child 3, keepLeft 7
    struct NODE_s tmp = node[child];
    
    int keepLeft = left(child);
    
    node[child] = node[keepLeft];

    node[right(child)] = tmp;
    node[right(child)].height = findHeight(node, right(child));

    while(node[right(keepLeft)].key != NULL || node[left(keepLeft)].key != NULL){
        node[keepLeft] = node[left(keepLeft)];

        node[left(keepLeft)] = node[left(left(keepLeft))];

        keepLeft = left(keepLeft);
    }

    node[child].height = findHeight(node, child);
}


NODE insertArray(NODE node, int key, int index)
{
    if(node[index].key == NULL)
    {
        node[index].key = key;
    }
    else if(key < node[index].key)
    {
        insertArray(node, key, left(index));
    }
    else if(key > node[index].key)
    {
        insertArray(node, key, right(index));
    }

    //Rotationlarda parenti log fonksiyonu ile bul
    int balance = findHeight(node, left(index)) - findHeight(node, right(index));
    
    int parentIndex = findParent(index);
    node[index].height = findHeight(node, index);

    // Left Left Case
    if (balance > 1 && key <= node[left(index)].key){
        rightRotate(node, index);
    }

    // Right Right Case
    if (balance < -1 && key > node[right(index)].key)
    {   
        leftRotate(node, index);
    }

    // Left Right Case
    if (balance > 1 && key > node[left(index)].key )
    {
        leftRotate(node, left(index));
        rightRotate(node, index);
    }

    // Right Left Case
    if (balance < -1 && key <= node[right(index)].key )
    {
        rightRotate(node, right(index));
        leftRotate(node, index);
    }

    return node;
}

void delete(NODE node, int index, int key)
{
    if(node[index].key == NULL)
    {
        return;
    }
    else{
        if(key < node[index].key)
        {
            delete(node, left(index), key);
        }

        if(key > node[index].key)
        {
            delete(node, right(index), key);
        }

        else if(key == node[index].key){
            if(node[left(index)].key == NULL && node[right(index)].key == NULL)
            {
                node[index].key = NULL;
                node[index].height = 0;
            }
            else if(node[left(index)].key != NULL && node[right(index)].key == NULL)
            {
                node[index] = node[left(index)];
                node[left(index)].key = NULL;
                node[left(index)].height = 0;
            }
            else if(node[left(index)].key == NULL && node[right(index)].key != NULL)
            {
                node[index] = node[right(index)];
                node[right(index)].key = NULL;
                node[right(index)].height = 0;
            }
            else{
                int maxIndex = left(index);

                while(node[right(maxIndex)].key != NULL)
                {
                    maxIndex = right(maxIndex);
                }

                node[index] = node[maxIndex];
                node[maxIndex] = node[left(maxIndex)];
            }
        }
    }
    node[index].height = findHeight(node, index);

    //Rotationlarda parenti log fonksiyonu ile bul
    int balance = findHeight(node, left(index)) - findHeight(node, right(index));
    
    int parentIndex = findParent(index);

    // Left Left Case
    if (balance > 1 && key <= node[left(index)].key){        
        printf("left left\n");
        rightRotate(node, index);
    }

    // Right Right Case
    if (balance < -1 && key > node[right(index)].key)
    {   
        printf("right right\n");
        leftRotate(node, index);
    }

    // Left Right Case
    if (balance > 1 && key > node[left(index)].key)
    {
        printf("Left right\n");
        leftRotate(node, left(index));
        rightRotate(node, index);
    }

    // Right Left Case
    if (balance < -1 && key <= node[right(index)].key)
    {
        printf("Right left\n");
        rightRotate(node, right(index));
        leftRotate(node, index);
    }
}

int main(int argc, char const *argv[])
{
    NODE tree = (NODE)malloc(sizeof(NODE_t)*100);

    for (int i = 0; i < 100; i++)
    {
        tree[i].key = NULL;
        tree[i].height = 0;
        tree[i].data = NULL;
    }
    
    insertArray(tree, 9, 0);
    insertArray(tree, 15, 0);
    insertArray(tree, 4, 0);
    insertArray(tree, 3, 0);
    insertArray(tree, 1, 0);
    insertArray(tree, 12, 0);
    insertArray(tree, 27, 0);
    insertArray(tree, 30, 0);

    delete(tree, 0, 15);
    printArray(tree, 0 , 0);

    return 0;
}
