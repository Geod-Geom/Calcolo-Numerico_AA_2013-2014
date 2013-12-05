/*
* The information in this file is
* Copyright(c) 2012, Gabriele Colosimo, Andrea Nascetti <gabriele.colosimo, andrea.nascetti>@uniroma1.it
* and is subject to the terms and conditions of the
* GNU Lesser General Public License Version 2.1
* The license text is available from
* http://www.gnu.org/licenses/lgpl.html
*/

/*
 * Funzione per il calcolo della norma di una matrice
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double MAX_ABS_VETTORE(int num, int a[num]);
double NORMA1_MATRICE(int num, int a[num][num]);
double NORMA_INFINITO_MATRICE(int num, int a[num][num]);

int main()
{
	int i,j;
	int n; /* dimensioni del vettore */
	int m = 101; /* massimo elemento del vettore */	
		
	printf("Inserire il numero di righe-colonne della matrice quadrata A: ");
	scanf("%d", &n);
	
	int A[n][n]; //allocazione della matrice A
	
	/* Inizializzazione della matrice con numeri casuali
	 * si utilizza la funzione rand() contenuta nella
	 * stdlib.h */
	for(i=0; i < n; i++)
	{
		for(j=0; j < n; j++)
		{
			A[i][j] = rand() % m - (int)(m/2); /* Genera numeri casuali interi tra 
			-m/2 e m/2 */
			printf("%5d", A[i][j]);
		}
	printf("\n");
	}
	
	/* SCRIVERE UNA FUNZIONE PER IL CALCOLO DELLA NORMA 1
	 * DELLA MATRICE a[n][n] */
	 printf("La norma 1 della matrice e' % .2lf\n", NORMA1_MATRICE(n, A));
	 	 
	 /* SCRIVERE UNA FUNZIONE PER IL CALCOLO DELLA NORMA INFINITO
	 * DELLA MATRICE a[n][n] */
	  printf("La norma infinito della matrice e' % .2lf\n", NORMA_INFINITO_MATRICE(n, A));
	 	
	return 0;
} /* main */

double MAX_ABS_VETTORE(int num, int a[num])
{
	int i;
	double max = a[0]; /* Scelta arbitraria */
	
	for(i=0; i < num; i++)
	{
		if(fabs(a[i]) > max)
			max = fabs(a[i]);
	}/* for i */
	
	return max;
} 

double NORMA1_MATRICE(int num, int a[num][num])
{
	int i,j;
	int b[num];
	
	for(i=0; i < num; i++) b[i]=0.0;
	
	for(i=0; i < num; i++)
	{
		for(j=0; j < num; j++)
		{
			b[j] += abs(a[i][j]) ;
		}
	}
		
	return MAX_ABS_VETTORE(num,b);
}

double NORMA_INFINITO_MATRICE(int num, int a[num][num])
{
	int i,j;
	int b[num];
	
	//inizializzazione vettore b
	for(i=0; i < num; i++) b[i]=0.0;
	
	for(i=0; i < num; i++)
	{
		for(j=0; j < num; j++)
		{
			b[i] += abs(a[i][j]) ;
		}
	}
		
	return MAX_ABS_VETTORE(num,b);
}




