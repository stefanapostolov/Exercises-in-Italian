#include <stdio.h>
#include <string.h>

#define MAX_LETTERS 100

int main(int argc, char * argv[]){

	char frase[MAX_LETTERS+1], i;
	char frase_nuova[2*MAX_LETTERS+1], j;

	gets(frase);

	puts(frase);

	for(i=0, j=0; frase[i]!='\0'; i++, j++){

		frase_nuova[j] = frase[i];
		if(frase[i] == 'a' || frase[i] == 'e' || frase[i] == 'i' || frase[i] == 'o' || frase[i] == 'u')
			frase_nuova[j+1] = 'f';
		else if(frase[i] == 'A' || frase[i] == 'E' || frase[i] == 'I' || frase[i] == 'O' || frase[i] == 'U')
			frase_nuova[j+1] = 'F';
		j++;
	}
	frase_nuova[j]='\0';

	puts(frase_nuova);
	printf("\n");


	return 0;
}
