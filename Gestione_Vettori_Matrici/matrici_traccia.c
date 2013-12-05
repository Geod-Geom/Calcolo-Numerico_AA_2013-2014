/*
* The information in this file is
* Copyright(c) 2012, Gabriele Colosimo, Andrea Nascetti <gabriele.colosimo, andrea.nascetti>@uniroma1.it
* and is subject to the terms and conditions of the
* GNU Lesser General Public License Version 2.1
* The license text is available from
* http://www.gnu.org/licenses/lgpl.html
*/

/*
 * Funzione per la stampa di una matrice
 */

#include <stdio.h>

void STAMPA_MATRICE(int righe, int colonne, double A[righe][colonne]);
double MATR_TRACCIA(int righe, double A[righe][righe]);

int main()
{
	int i, j, righe, colonne;
		
	printf("Inserisci righe: ");
	scanf("%d", &righe);
	printf("Inserisci colonne: ");
	scanf("%d", &colonne);
		
	double A[righe][colonne]; /* allocazione matrice */
		
	/* Inizializzazione della matrice */
	for(i = 0; i < righe; i++)
	{
		for(j = 0; j < colonne; j++)
		{
			A[i][j] = 1. + i + j; /* Valore iniziale */
		}
	}

	/* STAMPA MATRICE */
	STAMPA_MATRICE(righe, colonne, A);

	/* CALCOLO DELLA TRACCIA DELLA MATRICE */
	double traccia = 0.;
	traccia = MATR_TRACCIA(righe, A);
	printf("La traccia della matrice A e' % 8.3lf\n", traccia);

	return 0;
} /* main */

/* DICHIARAZIONE DELLA FUNZIONE */

void STAMPA_MATRICE(int righe, int colonne, double A[righe][colonne])
{
	int i, j;
	
	for(i=0; i < righe; i++)
	{
		for(j = 0; j < colonne; j++)
		{
			printf("% 8.3lf ", A[i][j]);
		}
		printf("\n");
	} 
}

double MATR_TRACCIA(int righe, double A[righe][righe])
{
	int i;
	double traccia = 0.;
	
	for(i = 0; i < righe; i++)
		traccia += A[i][i];
		
	return traccia;
}
