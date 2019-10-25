#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define empty 0

typedef struct Num{
	int x, y; //coordenadas na sudoku original
	int val; //"cor"
	int block; //"submatriz do sudoku"
} Num;

int main(int argc, char const *argv[]){
	int dim, color, count = 0;
	scanf("%d", &dim);

	Num *nodes = (Num*)malloc((dim*dim)*sizeof(Num)); //conf isso aqui

	int subdivision = sqrt(dim);
	for (int i = 0; i < dim; ++i){
		for (int j = 0; j < dim; ++j){
			scanf("%d", &color);
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

	for (int i = 0; i < count; ++i){
		printf("Matrix[%d][%d]: %d\n", nodes[i].x, nodes[i].y, nodes[i].val);
	}
	//printando a matriz do sudoku

	int **graph = (int**)malloc((dim*dim)*sizeof(int*));
	for (int i = 0; i < dim*dim; i++){
		graph[i] = (int*)malloc((dim*dim)*sizeof(int));
	}
	//alocando a matriz de adjacencias

	for (int i = 0; i < dim*dim; i++){
		for (int j = 0; j < dim*dim; j++){
			if(i == j) graph[i][j] = 0;
			else if(nodes[i].x == nodes[j].x) graph[i][j] = 1;
			else if(nodes[i].y == nodes[j].y) graph[i][j] = 1;
			else if(nodes[i].block == nodes[j].block) graph[i][j] = 1;
			else graph[i][j] = 0;
		}
	}

	for (int i = 0; i < dim*dim; i++){
		for (int j = 0; j < dim*dim; j++){
			printf("%d ", graph[i][j]);
		}
		printf("\n");
	}


	free(nodes);
	for (int i = 0; i < dim*dim; i++){
		free(graph[i]);
	}
	free(graph);
	return 0;
}