/*

	Una stringa è composta da parentesi tonde bilanciate quando,
	aperta una parentesi tonda essa viene sempre chiusa oppure la
	stringa è direttamente vuota. In caso contrario la stringa non
	è composta da parentesi tonde bilanciate.

	Il programma riceve in ingresso una stringa che è composta solo
	da parentesi bilanciate e chiama un sottoprogramma che restituisce
	il numero di annidamento delle parentesi.

	Esempio:
				s1 = [""] ---> 0
				s2 = ["() ()"] ---> 1
				s3 = ["(())()"] ---> 2

*/

#include <stdio.h>

#define APERTA '('

int maxAnnidimento (char []);

int main(int argc, char *argv[])
{

	return 0;
}

int maxAnnidimento (char testo[]){

	int i, annidamento, maxAnnidamento;

	annidamento = 0;
	maxAnnidimento = 0;
	for(i=0; testo[i]!='\0'; i++){
		if(testo[i] == APERTA){
			annidamento++;
			if(annidamento > maxAnnidamento){
				maxAnnidimento = annidamento;
			}
		}
		else{
			annidamento--;
		}
	}

	return maxAnnidamento;
	
}
