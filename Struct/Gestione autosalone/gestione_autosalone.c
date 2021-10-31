/*

	Scrivere un programma per la gestione di un autosalone che 
	memorizzi per ogni auto modello, targa, colore, prezzo. 
	Definire le strutture dati necessarie a memorizzare una 
	automobile e dichiarare una variabile per memorizzare al 
	massimo 100 auto. 
	
	Chiedere all'utente di inserire i dati di n auto (con n definito 
	dall'utente e minore di 100). Dopo l'inserimento permettere all'utente
	di cercare un'auto tramite la targa.

*/

#include <stdio.h>
#include <string.h>


#define MAX_LEN 10

#define MAX_AUTO 100


typedef struct automobile_s
{
	
	char modello[MAX_LEN+1];
	char targa[MAX_LEN+1];
	char colore[MAX_LEN+1];
	float prezzo;

} automobile_t;

automobile_t leggiauto();

int main(int argc, char * argv[]){

	automobile_t aut[MAX_AUTO];
	char targa[MAX_LEN];
	int i;
	int n;
	int trovata;

	do{
		printf("Inserisci il numero di auto da memorizzare:\n");
		scanf("%d", &n);
		if(n<=0 || n>100){
			printf("Hai inserito un numero invalido. Riproviamo\n");
		}
	} while(n<=0 || n>100);

	for(i=0; i<n; i++)
		aut[i] = leggiauto();

	printf("Inserisci la targa dell'auto desiderata:\n");
	scanf("%s", targa);

	trovata = 0;
	for(i=0; i<n && trovata == 0; i++){
		if(strcmp(aut[i].targa, targa) == 0){
			trovata = 1;
		}
	}

	if(trovata == 1){

		printf("Modello: %s\n", aut[i-1].modello);
		printf("Targa: %s\n", aut[i-1].targa);
		printf("Colore: %s\n", aut[i-1].colore);
		printf("Prezzo: %f\n", aut[i-1].prezzo);

	
	} else {

		printf("L'auto non e' stata trovata.\n");

	}


	return 0;
}

automobile_t leggiauto(){

	automobile_t ris;

	printf("Inserisci il modello dell'auto:\n");
	scanf("%s", ris.modello);
	printf("Inserisci la targa dell'auto:\n");
	scanf("%s", ris.targa);
	printf("Inserisci il colore dell'auto:\n");
	scanf("%s", ris.colore);
	printf("Inserisci il prezzo dell'auto:\n");
	scanf("%f", &ris.prezzo);

	return ris;

}

