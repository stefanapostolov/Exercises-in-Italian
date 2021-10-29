/*

	Si definiscano due tipi di dato adatti a rappresentare triangoli generici e rettangoli con i lati paralleli agli assi:
	Un triangolo sia definito come tre punti nel piano
	Un rettangolo coi lati paralleli agli assi sia invece definito da una coppia di punti: il suo vertice in alto a sinistra (NO, «NordOvest») e il 
  suo vertice in basso a destra (SE, «SudEst»).

	Esercizio 1a:
	
	Si scriva quindi un programma che stabilisca se un triangolo è: 
	"ragionevolmente" isoscele (o pseudoisoscele)
	"ragionevolmente" equilatero (o pseudoequilatero)
	Il programma deve verificare se valgono le relative proprietà (lunghezza dei lati) a meno di una ragionevole approssimazione in percentuale, da 
  impostarsi come costante globale.


*/

#include <stdio.h>
#include <math.h>
 
#define SOGLIA 1.0 // percentuale di approssimazione
 
typedef struct punto_s { 
	float x; 
	float y; 
} Punto;
 
typedef struct Triangolo_s {
	Punto A;
	Punto B;
	Punto C;
} Triangolo;
 
 
float distanza( Punto p1, Punto p2 ) 
{
	float dx = p1.x - p2.x;
	float dy = p1.y - p2.y;
	return sqrtf(dx * dx + dy * dy);
}
 
int degenere( Triangolo t ) 
{
	/* Per semplicità al momento si accetta praticamente qualsiasi triangolo, 
	poi si potranno sempre stabilire regole più complete. 
	Controllo semplicemente che non ci siano punti totalmente sovrapposti */
	if( distanza( t.A, t.B ) == 0 ||
		distanza( t.A, t.C ) == 0 ||
		distanza( t.B, t.C ) == 0)
		return 1;
 
	return 0;
}
 
Punto leggiPunto(char nomePunto) 
{
	Punto p;
 
	printf("Coordinata x del punto %c: ", nomePunto);
	scanf("%f", &p.x);
	printf("Coordinata y del punto numero %c: ", nomePunto);
	scanf("%f", &p.y);
 
	return p;
}
 
Triangolo leggiTriangolo() 
{
	Triangolo t;
	int deg;
	do {
		t.A = leggiPunto('A');
		t.B = leggiPunto('B');
		t.C = leggiPunto('C');
		deg = degenere(t);
		if( deg )
			 printf("\n Le coordinate non definiscono un Triangolo valido. Riproviamo.\n");
	} while( deg );	
	return t;
}
 
void stampaTri( Triangolo t ) 
{
	printf("\n");
	printf(" punto A [ %2.2f, %2.2f ]\n", t.A.x, t.A.y);
	printf(" punto B [ %2.2f, %2.2f ]\n", t.B.x, t.B.y);
	printf(" punto C [ %2.2f, %2.2f ]\n", t.C.x, t.C.y);
}
 
/* Definisco due grandezze float come pseudouguali se la differenza 
	 è inferiore a SOGLIA % della maggiore delle due grandezze */ 
int pseudouguali(float a, float b) 
{
	float max, min;
	if( a == b )     /* Se sono uguali, non serve calcolare */
		return 1;
	if( a * b == 0.0 )  /* se una delle due è 0, non rischio la divisione, tanto... */
		return 0;       /* ...se uno e' 0 e l'altro no la differenza è del 100% */
 
	min = a;
	max = b;
	if(min > max) {
		min = b;
		max = a;
	}
 
	return (max-min) / max * 100 < SOGLIA;
}
 
/* funzione per il calcolo dell'area del triangolo usando la formula di Erone */
float erone( float a, float b, float c ) 
{
	float p = (a+b+c) / 2;
	return sqrtf(p*(p-a)*(p-b)*(p-c));
}
 
int main() 
{
	Triangolo t;
	int coppie_lati_uguali;
	float ab, bc, ac;
 
	t = leggiTriangolo();
	printf("\nHai definito il seguente triangolo: \n");
	stampaTri( t );
 
	ab = distanza( t.A, t.B );
	ac = distanza( t.A, t.C );
	bc = distanza( t.B, t.C );
 
	printf("\nDistanze: AB %.4f    BC %.4f    AC %.4f\n\n", ab, bc, ac);
 
	printf("Confronti:  AB-BC %d   AB-AC %d   AC-BC %d\n\n", 
		pseudouguali(ab,bc), pseudouguali(ab,ac), pseudouguali(ac,bc));
 
	coppie_lati_uguali = pseudouguali(ab,bc) + pseudouguali(ab,ac) + pseudouguali(ac,bc);
 
	printf("Con tolleranza del %.1f %% il triangolo risulta essere ", (float)SOGLIA);
 
	/* Può sembrare a prima vista assurdo che ci siano due coppie di lati uguali ma non tre, 
	però occorre ricordare che la pseudouguaglianza non è una relazione di equivalenza, 
	in quanto non è transitiva. Ad esempio con SOGLIA pari al 10% 100 e 108 sono pseudouguali, 
	108 e 115 sono pseudouguali, ma 100 e 115 ovviamente NON lo sono */
	switch ( coppie_lati_uguali )  {
		case 3 : printf("PSEUDO-Equilatero\n\n");   break;
		case 2 : 
	 	case 1 : printf("PSEUDO-Isoscele\n\n");     break;
		case 0 : printf("DECISAMENTE Scaleno\n\n"); break;
		default : printf("\n\nSomething went wrong\n\n");
	}
 
	printf("Infine, anche se non era richiesto, segnalo che:\n");
	printf(" il perimetro e' %.2f\n l'area e' %.2f\n\n", ab+bc+ac, erone(ab,ac,bc));
 
	return 0;
}
 
