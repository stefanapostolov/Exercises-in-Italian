#include <stdio.h>

void calcolaSomme(float ingresso[], int dim, float uscita[]);

int main(int argc, char* argv[]){
	return 0;
}

void calcolaSomme(float ingresso[], int dim, float uscita[])
{
	int i;

	if(dim>0){
		uscita[0] = ingresso[0];
		for(i = 1; i<dim; i++){
			uscita[i] = uscita[i-1] + ingresso[i];
		}
	}
}
