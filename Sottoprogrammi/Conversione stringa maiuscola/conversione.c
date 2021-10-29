#include <stdio.h>

#define CONVERSION_CONST ('A'-'a')

void conversioneStringa (char frase[]);

int main(int argc, char* argv[]){


	return 0;
}

void conversioneStringa (char frase[])
{
	int i;

	for(i=0; frase[i]!='\0'; i++){
		if(frase[i]>='a' && frase[i]<= 'z'){
		frase[i] = frase[i] + CONVERSION_CONST;
		}
	}
}


