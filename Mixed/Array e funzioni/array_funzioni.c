/*

	Scrivere un programma che chieda all’utente di inserire due sequenze 
	di N numeri ed esegua le seguenti operazioni, la sequenza termina
	quando viene inserito un valore negativo: 
	
		A. dica quale dei due array ha valore medio più alto;
		
		B. calcoli l'array concatenato tra i due array in ingresso;
		
		C. trovi il massimo ed il minimo tra tutti i valori inseriti, 
		   indicando in quale dei due array sono presenti i due valori 
		   di massimo e minimo;
		
		D. stampi a video il loro prodotto scalare; 

	Prodotto scalare tra vettori - [a b c d e] * [f g h i l]' = af + bg + ch + di + el
 
 */


#include <stdio.h>

#define MAX_NUM 50

//Prototipi delle funzioni

/* In base al valore medio degli array, la funzione restituisce 1
   se il primo array ha valore medio più alto, 2 se il secondo */

int maxAvg (int a1[], int dim1, int a2[], int dim2);

/* La funzione trasmette al chiamante l'array concatenato tra i due
   array d'ingresso */

void concArray (int a1[], int dim1, int a2[], int dim2, int conc[], int *dim3);

/* La funzione trova il massimo ed il minimo tra tutti i valori inseriti, 
   indicando in quale dei due array sono presenti i due valori di massimo
   e minimo, restituendo 1 se si trovano nel primo, 2 nel massimo */

void minMax (int a1[], int dim1, int a2[], int dim2, int *min, int *max, int *pmin, int *pmax);

/* La funzione restituisce al chiamante il prodotto scalare tra i due array */

int prodScal (int a1[], int dim1, int a2[], int dim2);

/* La funzione stampa l'array fornito */

void stampaArray (int a[], int dim);

int main(int argc, char * argv[]){

	int seq1[MAX_NUM], N1;
	int seq2[MAX_NUM], N2;
	float avg;
	int concatenato[MAX_NUM*2], N3;
	int massimo, minimo;
	int prodotto_scalare;
	int i, j;
	int curNum;
	int posizioneMin, posizioneMax;

	printf("Inserisci il valore del 1o numero della prima sequenza:\n");
	scanf("%d", &curNum);
	N1 = 0;
	for(i=0, j=1; i<MAX_NUM && curNum >= 0; i++, j++){
		seq1[i] = curNum;
		N1++;
		printf("Inserisci il valore del %do numero della prima sequenza:\n", j+1);
		scanf("%d", &curNum);
	}
	printf("\n");

	printf("Inserisci il valore del 1o numero della seconda sequenza:\n");
	scanf("%d", &curNum);
	N2 = 0;
	for(i=0, j=1; i<MAX_NUM && curNum >= 0; i++, j++){
		seq2[i] = curNum;
		N2++;
		printf("Inserisci il valore del %do numero della seconda sequenza:\n", j+1);
		scanf("%d", &curNum);
	}
	printf("\n");

	avg = maxAvg(seq1, N1, seq2, N2);

	if(avg == 1){
		printf("Il valore medio piu' alto si trova nella prima sequenza.\n ");
	} else if(avg == 2) {
		printf("Il valore medio piu' alto si trova nella seconda sequenza.\n");
	} else {
		printf("Il valore medio e' lo stesso per entrambe le sequenze.\n");
	}
	printf("\n");

	concArray(seq1, N1, seq2, N2, concatenato, &N3);

	stampaArray(concatenato, N3);
	printf("\n");

	minMax(seq1, N1, seq2, N2, &minimo, &massimo, &posizioneMin, &posizioneMax);

	if(posizioneMin == 1){
		printf("Il valore minimo si trova nella prima sequenza.\n ");
	} else if(posizioneMin == 2) {
		printf("Il valore minimo si trova nella seconda sequenza.\n");
	} else {
		printf("Il valore minimo e' lo stesso per entrambe le sequenze.\n");
	}

	if(posizioneMax == 1){
		printf("Il valore massimo si trova nella prima sequenza.\n ");
	} else if(posizioneMax == 2) {
		printf("Il valore massimo si trova nella seconda sequenza.\n");
	} else {
		printf("Il valore massimo e' lo stesso per entrambe le sequenze.\n");
	}
	printf("\n");

	if(N1 == N2){
		prodotto_scalare = prodScal(seq1, N1, seq2, N2);
		printf("Il prodotto scalare tra le due sequenze e': %d\n", prodotto_scalare);
	} else {
		printf("La dimensione delle due sequenze non e' la stessa per poter effettuare il prodotto scalare!\n");
	}
	printf("\n");


	return 0;
}

// Implementazione delle funzioni

int maxAvg (int a1[], int dim1, int a2[], int dim2){

	int ris;
	float avg1, avg2;
	int tot;
	int i;

	tot = 0;
	for(i=0; i<dim1; i++){
		tot = tot + a1[i];
	}

	avg1 = (float)tot/dim1;

	tot = 0;
	for(i=0; i<dim2; i++){
		tot = tot + a2[i];
	}

	avg2 = (float)tot/dim2;

	if(avg1 < avg2){
		ris = 2;
	} else if(avg1 > avg2) {
		ris = 1;
	} else {
		ris = 0;
	}

	return ris;

}

void concArray (int a1[], int dim1, int a2[], int dim2, int conc[], int *dim3){

	int i, j;

	for(i=0; i<dim1; i++)
		conc[i] = a1[i];
	for(i=dim1, j=0; i<(dim1+dim2) && j<dim2; i++, j++){
		conc[i] = a2[j];
	}

	*dim3 = dim1+dim2;

}

void stampaArray (int a[], int dim){

	int i;

	for(i=0; i<dim; i++)
		printf("Il valore in posizione %d e': %d\n", i+1, a[i]);

}

void minMax (int a1[], int dim1, int a2[], int dim2, int *min, int *max, int *pmin, int *pmax){

	int max1, max2;
	int min1, min2;
	int i;

	max1 = a1[0];
	min1 = a1[0];
	for(i=0; i<dim1-1; i++){
		if(a1[i] <= a1[i+1]){
			min1 = a1[i];
		} else if(a1[i] >= a1[i+1]){
			max1 = a1[i];
		}
	}

	max2 = a2[0];
	min2 = a2[0];
	for(i=0; i<dim2-1; i++){
		if(a2[i] <= a2[i+1]){
			min2 = a2[i];
		} else if(a2[i] >= a2[i+1]){
			max2 = a2[i];
		}
	}

	if(max1 < max2){
		*max = max2;
		*pmax = 2;
	} else if (max1 > max2){
		*max = max1;
		*pmax = 1;
	} else {
		*max = max1;
	}

	if(min1 < min2){
		*min = min1;
		*pmin = 1;
	} else if (min1 > min2){
		*min = max2;
		*pmin = 2;
	} else {
		*pmin = 0;
		*min = min1;
	}

}

int prodScal (int a1[], int dim1, int a2[], int dim2){

	int ris;
	int i, j;

	for(i=0, j=0, ris=0; i<dim1 && j<dim2; i++, j++)
		ris = ris + (a1[i]*a2[j]);

	return ris;
}

