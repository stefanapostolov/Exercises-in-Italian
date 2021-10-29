/*
	
	Si scriva un sottoprogramma che ricevuti in ingresso due numeri interi (sicuramente positivi o nulli) ritorni 1 se i due numeri sono coprimi, 
	0 altrimenti.
	Due numeri si dicono coprimi se non hanno divisori comuni a parte 1; 1 è coprimo con ogni numero, mentre 0 è coprimo solo di 1.
	
*/

#include <stdio.h>



int coprimi(int a, int b);

int main(int argc, char *argv[])
{

	return 0;
}

int coprimi(int a, int b){

	int min;
	int ris, i;

	if(a == 1 || b == 1){
		ris = 1;
	} else if (a == 0 || b == 0){
		ris = 0;
	} else {
		if(a < b){
			min = a;
		} else {
			min = b
		}

		ris = 1;
		for(i=2; i<=min && ris == 1; i++){
			if(a % i == 0 && b % i == 0){
				ris = 0;
			}
		}

	}

	return ris;

}
