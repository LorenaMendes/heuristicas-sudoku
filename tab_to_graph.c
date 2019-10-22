#include <stdio.h>
#define empty 0

typedef struct Num{
	int x, y;
	int val;
} Num;

int main(int argc, char const *argv[]){
	int dim, aux, count = 0;
	scanf("%d", &dim);

	Num vector[dim*dim];

	for (int i = 0; i < dim; ++i){
		for (int j = 0; j < dim; ++j){
			scanf("%d ", &aux);
			if(aux != empty){
				Num new;
				new.x = i;
				new.y = j;
				new.val = aux;
				vector[count] = new;
				count++;
			}
		}
	}

	for (int i = 0; i < count; ++i){
		printf("%d - ", vector[i].val);
	}

	return 0;
}