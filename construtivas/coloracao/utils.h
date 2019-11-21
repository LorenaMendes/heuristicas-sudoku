#ifndef UTILS_H
#define UTILS_H


typedef struct Num{
	int x, y; //coordenadas na sudoku original
	int val; //"cor"
	int block; //"submatriz do sudoku"
} Num;

typedef struct Vertex_colors Vertex_colors;
struct Vertex_colors{
	Vertex_colors *next;
	int vertex;
};

void insert_list(int, int, Vertex_colors*);

#endif