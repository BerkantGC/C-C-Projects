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

int search(NODE tree, int key)
{
    for (int i = 0; i < 100; i++)
    {
        if(key == tree[i].key)
        {
            printf("KEY: %d \n", key);
            return 1;
        }
    }
    
    return 0;
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

        node[right(keepRight)].key = 0;
        node[right(keepRight)].height = 0;

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

void makeBalanced(NODE node, int index, int key)
{
        node[index].height = findHeight(node, index);
        
        int balance = findHeight(node, left(index)) - findHeight(node, right(index));
        
        int parentindex = findParent(index);

        // Left Left Case
        if (balance > 1 && key <= node[left(index)].key){
            printf("a\n");
            rightRotate(node, index);
        }

        // Right Right Case
        if (balance < -1 && key > node[right(index)].key)
        {   
            printf("b\n");
            leftRotate(node, index);
        }

        // Left Right Case
        if (balance > 1 && key > node[left(index)].key )
        {
            printf("c\n");
            leftRotate(node, left(index));
            rightRotate(node, index);
        }

        // Right Left Case
        if (balance < -1 && key <= node[right(index)].key )
        {
            printf("d\n");
            rightRotate(node, right(index));
            leftRotate(node, index);
        }
}

NODE insertArray(NODE node, int key)
{
    int index = 0;

    while(node[index].key != NULL)
    {
        if(key < node[index].key)
        {
            index = left(index);
        }
        else if(key > node[index].key)
        {
            index = right(index);
        }
    }

    node[index].key = key;

    //Rotationlarda parenti log fonksiyonu ile bul
    int shiftUp = index;

    while (shiftUp != 0)
    {
        makeBalanced(node, shiftUp, key);
        shiftUp = (shiftUp-1)/2;
    }
    makeBalanced(node, shiftUp, key);

    return node;
}

void delete(NODE node, int index, int key)
{
    while(node[index].key != key)
    {
        if(key < node[index].key)
        {
            index = left(index);
        }

        if(key > node[index].key)
        {
            index = right(index);
        }
    }

    if(key == node[index].key){
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

    //Rotationlarda parenti log fonksiyonu ile bul
    int shiftUp = index;

    while (shiftUp != 0)
    {
        makeBalanced(node, shiftUp, key);   
        shiftUp = (shiftUp-1)/2;
    }
    makeBalanced(node, shiftUp, key);   
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
    
    
    insertArray(tree, 9);
    insertArray(tree, 15);
    insertArray(tree, 4);
    insertArray(tree, 3);
    insertArray(tree, 1);
    insertArray(tree, 12);
    insertArray(tree, 27);
    insertArray(tree, 30);

    delete(tree, 0, 15);
    
    printArray(tree, 0 , 0);

    return 0;
}
