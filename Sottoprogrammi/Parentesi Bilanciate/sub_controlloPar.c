/*

	Una stringa è composta da parentesi tonde bilanciate quando,
	aperta una parentesi tonda essa viene sempre chiusa oppure la
	stringa è direttamente vuota. In caso contrario la stringa non
	è composta da parentesi tonde bilanciate.

	Il programma riceve in ingresso una stringa composta solo da
	parentesi tonde e restituisce 1 se è bilanciata o 0 se non lo è


*/

#include <stdio.h>


#define APERTA '('
#define CHIUSA ')'

int bilanciata (char []);

int main(int argc, char *argv[])
{
	
	return 0;
}

int bilanciata (char testo[]){

	int i, annidamento, ris;

	for(i=0; testo[i]!='\0' && annidamento >= 0; i++){
		if(testo[i] == APERTA){
			annidamento++;
		}
		else if(testo[i] == CHIUSA){
			annidamento--;
		}
		else{
			annidamento = -1;
		}
	}

	if(annidamento == 0){
		ris = 1;
	}
	else{
		ris = 0;
	}


	return ris;
}

