#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode ListNode;

struct ListNode {
      int val;
      struct ListNode *next;
 };
  
 
struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode * iter = head;

    ListNode * tmp = malloc(sizeof(ListNode));

    while (iter->next != NULL)
    {
        ListNode * nodeToDelete = iter->next;
        if(nodeToDelete->val == iter->val)
        {
            tmp->val = iter->val;
            tmp->next = nodeToDelete->next;
            iter->next = tmp;
            free(nodeToDelete);
        }
        iter = iter->next;
    }
    return head;
}

int main()
{
    return 0;
}