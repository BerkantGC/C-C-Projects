#include "linkedstack.h"
#include <stdio.h>

typedef struct 
{
	int R;
	int C;
} POS_t[1], *POS;


void printStack(LINKED_STACK stack)
{
    POS pos;
    
    LINKED_STACK_NODE node;
    node = stack->head;
    
	while(node != NULL)
	{
		pos = (POS)node->data;
		printf("(%d,%d) ", pos->R, pos->C);
		
		node = node->next;
	}
	printf("\n");
}

void printMaze(int M[8][8])
{
		for(int i = 0; i < 8; i++)
	    {
		for(int j = 0; j < 8; j++)
		{
			if(M[i][j] == -1)
			printf("%d  ", M[i][j]);
			else printf(" %d  ", M[i][j]);
		}
		printf("\n");
	    }
	    
	    printf("\n\n\n");    
}

void solve_maze() {
	
	int M[8][8] =
	 {
		/* R\C   0  1  2  3  4  5  6  7 */
		/* 0 */ {0, 0, 0, 1, 0, 0, 0, 0},
		/* 1 */ {0, 1, 1, 1, 0, 0, 1, 0},
		/* 2 */ {0, 1, 0, 1, 0, 0, 1, 0},
		/* 3 */ {0, 1, 0, 1, 1, 1, 1, 0},
		/* 4 */ {0, 1, 0, 0, 0, 0, 1, 1},
		/* 5 */ {0, 1, 1, 0, 1, 1, 1, 0},
		/* 6 */ {0, 0, 0, 0, 1, 0, 0, 0},
		/* 7 */ {0, 0, 0, 0, 1, 0, 0, 0},
	};
	
	int I, J, R = 0, C = 3;
	
	LINKED_STACK stack = linked_stack_init();
	POS pos = (POS)malloc(sizeof(POS));
	POS entrancepair = (POS)malloc(sizeof(POS));
    POS posIJ;
	
	//int flag;
	
	//First step!**
	pos->C = C;
	pos->R = R;
	
	linked_stack_push(stack, pos);
	
	entrancepair = pos;
	M[R][C] = 2;
	//**

	do
	{
		// TODO: Fill this block.
	
		POS pos = (POS)malloc(sizeof(POS));
		printStack(stack);
		
		if(M[R-1][C] == 1 || M[R][C+1] == 1 || M[R+1][C] == 1 || M[R][C-1] == 1)
		{
			if(M[R-1][C] == 1)
			{
			
		    I = R - 1, J = C;
		    posIJ = (POS)malloc(sizeof(POS));
		    posIJ->R = I;
			posIJ->C = J;
			
		
			linked_stack_push(stack, posIJ);
			M[I][J] = 2;
			}
		
		
			if(M[R][C+1] == 1)
			{   
		    I = R, J = C + 1;
		    
		    posIJ = (POS)malloc(sizeof(POS));
		    posIJ->R = I;
			posIJ->C = J;
		
			linked_stack_push(stack, posIJ);
			M[I][J] = 2;
			}
		
		
			if(M[R+1][C] == 1)
			{
			    I = R + 1, J = C;
			    
			   posIJ = (POS)malloc(sizeof(POS));
		       posIJ->R = I;
			   posIJ->C = J;
			
		
			   linked_stack_push(stack, posIJ);
			   M[I][J] = 2;
			}
			
			
			if(M[R][C-1] == 1)
			{   
			    I = R, J = C - 1;
			    
			    posIJ = (POS)malloc(sizeof(POS));
		        posIJ->R = I;
			    posIJ->C = J;
			
		
			   linked_stack_push(stack, posIJ);
			   M[I][J] = 2;
			}
	    }
	    
	    else
		{
	    	linked_stack_pop(stack);
			M[R][C] = -1;	
		}
		
		printMaze(M);
		
	    pos = (POS)linked_stack_top(stack);
	    R = pos->R;
		C = pos->C;
	    
	} while (R != 7 && C != 7 && R != 0 && C != 0);
	
    if(R == entrancepair->R && C == entrancepair->C)
    {
    	printf("There is no exit from maze!\n");
	}
	
	else
	{
		printf("Exit pair is (%d, %d)\n", R, C);
	}

	linked_stack_free(stack);
	free(entrancepair);
	free(pos);
	free(posIJ);

}

