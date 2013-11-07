/* Programma: calcolo di N fattoriale
 *
 * La definizione di fattoriale è:
 *
 * n! = n*(n - 1)*(n - 2)*...*1  (per valori di n maggiori o uguali a 1)
 *
 * e per (n = 0) n! = 1  
 *
 * Il programma chiede all'utente di inserire un numero intero N e 
 * restituisce il valore di N fattoriale.
 * Il calcolo del fattoriale viene eseguito dalla funzione CALCOLO_FATTORIALE!
 * 
 * * Compilare con:
 * 	gcc -o ES2_FattorialeFun ES2_FattorialeFun.c
 * 
 */
 
 // Implementazione della funzione per il calcolo del fattoriale
  
#include <stdio.h>

long int CALCOLO_FATTORIALE(int N); 
 
int main()
{
// Allocazione e inizializzazione delle variabili

	long int numero = 0;
	long int risultato = 1;
	
// Recupero dei dati dati di input
	
	printf("Inserire il numero N = ");
	scanf("%ld", &numero);
	
// Verifica della positività di N

	if (numero < 0) 
	{
		printf("Il numero inserito è negativo\n");
		return 0;
	}

// Calcolo di N fattoriale utilizzando la funzione

	risultato = CALCOLO_FATTORIALE(numero);
    
	printf("%ld! = %ld\n", numero, risultato);
	return 0;
	
}

long int CALCOLO_FATTORIALE(int N)
 {
 	int i=0;
 	long int ris=1;
	
	for (i=N; i>= 1 ; i--) 
	{
		ris *= i; 
	} 	
 
 	return ris;
}
