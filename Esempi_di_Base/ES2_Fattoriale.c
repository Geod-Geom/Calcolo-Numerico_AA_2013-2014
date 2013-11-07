/* Programma: calcolo di N fattoriale
 *
 * La definizione di fattoriale è:
 *
 * n! = n*(n - 1)*(n - 2)*...*1  (per valori di n maggiori o uguali a 1)
 *
 * e per (n = 0) n! = 1  
 *
 * Il programma chiede all'utente di inserire un numero intero N e 
 * restituisce il valore di N fattoriale
 * 
 * Compilare con:
 * 	gcc -o ES2_Fattoriale ES2_Fattoriale.c
 */

#include <stdio.h>

int main()
{
// Dichiarazione e inizializzazione delle variabili

	int numero = 0, i = 0;
	long int risultato = 1;
	
// Recupero dei dati dati di input
	
	printf("Inserire il numero N = ");
	scanf("%d", &numero);
	
// Verifica della positività di N

	if (numero < 0) 
	{
		printf("Il numero inserito è negativo\n");
		return 0;
	}

// Calcolo di N fattoriale utilizzando un ciclo FOR
	
	for(i = numero; i >= 1; i--) 
	{
		risultato *= i; 
	}
    
	printf("%d! = %ld\n", numero, risultato);
	return 0;
	
} /* main */
