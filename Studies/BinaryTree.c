#include <stdio.h>
#include <stdlib.h>


struct NODE{
    int data;
    struct NODE * right;
    struct NODE * left;
};

typedef struct NODE NODE;

int wander(NODE *btree){
    if(btree == NULL)
        return NULL;
    wander(btree->left);
    printf("%d ", btree->data);
    wander(btree->right);

    return 1;
}

NODE *addData(NODE *btree, int x){
    if(btree == NULL)
    {
        NODE *root = (NODE*)malloc(sizeof(NODE));
        root->data = x;
        root->right = NULL;
        root->left = NULL;
        printf("nulldan dönüştü %d\n", x);
        return root;
    }

    if(btree->data < x)
    {
            btree->right = addData(btree->right, x);
        
        printf("sağdan dönüştü %d\n", x);
        
        return btree;
    }

    if(btree->data > x)
    {
            btree->left = addData(btree->left, x);
        
        return btree;
    }
}

NODE* minValue(NODE* btree)
{
    if(btree->left == NULL)
        return btree;
    
    NODE *min = minValue(btree->left);

    return min;
}
NODE *delete(NODE *btree, int wanted)
{
    if(btree == NULL)
    {
        printf("empty\n");
        return btree;
    }
    if(btree->data == wanted)
    {
        if(btree->right == NULL)
        {
            NODE *tmp = btree->left;
            free(btree);
            return tmp;
        }
        if(btree->left == NULL)
        {
             NODE *tmp = btree->right;
            free(btree);
            return tmp;
        }

        NODE* tmp = minValue(btree->right);

        btree->data = tmp->data;
        btree->right = delete(btree->right, tmp->data);
    }

    if(btree->data > wanted)
    {
        printf("soldake\n");
        btree->left= delete(btree->left, wanted);
    }
    if(btree->data < wanted)
    {
        printf("sağdake\n");
        btree->right = delete(btree->right, wanted);
    }

    return btree;
}

int search(NODE *btree, int wanted){
    if(btree == NULL)
        return 0;
    if (btree->data == wanted)
    {
        return 1;
    }
    if(search(btree->right, wanted) == 1)
        return 1;
    if(search(btree->left, wanted) == 1)
        return 1;
    return 0;
}

int main(){
    NODE *btree = NULL;
    btree = addData(btree, 10);
    btree = addData(btree, 2);
    btree = addData(btree, 1);
    btree = addData(btree, 5);
    btree = addData(btree, 16);

    btree = delete(btree, 1);
    

    printf("Is There : %d \n", search(btree, 5));
    wander(btree);
    return 0;
}