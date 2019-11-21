#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "coloracao-classes.h"
#define MAX_COLORS_INIT 9

//tenho um vetor com as 9 primeiras cores e uma lista com todos os vértices que o usam (eh isto por enqt)
int missing_color(Num *nodes, int dim){
	for(int i = 0; i < dim; i++){
		if(nodes[i].val == 0) return 1;
	}
	return 0;
}

void insert_color(Num *nodes, Vertex_colors *used_colors, int dim, int**graph, int color, int pos){
	for(int i = 0; i < dim; i++){
		if(nodes[i].val == 0){
			Vertex_colors *aux = &used_colors[pos];
			int can = 1;
			while(aux != NULL){
				if(graph[i][aux->vertex] == 1){
					can = 0;
					break;
				}
				aux = aux->next;
			}
			if(can == 1){
				nodes[i].val = color;
				insert_list(pos, i, used_colors);
			}
		}
	}
}

void colorNodes(Num *nodes, Vertex_colors *used_colors, int dim, int**graph){
	for(int i = 1; i <= MAX_COLORS_INIT; i++){
		insert_color(nodes, used_colors, dim, graph, i, i-1);
	}
	int color = 10;
	printf("Cores usadas na sudoku completa: \n");
	for(int i = 0; i < MAX_COLORS_INIT; i++){
		printf("cor %d: ", i+1);
		Vertex_colors *aux = &used_colors[i];
		while(aux->next != NULL){
			printf("%d ", aux->vertex);
			aux = aux->next;
		}
		printf("%d\n", aux->vertex);
	}
	while(missing_color(nodes, dim)){
		Vertex_colors *add_color = (Vertex_colors*)malloc(sizeof(Vertex_colors));
		add_color->vertex = -1;
		add_color->next = NULL;
		insert_color(nodes, add_color, dim, graph, color, 0);
		//printar aqui a lista de cores
		Vertex_colors *aux = add_color;
		printf("cor %d:", color);
		while(aux != NULL){
			printf(" %d", aux->vertex);
			aux = aux->next;
		}
		printf("\n");
		color++;
	}
}
