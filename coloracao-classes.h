#ifndef CC_H
#define CC_H

void insere_cor(Num *nodes, Vertex_colors *used_colors, int dim, int**graph, int color, int pos);
void colore(Num *nodes, Vertex_colors *used_colors, int dim, int**graph);
int falta_cor(Num *nodes, int dim);

#endif