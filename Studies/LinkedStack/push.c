#include <stdio.h>
#include <stdlib.h>

typedef struct NODE_s
{
    struct NODE_s *next;
    void* data;
}NODE_t, *NODE;

typedef struct LINKED_STACK_s
{
    NODE head;
}LINKED_STACK_t, *LINKED_STACK;

LINKED_STACK init(){
    LINKED_STACK stack = NULL;
    stack = (LINKED_STACK)malloc(sizeof(LINKED_STACK_t));
    
    if(stack != NULL ){
        stack->head = NULL;
    }

    return stack;
}

LINKED_STACK push(LINKED_STACK stack, void *data){
    NODE tmp = (NODE)malloc(sizeof(NODE_t));

    
    tmp->data = data;
    tmp->next = stack->head;
    stack->head = tmp;

    return stack;
}

LINKED_STACK addEnd(LINKED_STACK stack, void *data)
{
    NODE node = (NODE)malloc(sizeof(NODE_t));

    node->data = data;
    node->next = NULL;
    if(stack->head == NULL)
    {
        stack->head = node;
        return stack;
    }

    NODE iter = stack->head;
    while (iter->next != NULL)
    {
        iter = iter->next;
    }

    iter->next = node;

    return stack;  
}

int search(LINKED_STACK stack, int x){
    NODE node = stack->head;

    while (node != NULL)
    {
        if(node->data == x)
            return 1;

        node = node->next;
    }
    
    return 0;
}

LINKED_STACK reverse(LINKED_STACK stack)
{
    NODE curr = stack->head;
    NODE reversed = init();

    while (curr != NULL)
    {
        reversed = push(reversed, curr->data);
        curr = curr->next;
    }
    
    return reversed;
}

void printNodes(LINKED_STACK stack){
    NODE iter = stack->head;

    while (iter != NULL)
    {
        printf("%d ", iter->data);
        iter = iter->next;
    }
    
}

NODE mergeTwoSortedNode(NODE stack1, NODE stack2){
    NODE node = (NODE)malloc(sizeof(NODE_t));
   
    
    return node;   
}

int main(){
    LINKED_STACK stack = init();

    stack = push(stack, 5);
    stack = push(stack, 1);
    stack = push(stack, 6);

    LINKED_STACK reversed = reverse(stack);

    printNodes(stack);
    printf("\n");
    printNodes(reversed);
    printf("\n");

    return 1;
}