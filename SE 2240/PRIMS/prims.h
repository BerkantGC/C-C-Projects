#include "graph.h"

GRAPH prims(GRAPH graph);

void makeEmptyArray(int *array, int size)
{
	for(int i = 0; i < size; i++){
		array[i] = 0;
	}
}

void makePrims(GRAPH graph, GRAPH MST){

	int size = graph->size;

	//init a graph with same size of graph to store edges
	GRAPH tmpEdges = graph_init(size);

	//array to check changed or not
	int *changedVertices = (int *)malloc(sizeof(int) * size);

	//keep first start index
	int beginning = 0, tmpI, tmpJ;

	makeEmptyArray(changedVertices, size);

	for (int counter = size - 1; counter > 0; counter--)
	{
		// Tmp edge tüm ihtimal edgelerini atıyor
		for(int end = 0; end < size; end++)
		{
			//add all possible edge to tmpEdges
			if( graph->matrix[beginning][end] != 0 )
				graph_addEdge(tmpEdges, beginning, end, graph->matrix[beginning][end]);

		}

		//make vertices checked
		changedVertices[beginning] = 1;

		//set indexes will changed to start
		tmpI = 0, tmpJ = 0;

		for(int i = 0; i < size; i++){
			for(int j = 0; j < size; j++){
				
				//if vertices is not changed and there is edge between i and j, make smallest (tmpI, tmpJ) i and j
				if(changedVertices[j] == 0 && tmpEdges->matrix[i][j] != 0)
				{
					tmpI = i;
					tmpJ = j;
				}

				//if vertices is not changed and newIndexes is smaller than smallest indexes selected before, make smallest (tmpI, tmpJ) i and j
				if(changedVertices[j] == 0 && tmpEdges->matrix[i][j] < tmpEdges->matrix[tmpI][tmpJ] && tmpEdges->matrix[i][j] != 0)
				{
					tmpI = i;
					tmpJ = j;
				}

			}
		}
		
		beginning = tmpJ;
		changedVertices[tmpJ] = 1;

		graph_addEdge(MST,tmpI,tmpJ,graph->matrix[tmpI][tmpJ]);
	}

	free(changedNodes);

	graph_free(tmpEdges);
}

GRAPH prims(GRAPH graph) {	

	GRAPH MST = graph_init(graph->size);

	makePrims(graph, MST);

	return MST;
}

