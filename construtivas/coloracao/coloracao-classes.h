#ifndef CC_H
#define CC_H

#include "utils.h"

void insert_color(Num *nodes, Vertex_colors *used_colors, int dim, int**graph, int color, int pos);
void colorNodes(Num *nodes, Vertex_colors *used_colors, int dim, int**graph);
int missing_color(Num *nodes, int dim);

#endif