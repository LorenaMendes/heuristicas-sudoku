#include "coloracao-classes.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

void swap(Num *nodes, int index1, int dim){
	int index2 = rand()%(dim*dim);
	while(nodes[index1].val == nodes[index2].val || nodes[index2].pre_def){
		index2 = rand()%(dim*dim);
	}
	int temp = nodes[index1].val;
	nodes[index1].val = nodes[index2].val;
	nodes[index2].val = temp;
}

int is_valid_config(int **graph, Num *nodes, int dim){
	//retorna -1 se FOR VALIDA e o indice se n for valida
	for(int i = 0; i < dim*dim; i++){
		for(int j = i+1; j < dim*dim; j++){
			if(graph[i][j] && nodes[i].val == nodes[j].val){
				return j; //troca a de um deles, e vai ser do j pq sim
			}
		}
	}
	return -1;
}

void metaheuristica(int **graph, Num *nodes, int dim){

	int maior = 0;
	int index = -1;
	for(int i = 0; i < dim*dim; i++){
		if(nodes[i].val > maior){
			maior = nodes[i].val;
			index = i;
		}
	}
	nodes[index].val = maior - 1; //diminuiu a cor

	while(1){
		int valid = is_valid_config(graph, nodes, dim);
		if(valid == -1) break; //assim por enqt
		else{
			swap(nodes, valid, dim);
		}
	}
}