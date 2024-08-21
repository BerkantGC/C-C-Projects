#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

typedef struct {
	int source;
	int destination;
	int weight;
} EDGE;

typedef struct{
	int num_vertices;
	int num_edges;
	EDGE *edges;
} GRAPH;

GRAPH *init_graph(int vertices, int edges);
void fill_graph(GRAPH *graph);

void prims_algorithm(GRAPH *graph);

GRAPH *init_graph(int vertices, int edges) {
	GRAPH *graph = calloc(1, sizeof(*graph));
	if(graph == NULL) {
		printf("Error:");
		exit(EXIT_FAILURE);
	}
	
	graph->num_vertices = vertices;
	graph->num_edges = edges;
	graph->edges = calloc(edges, sizeof(EDGE));
	
	if(graph->edges == NULL){
		printf("Error:");
		exit(EXIT_FAILURE);
	}
	return graph;
}

void fill_graph(GRAPH *graph){
	graph->edges[0].source = 1;
	graph->edges[0].destination = 3;
	graph->edges[0].weight = 12;

	graph->edges[1].source = 1;
	graph->edges[1].destination = 2;
	graph->edges[1].weight = 4;

	graph->edges[2].source = 2;
	graph->edges[2].destination = 5;
	graph->edges[2].weight = 10;

	graph->edges[3].source = 3;
	graph->edges[3].destination = 5;
	graph->edges[3].weight = 2;

	graph->edges[4].source = 3;
	graph->edges[4].destination = 4;
	graph->edges[4].weight = 7;

	graph->edges[5].source = 4;
	graph->edges[5].destination = 5;
	graph->edges[5].weight = 3;

	graph->edges[6].source = 4;
	graph->edges[6].destination = 6;
	graph->edges[6].weight = 8;

	graph->edges[7].source = 5;
	graph->edges[7].destination = 6;
	graph->edges[7].weight = 9;

	graph->edges[8].source = 6;
	graph->edges[8].destination = 7;
	graph->edges[8].weight = 11;

	graph->edges[9].source = 6;
	graph->edges[9].destination = 8;
	graph->edges[9].weight = 1;

	graph->edges[10].source = 7;
	graph->edges[10].destination = 8;
	graph->edges[10].weight = 13;

	graph->edges[11].source = 7;
	graph->edges[11].destination = 10;
	graph->edges[11].weight = 6;

	graph->edges[12].source = 8;
	graph->edges[12].destination = 9;
	graph->edges[12].weight = 5;

	graph->edges[13].source = 9;
	graph->edges[13].destination = 10;
	graph->edges[13].weight = 14;
}

typedef struct
{
	int header;
	int *destination;
	int *weight;
	int num_destination;
	int isVisited;
} VERTICES;

int findMinWeight(VERTICES *vertices, int index)
{
	int j = 0, next = -1, min = -1;
		
		if(vertices[vertices[index].destination[j]].isVisited == 0)
		{
			next = vertices[index].destination[j];
			min = vertices[index].weight[j++];
		}

		printf("%d ", vertices[index].isVisited);

		for(int i = 1; i < vertices[index].num_destination; i++)
		{
			printf("%d ", vertices[index].destination[i]);
			if(min > vertices[index].weight[j] && vertices[vertices[index].destination[j] - 1].isVisited == 0)
			{
				min = vertices[index].weight[j];
				next = vertices[index].destination[j];
			}
			j++;
		}
		vertices[index].isVisited = 1;

		printf("header-> %d weight-> %d destination: %d\n", vertices[index].header, min, next);
	
	return next;
}

void prims_algorithm(GRAPH *graph){
	// TODO: Implement the algorithm.
	// TODO: Print the solutioın.

	int num_vertices= graph->num_vertices;
	VERTICES *vertices = (VERTICES *)malloc(sizeof(VERTICES) * num_vertices);
	int * destination;
	int * weight; 

	int j = 0, num_destination = 0;
	for(int i = 0; i < graph->num_edges; i++)
	{
		vertices[j].destination = realloc(vertices[j].destination, num_destination);
		vertices[j].destination[num_destination] = graph->edges[i].destination;
		
		vertices[j].weight = realloc(vertices[j].weight, num_destination);
		vertices[j].weight[num_destination++] = graph->edges[i].weight;

		vertices[j].num_destination = num_destination;
		vertices[j].isVisited = 0;

		if(graph->edges[i+1].source != graph->edges[i].source)
		{
			num_destination= 0;
			vertices[j].header = graph->edges[i].source;
			
			j++;
		}		
	}

	//checking
	/*for (int i = 0; i < graph->num_vertices; i++)
	{
		printf("header: %d ", vertices[i].header);
		for (int j = 0; j < vertices[i].num_destination; j++)
		{
			printf("destination: %d weight: %d	", vertices[i].destination[j], vertices[i].weight[j]);
		}
		printf("\n");
	}*/
	
	//applying
	findMinWeight(vertices, 0);
	findMinWeight(vertices, 0);

}

int main() {
	GRAPH *graph = init_graph(10, 14);
	fill_graph(graph);
	prims_algorithm(graph);
	return 0;
}
