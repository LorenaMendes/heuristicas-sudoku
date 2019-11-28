#ifndef META_H
#define META_H

void metaheuristica(int **graph, Num *nodes, int dim);
int is_valid_config(int **graph, Num *nodes, int dim);
void swap(Num *nodes, int index1, int dim);

#endif