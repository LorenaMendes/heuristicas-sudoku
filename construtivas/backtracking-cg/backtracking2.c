#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
// Number of vertices in the graph
#define V 81
typedef struct Num{
	int x, y; //coordenadas na sudoku original
	int val; //"cor"
	int block; //"submatriz do sudoku"
} Num;

  
void printSolution(int color[]); 
  
/* A utility function to check if the current color assignment 
is safe for vertex v i.e. checks whether the edge exists or not 
(i.e, graph[v][i]==1). If exist then checks whether the color to  
be filled in the new vertex(c is sent in the parameter) is already 
used by its adjacent vertices(i-->adj vertices) or not (i.e, color[i]==c) */
bool isSafe (int v, bool **graph, int color[], int c) 
{ 
    for (int i = 0; i < V; i++) {
        //printf("------------------ c: %d   color[i]: %d\n", c, color[i]);
        if (graph[v][i] && c == color[i])
            return false; 
    }
    return true; 
}
  
/* A recursive utility function to solve m coloring problem */
bool graphColoringUtil(bool **graph, int m, int color[], int v, int fixed_numbers[]) 
{ 
    /* base case: If all vertices are assigned a color then 
       return true */
    if (v == V){
      return true;
    }
    //printf("Vertice: %d\n",v );
    /* Consider this vertex v and try different colors */
    for (int c = 1; c <= m; c++) 
    { 
        /* Check if assignment of color c to v is fine*/
      if( !fixed_numbers[v]){
        if (isSafe(v, graph, color, c)) 
        { 
           color[v] = c; 
          //printf("==============V: %d   c:%d \n", v, c);
          //printSolution(color);
           /* recur to assign colors to rest of the vertices */
           if (graphColoringUtil(graph, m, color, v+1,fixed_numbers) == true) 
             return true; 
  
            /* If assigning color c doesn't lead to a solution 
               then remove it */
           color[v] = 0; 
        }
      }else{
        return graphColoringUtil(graph, m, color, v+1,fixed_numbers);
       }
    } 
  
    /* If no color can be assigned to this vertex then return false */
    return false; 
} 
  
/* This function solves the m Coloring problem using Backtracking. 
  It mainly uses graphColoringUtil() to solve the problem. It returns 
  false if the m colors cannot be assigned, otherwise return true and 
  prints assignments of colors to all vertices. Please note that there 
  may be more than one solutions, this function prints one of the 
  feasible solutions.*/
bool graphColoring(bool **graph, int m, int colors[], int fixed_numbers[]) 
{ 
    // Initialize all color values as 0. This initialization is needed 
    // correct functioning of isSafe() 
  
    // Call graphColoringUtil() for vertex 0 
    if (graphColoringUtil(graph, m, colors, 0, fixed_numbers) == false) 
    { 
      printf("Solution does not exist"); 
      return false; 
    } 
    else{
    // Print the solution 
    printSolution(colors); 
    return true; }
} 
  
/* A utility function to print solution */
void printSolution(int color[]) 
{ 
    int aux = 0;
    for (int i = 0; i < 9; i++){
      for(int j=0; j < 9; j++){
        printf(" %d ", color[aux]);
        aux++; 
      }
      printf("\n"); 
    }
    printf("\n");
} 
  
// driver program to test above function 
int main() 
{ 
    /* Create following graph and test whether it is 3 colorable 
      (3)---(2) 
       |   / | 
       |  /  | 
       | /   | 
      (0)---(1) 
    */
	int aux,color, count = 0;
  scanf("%d", &aux);
  Num *nodes = (Num*)malloc((aux*aux)*sizeof(Num)); //conf isso aqui
  int colors[V];
  int fixed_numbers[V];
	int subdivision = sqrt(aux);
	for (int i = 0; i < aux; ++i){
		for (int j = 0; j < aux; ++j){
			scanf("%d", &color);
      colors[count] = color;
      if(color != 0)
        fixed_numbers[count]=1;
      else
        fixed_numbers[count]=0;
			nodes[count].x = i;
			nodes[count].y = j;
			nodes[count].val = color;
			if(i < subdivision && j < subdivision) nodes[count].block = 1;
			if(i < subdivision && j >= subdivision && j < 2*subdivision) nodes[count].block = 2;
			if(i < subdivision && j >= 2*subdivision) nodes[count].block = subdivision;
			if(i >= subdivision && i < 2*subdivision && j < subdivision) nodes[count].block = 4;
			if(i >= subdivision && i < 2*subdivision && j >= subdivision && j < 2*subdivision) nodes[count].block = 5;
			if(i >= subdivision && i < 2*subdivision && j > 2*subdivision) nodes[count].block = 2*subdivision;
			if(i > 2*subdivision && j < subdivision) nodes[count].block = 7;
			if(i > 2*subdivision && j >= subdivision && j > 2*subdivision) nodes[count].block = 8;
			if(i > 2*subdivision && j > 2*subdivision) nodes[count].block = 9;
			count++;
		}
	}
	//tem o vetor de nós do grafo, com suas cores previamente definidas e coordenadas na sudoku 
  printSolution(colors);
	for (int i = 0; i < count; ++i){
		//printf("Matrix[%d][%d]: %d\n", nodes[i].x, nodes[i].y, nodes[i].val);
	}
	//printando a matriz do sudoku

	bool **graph = (bool**)malloc((aux*aux)*sizeof(bool*));
	for (int i = 0; i < aux*aux; i++){
		graph[i] = (bool*)malloc((aux*aux)*sizeof(bool));
	}

	//alocando a matriz de adjacencias

	for (int i = 0; i < aux*aux; i++){
		for (int j = 0; j < aux*aux; j++){
			if(i == j) graph[i][j] = 0;
			else if(nodes[i].x == nodes[j].x) graph[i][j] = 1;
			else if(nodes[i].y == nodes[j].y) graph[i][j] = 1;
			else if(nodes[i].block == nodes[j].block) graph[i][j] = 1;
			else graph[i][j] = 0;
		}
	}

	for (int i = 0; i < aux*aux; i++){
		for (int j = 0; j < aux*aux; j++){
			//printf("%d ", graph[i][j]);
        }
    }

    int m = 150; // Number of colors 
    graphColoring(graph, m, colors, fixed_numbers); 
    return 0; 
} 

