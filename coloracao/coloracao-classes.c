#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "coloracao-classes.h"
#define MAX_COLORS_INIT 9

//tenho um vetor com as 9 primeiras cores e uma lista com todos os vértices que o usam (eh isto por enqt)
int falta_cor(Num *nodes, int dim){
	for(int i = 0; i < dim; i++){
		if(nodes[i].val == 0) return 1;
	}
	return 0;
}

void insere_cor(Num *nodes, Vertex_colors *used_colors, int dim, int**graph, int color, int pos){
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
				insere_lista(pos, i, used_colors);
			}
		}
	}
}

// void insere_cor_restante(Num *nodes, Vertex_colors *used_color, int dim, int **graph, int color){
// 	for(int i = 0; i < dim; i++){
// 		if(nodes[i].val == 0){
// 			Vertex_colors *aux = &used_colors[0];//ver se eh isso
// 			int can = 1;
// 			while(aux != NULL){
// 				if(graph[i][aux->vertex] == 1){
// 					can = 0;
// 					break;
// 				}
// 				aux = aux->next;
// 			}
// 			if(can == 1){
// 				nodes[i].val = color;
// 				insere_lista(0, i, used_colors);
// 			}
// 		}
// 	}
// }

void colore(Num *nodes, Vertex_colors *used_colors, int dim, int**graph){
	for(int i = 1; i <= MAX_COLORS_INIT; i++){
		insere_cor(nodes, used_colors, dim, graph, i, i-1);
	}
	int cor = 10;
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
	while(falta_cor(nodes, dim)){
		Vertex_colors *cor_restante = (Vertex_colors*)malloc(sizeof(Vertex_colors));
		cor_restante->vertex = -1;
		cor_restante->next = NULL;
		insere_cor(nodes, cor_restante, dim, graph, cor, 0);
		//printar aqui a lista de cores
		Vertex_colors *aux = cor_restante;
		printf("cor %d:", cor);
		while(aux != NULL){
			printf(" %d", aux->vertex);
			aux = aux->next;
		}
		printf("\n");
		cor++;
	}
}

// void colore(/*por parametros aqui*/){
// 	while(/*grafo nao esta totalmente colorido*/){
// 		//tenho um vetor com as 9 primeiras cores: se cor nao esta no vetor, pega a menor
// 		//se é maior q 9 -> ai so vai aumentando sem ver 
// 		//sepa é melhor fazer uma lista encadeada (cria um no por cor usada e verifica tamanho - > firula)
// 	}
// }