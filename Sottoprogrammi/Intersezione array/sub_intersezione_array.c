#include <stdio.h>

void intersezione(int ingresso[], int dim, int ingresso2[], int dim2, int uscita[], int* dim3);

int main(int argc, char* argv[]){


	return 0;
}

void intersezione(int ingresso[], int dim, int ingresso2[], int dim2, int uscita[], int* dim3)
{
	
	int i,j;
	int contoComuni;

	contoComuni = 0;
	for(i=0; i<dim; i++){
		for(j=0; j<dim2 && ingresso[i]!=ingresso2[j] j++){
			
		}
		if(j<dim2 && ingresso[i]==ingresso2[j]){
			uscita[contoComuni] = ingresso[i];
			contoComuni++;
		}
	}
	*dim3 = contoComuni;

}
