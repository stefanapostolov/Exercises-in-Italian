/*
	
	Si scriva un sottoprogramma rimuoviDuplicati che ricevuto in ingresso un array di valori interi (e qualsiasi altro parametro ritenuto strettamente necessario)
  trasmetta al chiamante un secondo array contenente i valori dell’array in ingresso privo di duplicati, restituendone il numero di elementi.
	Esempi:
	ingresso: [8,1,2,2,3,6,2,6] uscita: [8,1,2,3,6] ingresso: [7,7,7,7] uscita: [7]
	
*/

#include <stdio.h>



void rimuoviDuplicati (int input[], int dim1[], int output[], int *dim2);

int main(int argc, char *argv[])
{
	
	return 0;
}

void rimuoviDuplicati (int input[], int dim1[], int output[], int *dim2){

	int i, j;
	int outLen, trovato;

	outLen = 0;
	for(i=0; i < dim1; i++){
		trovato = 0;
		for(j=0; j<outLen && trovato == 0; j++){
			if(input[i] == output[j]){
			trovato = 1;
		}
	}

	if(trovato == 0){
		output[outLen] = input[i];
		outLen++;
	}

}

	*dim2 = outLen

}

	
