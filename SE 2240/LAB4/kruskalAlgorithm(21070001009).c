#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*DO NOT CHANGE ANY PARAMETER, INCLUDES, STRUCTURES
  DO NOT ADD EXTRA FUNCTIONS, DO NOT CHANGE main and createGraph
  DO NOT ADD EXTRA INCLUDES
  SEND ONLY "graph.txt" and "kruskalLabwork.c
  FILL createUniques, unionFind, kruskalMST and sortEdges FUNCTIONS"
  */

// Edge inside the graph
typedef struct Edge
{
    unsigned int weight;
    unsigned char begin;
    unsigned char end;
} Edge;

// Graph structure
typedef struct Graph
{
    unsigned int size;
    Edge *edges;
} Graph;

// create Graph from file
Graph *createGraph(char *filename)
{
    // open file in read mode 
    FILE *fp = fopen(filename, "r");

    // check if file is there
    if (fp == NULL)
    {
        printf("File not found");
        exit(1);
    }
    else
    {
        // calculate size of the graph by line number
        // initialize begin end, weight

        // create graph
        Graph *graph = malloc(sizeof(Graph));

        // calculate size of the graph by line number. BE CAREFUL with the last line
        int size = 0;
        char c;
        while ((c = fgetc(fp)) != EOF)
        {
            if (c == '\n')
                size++;
        }
        graph->size = ++size;

        // create empty edges by size
        graph->edges = (Edge*)malloc(sizeof(Edge) * size);

        // initialize edges BE CAREFUL about file pointer
        rewind(fp);
        for (int i = 0; i < size; i++)
        {
            fscanf(fp, "%c%c %d\n", &graph->edges[i].begin, &graph->edges[i].end, &graph->edges[i].weight);
        }

        fclose(fp);
        return graph;
    }
}


char* createUniques(Graph *graph) {

    // create empty letters list 2 times plus 1 (for '\0 last char') the size of the graph
    char *letters = (char*)malloc(graph->size*2 + 1);
    /* NOTE: Allocate double size for space begin and end of the edges */
    
    // Combine letters from edge begin char and edge end char
    int i = 0;
    while(i < graph->size)
    {
        letters[i] = graph->edges[i].begin;
        i++;
    }
    while(i < graph->size*2)
    {
        letters[i] = graph->edges[i - graph->size].end;
        i++;
    }
    letters[i] = '\0';

    // sort letters by bubble sort
    for (int j = 1; j < graph->size*2; j++)
    {
        for (int k = 0; k < graph->size*2-1; k++)
        {
            if(letters[k] > letters[k+1])
            {
                int tmp = letters[k];
                letters[k] = letters[k+1];
                letters[k+1] = tmp;
            }
        }
    }
    printf("letters: %s\n", letters);
    
    char * uniques = (char*)malloc(sizeof(char));
    int uniqueNumber = 1;
    // remove duplicates from letters
    int count = graph->size*2;

    // initialize empty unique
    // DONT FORGET reallocate unique each time
    uniques[0] = letters[0];
    for (int j = 0; j < count; j++)
    {
        for(int k = j + 1; letters[k] == letters[j];)
        {
            j++;
        }
        uniques = realloc(uniques, uniqueNumber);
        uniques[uniqueNumber] = letters[j];
        uniqueNumber++;
    }

    // Add '\0' at the end of the string
    uniques = realloc(uniques, uniqueNumber);
    uniques[uniqueNumber-1] = '\0';

    printf("lenght: %d, unique: %s\n", uniqueNumber, uniques);

    // free unused variables   

    free(letters);
    return uniques;
}

// Union find function
/* unionFind is for checking if the edge is a cycle. 
If it is a cycle, do not add it to the minimum spanning tree */
char* unionFind(char *uniques, char cno1, char cno2, unsigned int len)
{
    int i = 0;

    while (i < len)
    {
        if(uniques[i] == cno2)
        {
            uniques[i] = cno1;
        }
        i++;
    }
    
    return uniques;
}

// kruskal mst algorithm
Graph *kruskalMST(Graph *graph)
{
    // allocate empty graph and empty cno1, cno2, indexCno1 and indexCno2
    Graph *mst = (Graph*)malloc(sizeof(Graph));
    mst->size = 0;
    mst->edges = (Edge* )malloc(sizeof(Edge));

    char cno1 = 0, cno2 = 0;
    int indexCno1, indexCno2;

    // create uniques use createUniques function
    char *uniques = createUniques(graph);
    // find length of uniques string
    int i = 0, len = 0;

    while (uniques[i] != '\0')
    {
        len++;
        i++;
    }
    // iterate graph edges

        // assign cno1, cno2 and their indexCno's BE CAREFUL with index of uniques
        for (int  j = 0; j < graph->size; j++)
        {
            indexCno1 = graph->edges[j].begin - 'A';
            indexCno2 = graph->edges[j].end - 'A';

            cno1 = uniques[indexCno1];
            cno2 = uniques[indexCno2];

            if(cno1 != cno2)
            {
                mst->size++;
                mst->edges = realloc(mst->edges, sizeof(Edge) * mst->size);

                mst->edges[mst->size-1] = graph->edges[j];

                unionFind(uniques, cno1, cno2, len);
            }
        }
        printf("\n\n");
        // check if begin and end are in the same set

            // add to mst if they are not in the same set,  DONT FORGET reallocte mst edges

            // update uniques use unionFind function
    
    return mst;
}


// sort edges by weight use bubble sort
Graph * sortEdges(Graph *graph)
{

    for (int i = 1; i < graph->size; i++)
    {
        for (int j = 0; j < graph->size-1; j++)
        {
            if(graph->edges[j].weight > graph->edges[j+1].weight)
            {
                Edge tmp = graph->edges[j];
                graph->edges[j] = graph->edges[j+1];
                graph->edges[j+1] = tmp;
            }
        }
    }

    return graph;
}

int main()
{
    // create graph;
    Graph *graph = createGraph("graph.txt");
    
    // sort graph for kruskal algorithm when getting minimum weight
    graph = sortEdges(graph);

    // kruskal minimum spanning tree
     Graph *mst = kruskalMST(graph);

    // // print minimum spanning tree
    for (int i = 0; i < mst->size; i++)
    {
        printf("%d.) %c%c %d\n",(i+1), mst->edges[i].begin, mst->edges[i].end, mst->edges[i].weight);
    }

    // calculate total weight of the minimum spanning tree
    int totalWeight = 0;
    for (int i = 0; i < mst->size; i++)
    {
        totalWeight += mst->edges[i].weight;
    }
    printf("Total weight of the minimum spanning tree: %d\n", totalWeight);

    // dont forget to free memory otherwise you will get memory leak
    free(graph);
    free(mst);

    return 0;
}