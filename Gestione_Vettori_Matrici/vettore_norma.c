/*
* The information in this file is
* Copyright(c) 2012, Gabriele Colosimo, Andrea Nascetti <gabriele.colosimo, andrea.nascetti>@uniroma1.it
* and is subject to the terms and conditions of the
* GNU Lesser General Public License Version 2.1
* The license text is available from
* http://www.gnu.org/licenses/lgpl.html
*/

/*
 * Funzione per il calcolo della norma 2 di un vettore
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double MAX_ABS_VETTORE(int num, int a[num]);
double NORMA2_VETTORE(int num, int a[num]);
double NORMA_N_VETTORE(int num, int a[num], double ordine_norma);
double NORMA_INFINITO_VETTORE(int num, int a[num]);

int main()
{
	int i;
	int n; /* dimensioni del vettore */
	int m = 101; /* massimo elemento del vettore */	
		
	printf("Inserire la dimensione n del vettore: ");
	scanf("%d", &n);
	
	int a[n];
	
	/* Inizializzazione del vettore con numeri casuali
	 * si utilizza la funzione rand() contenuta nella
	 * stdlib.h */
	 for(i=0; i < n; i++)
	{
		a[i] = rand() % m - (int)(m/2); /* Genera numeri casuali interi tra 
		-m/2 e m/2 */
		printf("a[%3d] = %5d\n", i, a[i]);
	}
	
	/* SCRIVERE UNA FUNZIONE PER IL CALCOLO DELLA NORMA 2
	 * DEL VETTORE a[n] */
	 printf("La norma 2 del vettore e' % .2lf\n", NORMA2_VETTORE(n, a));
	 
	/* SCRIVERE UNA FUNZIONE PER IL CALCOLO DELLA NORMA K
	 * DEL VETTORE a[n] */ 
	 double k;
	 printf("Inserire l'ordine della norma da calcolare: ");
	 scanf("%lf", &k);
	 
	 printf("La norma %.0lf del vettore e' % .2lf\n", k, NORMA_N_VETTORE(n, a, k));
	 
	 /* SCRIVERE UNA FUNZIONE PER IL CALCOLO DELLA NORMA INFINITO
	 * DEL VETTORE a[n] */
	  printf("La norma infinito del vettore e' % .2lf\n", NORMA_INFINITO_VETTORE(n, a));
	 
	
	return 0;
} /* main */

double NORMA2_VETTORE(int num, int a[num])
{
	int i;
	double norma = 0.;
	
	for(i=0; i < num; i++)
	{
		norma += abs(a[i]) * abs(a[i]);
	}
		
	return sqrt(norma);
}

double NORMA_N_VETTORE(int num, int a[num], double ordine_norma)
{
	int i;
	double norma = 0.;
	
	for(i=0; i < num; i++)
	{
		norma += pow(abs(a[i]), ordine_norma);
	}
		
	return pow(norma, 1./ordine_norma);
}

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

double NORMA_INFINITO_VETTORE(int num, int a[num])
{
	return MAX_ABS_VETTORE(num, a);
}




