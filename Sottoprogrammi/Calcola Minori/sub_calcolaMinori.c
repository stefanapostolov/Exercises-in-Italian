/*

	Si scriva un sottoprogramma calcolaMinori che ricevuto in ingresso un array di valori interi val (e qualsiasi altro paramet- ro ritenuto strettamente 		necessario), e trasmetta al chiamante un secondo array min, tale per cui l’elemento i-esimo min[i] corrisponde al numero di valori di val minori di 		val[i].
	Esempi:
	ingresso: [8,1,2,2,3] uscita: [4,0,1,1,3] ingresso: [7,7,7,7] uscita: [0,0,0,0]


*/

#include <stdio.h>


void calcolaMinori(int input[], int dim1, int output[], int * dim2);

int main(int argc, char *argv[]){

	return 0; 

}

void calcolaMinori(int input[], int dim1, int output[], int * dim2){


	int i, j, maxMinori;

	for(i=0; i<dim1; i++){
		maxMinori = 0;
		for(j=0; j<dim1; j++){
			if(input[i] > input[j]){
				maxMinori++
			}
		}

		output[i] = maxMinori;
	}

	*dim2 = dim1;
	
}
