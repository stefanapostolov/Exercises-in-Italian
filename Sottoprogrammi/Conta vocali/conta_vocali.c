#include <stdio.h>
#include <string.h>

#define MAX_LETTERS 100


int main(int argc, char * argv[]){
	
	char testo[MAX_LETTERS+1], testo_nuovo[MAX_LETTERS+1], i, j;

	gets(testo);

	puts(testo);
	printf("\n");

	for(i=0, j=0; testo[i]!='\0'; i++, j++){

		if(testo[i] == '.')
			testo_nuovo[j] = '\n';
		else
			testo_nuovo[j] = testo[i];
	}
	testo_nuovo[j+1]='\0';

	puts(testo_nuovo);


	return 0;
}