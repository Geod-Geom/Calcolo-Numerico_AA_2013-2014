/* Programma: Numeri primi brute
 *
 * Il programma chiede all'utente di inserire un numero intero N e 
 * restituisce i numeri primi inferiori al numero N
 * 
 * Compilare con:
 * 	gcc -o Numeri_primi_brute Numeri_primi_brute.c
 */

#include <stdio.h>

int main()
{
// Allocazione delle variabili
	int N = 0;
	int flag = 0, i = 0, j = 0, k = 0;
		
// Recupero e controllo dei dati dati di input	
	printf("Inserire il numero N = ");
	scanf("%d", &N);

	if (N < 3)
	{
		printf("N deve essere maggiore di 2\n");
		return 1;
  	}

	printf("I numeri primi minori di %d sono:\n", N);

	for(i = 1; i < N; i++)
	{
		flag = 0;
		for(j = 2; j < i; j++)
		{
			if( i > j && i % j == 0)
			{
				flag = 1;
				break;
			} /* if */
		} /* for j */
		if(flag == 0)
		{
			printf("%d\n", i);
			k++;
		} /* if */
	} /* for i */
	
	printf("Ci sono %d numeri primi inferiori a %d\n", k, N);	
		
	return 0;
} /* main */
