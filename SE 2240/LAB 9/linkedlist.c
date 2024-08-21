#include <stdio.h>
#include <stdlib.h>

typedef struct LINKED_NODE_s
{
    void *data;
    struct LINKED_NODE_s *next;
} LINKED_NODE_t[1] , *LINKED_NODE;

typedef struct LINKED_LIST_s
{
    LINKED_NODE head;
}LINKED_LIST_t[1], *LINKED_LIST;

LINKED_LIST init()
{
    LINKED_LIST list = (LINKED_LIST)malloc(sizeof(LINKED_LIST_t));

    if(list != NULL)
    {
        list->head = NULL;
        return list;
    }
    else return NULL;
}

void push(LINKED_LIST list, void *data)
{
    LINKED_NODE node = (LINKED_NODE)malloc(sizeof(LINKED_NODE_t));
    node->data = data;

    if(list->head == NULL)
    {
        list->head = node;
        node->next = NULL;
    }

    else{
        node->next = list->head;
        list->head = node;
    }
}

int pop(LINKED_LIST list)
{
    if(list->head == NULL)
        return NULL;

    LINKED_NODE node = list->head;
    list->head = node->next;

    int data = node->data;

    free(node);
    return data;
}

void printList(LINKED_LIST list)
{
    LINKED_NODE iter = list->head;

    while (iter != NULL)
    {
        printf("%d ", iter->data);
        iter = iter->next;
    }
    printf("\n");
}

int depthFirstSearch(int graph[5][5], int index)
{
    for (int i = 0; i < 5; i++)
    {
        if(graph[index][i] != 0)
        {
            index = depthFirstSearch(graph, i);
        }
    }

    return index;
}

void printMatrix(int graph[5][5])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

void delete(int graph[5][5], int index)
{
    for (int i = 0; i < 5; i++)
    {
        graph[index][i] = 0;
        graph[i][index] = 0;
    }
}

int canGo(int graph[5][5], int i)
{
    for (int j = 0; j < 5; j++)
    {
        if(graph[i][j] == 1)
        {
            return 1;
        }
    }
    return 0;    
}

LINKED_LIST topologicalOrder(LINKED_LIST list, int graph[5][5], int n){
    int sum, indegreeArray[n], outdegreeArray[n];

    for (int k = 0; k < n; k++)
    {
        sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum += graph[i][k];   
        }
        indegreeArray[k] = sum;

        printf("indegreeOf %d : %d\n", k, indegreeArray[k]);
    }

    for (int k = 0; k < n; k++)
    {
        sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum += graph[k][i];   
        }
        outdegreeArray[k] = sum;
        printf("outdegree of %d : %d\n", k, sum);
    }

    for (int i = 0; i < n; i++)
    {
        if(indegreeArray[i] == 0)
        {               
            while (canGo(graph, i))
            {
                int deleted = depthFirstSearch(graph, i);
                push(list, deleted);
                delete(graph, deleted);
            }
            push(list, i);
            delete(graph, i);
        }
    }
    
    return list;
}

int checkAcycle(int indegrees[5])
{
    for (int j = 0; j < 5; j++)
    {
        if(indegrees[j] == 0)
        {
            return 1;
        }
    }

    return 0;
}

void updateIndegrees(int graph[5][5], int indegreesArray[5], int index)
{   
    for (int i = 0; i < 5; i++)
    {
        if(graph[index][i] == 1)
        {    
           indegreesArray[i] -= 1;
        }
    }
    
}

void topologicalOrderV2(int graph[5][5], int n){

    int numVisitedVertices = 0;

    int a[n];

    int sum;

    for (int k = 0; k < n; k++)
    {
        sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum += graph[i][k];   
        }
        a[k] = sum;

        printf("indegreeOf %d : %d\n", k, a[k]);
    }

    for (int i = 0; i < n; i++)
    {
        if(checkAcycle(a) == 0)   
        {
            break;
        }

        if(a[i] == 0)
        {
            numVisitedVertices++;
    
            updateIndegrees(graph, a, i);

            delete(graph, i);
        }

        printf("%d ", i);
    }
        
}

int main(int argc, char const *argv[])
{
    LINKED_LIST list = init();

    int graph[5][5] = {
          //0  1  2  3  4
    /*0*/  {0, 1, 1, 1, 0},
    /*1*/  {0, 0, 0, 1, 1},
    /*2*/  {0, 0, 0, 0, 0},
    /*3*/  {0, 0, 1, 0, 1},
    /*4*/  {0, 0, 0, 0, 0}
    };
    
    int visited[5];

    //topologicalOrder(list, graph, 5);
    topologicalOrderV2(graph, 5);

    printList(list);

    return 0;
}

