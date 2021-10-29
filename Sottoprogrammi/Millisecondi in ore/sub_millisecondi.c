#include <stdio.h>

#define CONVERSIONE 1000
#define OREINSEC 3600
#define SECINMIN 60

int millisecondi(int, int, int);


int main(int argc, char* argv[]){

	int ore, minuti, secondi;
	int millisecondi;

	millisecondi = millisecondi(ore, minuti, secondi);

	printf("%d", millisecondi);

	

	return 0;
}

int millisecondi(int ore, int minuti, int secondi)
{
	int oreInSec, minutiInSec;
	int millisecondi;

	oreInSec = ore / OREINSEC;
	minutiInSec = minuti / SECINMIN;

	millisecondi = (oreInSec+minutiInSec+secondi)*CONVERSIONE;

	return millisecondi;

}
