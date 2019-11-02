#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

void insere_lista(int pos, int vertex, Vertex_colors *used_colors){
	if(used_colors[pos].vertex == -1){
		// printf("entrou aqui na cor %d com vertice: %d\n", pos+1, vertex);
		used_colors[pos].vertex = vertex;
	}
	else{
		Vertex_colors *new = (Vertex_colors*)malloc(sizeof(Vertex_colors));//pra aparecer na função q vc chamout em q ser ponteiro ne, imbecil
		new->vertex = vertex;
		// printf("entrou aqui na cor %d e ja add vertice: %d\n", pos+1, new->vertex);
		new->next = NULL;
		Vertex_colors *aux = &used_colors[pos];
		while(aux->next != NULL){
			aux = aux->next;
		}
		aux->next = new;
	}
} //inseri na lista