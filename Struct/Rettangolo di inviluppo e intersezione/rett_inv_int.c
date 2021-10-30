/*

	Si scriva poi un programma che, dati due rettangoli con i 
	lati paralleli agli assi: 
	
	Verifichi che i due rettangoli dati siano “corretti” (ovvero che il vertice di 
	NO sia effettivamente a nord-ovest rispetto al vertice di SE).

	Calcoli il loro rettangolo di inviluppo (definito successivamente).

	Calcoli, se esiste, il rettangolo di intersezione, oppure segnali che i rettangoli 
	sono interamente non sovrapposti (cioè del tutto disgiunti).

*/

#include <stdio.h>
#include <math.h>

typedef struct punto_s {

	float x;
	float y;

} punto_t;

typedef struct rettangolo_s {

	punto_t NordOvest;
	punto_t SudEst;

} rettangolo_t;

int degenere(rettangolo_t r);

rettangolo_t inviluppo (rettangolo_t r1, rettangolo_t r2);

rettangolo_t intersezione (rettangolo_t r1, rettangolo_t r2);

rettangolo_t leggirettangolo();

punto_t leggipunto();

void stamparect(rettangolo_t r);

int intersezioneVuota(rettangolo_t r1, rettangolo_t r2);

int main(int argc, char * argv[])
{

	rettangolo_t re1, re2;
	rettangolo_t inv, inters;

	printf("Inserisci il primo rettangolo:\n");
	re1 = leggirettangolo();
	printf("Inserisci il secondo rettangolo:\n");
	re2 = leggirettangolo();

	printf("L'inviluppo dei due rettangoli e':\n");
	inv = inviluppo(re1, re2);
	stamparect(inv);

	printf("\n");
	if(intersezioneVuota(re1, re2)){
		printf("L'intersezione dei rettangoli e' vuota:\n");
	} else {
		printf("L'intersezione dei rettangoli e': \n");
		inters = intersezione(re1, re2);
		stamparect(inters);
	}

	return 0;
}

/* Verifica che il rettangolo sia ben formato*/

int degenere(rettangolo_t r){

	return r.NordOvest.x >= r.SudEst.x || r.NordOvest.y <= r.SudEst.y ;

}

/* Lettura dei punti */

punto_t leggipunto(){

	punto_t risultato;

	printf("Coordinate x del punto:\n");
	scanf("%f", &risultato.x);
	printf("Coordinate y del punto:\n");
	scanf("%f", &risultato.y);
	
	return risultato;

}

/* Lettura dei rettangoli */

rettangolo_t leggirettangolo(){

	rettangolo_t risultato;

	do{
		printf("\n Vertice di Nord-Ovest\n");
		risultato.NordOvest = leggipunto();
		printf("\n Vertice di Sud-Est\n");
		risultato.SudEst = leggipunto();
		if(degenere(risultato))
			printf("Le coordinate non rappresentano un rettangolo ben formato. Riproviamo.\n");
	} while(degenere(risultato));

	return risultato;

}

/* Rettangolo di inviluppo */

rettangolo_t inviluppo (rettangolo_t r1, rettangolo_t r2){

	rettangolo_t i;
	
	i.NordOvest.x = fmin(r1.NordOvest.x, r2.NordOvest.x);
	i.NordOvest.y = fmax(r1.NordOvest.y, r2.NordOvest.y);
	i.SudEst.x = fmax(r1.SudEst.x, r2.SudEst.x);
	i.SudEst.y = fmin(r1.SudEst.y, r2.SudEst.y);
	
	return i;
}

/* Stampa del rettangolo */ 

void stamparect(rettangolo_t r){

	printf("Rettangolo:\n");
	printf("NO: [ %2.2f, %2.2f ]\n", r.NordOvest.x, r.NordOvest.y);
	printf("SE: [ %2.2f, %2.2f ]\n", r.SudEst.x, r.SudEst.y);

}

/* Rettangolo di intersezione */ 

rettangolo_t intersezione (rettangolo_t r1, rettangolo_t r2){

	rettangolo_t i;

	i.NordOvest.x = fmax(r1.NordOvest.x, r2.NordOvest.x);
	i.NordOvest.y = fmin(r1.NordOvest.y, r2.NordOvest.y);
	i.SudEst.x = fmin(r1.SudEst.x, r2.SudEst.x);
	i.SudEst.y = fmax(r1.SudEst.y, r2.SudEst.y);

	return i;
}

/* Verifica intersezione vuota */

int intersezioneVuota(rettangolo_t r1, rettangolo_t r2){

	return degenere(intersezione(r1, r2));

}
