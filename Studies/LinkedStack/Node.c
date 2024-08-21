#include <stdio.h>
#include <stdlib.h>

//struct defined here
typedef struct NODE_s
{
    void *data;
    struct Node *next;
}NODE_t, *NODE;

//initialize node
NODE init(){
    NODE node = (NODE)malloc(sizeof(NODE_t));
    node->next = NULL;

    return node;
}

NODE push(NODE node, void *data){
    if(node!=NULL)
    {
        NODE new = init();

        new->data=data;

        new->next = node;
        node = new;

        return node;
    }

    else{
        node = init();
        return node;
    }
}

NODE addEnd(NODE node, void *data){
    NODE newNode = init();

    newNode->data = data;
    newNode->next = NULL;

    node->next = newNode;

    return node;
}

NODE mergeTwoSortedNodes(NODE node1, NODE node2)
{
    NODE result = init();
    NODE iter = result;

    while (node1 != NULL && node2 != NULL)
    {
        if(node1 == NULL)
        {
            iter->next = node2;
        }
        else if(node2!= NULL)
        {
            iter->next = node1;
        }
        else{
            if(node1->data < node2->data)
            {
                push(iter, node1->data);
                iter = iter->next;
                node1 = node1->next;
            }
            else if(node1->data > node2->data){
                push(iter, node2->data);
                iter = iter->next;
                node2 = node2->next;            
            }
            else{
                push(iter, node1->data);
                iter = iter->next;
                push(iter, node1->data);
                iter = iter->next;
                node1 = node1->next;
                node2 = node2->next;
            }
        }
    }
    return result;
}

int main(){
    NODE node;

    node = push(node, 5);
    node = addEnd(node, 14);

    NODE merged = mergeTwoSortedNodes(node, node);

    printf("test: %d", merged->data);
    return 1;
}