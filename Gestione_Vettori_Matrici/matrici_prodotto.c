/*
* The information in this file is
* Copyright(c) 2012, Gabriele Colosimo, Andrea Nascetti <gabriele.colosimo, andrea.nascetti>@uniroma1.it
* and is subject to the terms and conditions of the
* GNU Lesser General Public License Version 2.1
* The license text is available from
* http://www.gnu.org/licenses/lgpl.html
*/

/*
 * Funzione per il prodotto di due matrici
 * 
 */
 
#include <stdio.h>
void STAMPA_MATRICE(int righe, int colonne, double A[righe][colonne]);
void MATR_PROD(int righe_1, int colonne_1, int colonne_2,
		   double matr_1[righe_1][colonne_1], 
		   double matr_2[colonne_1][colonne_2],
		   double matr_out[righe_1][colonne_2]);

int main()
{
	int i, j, righe_1, colonne_1;
	int righe_2, colonne_2;
		
	printf("Inserisci righe matrice 1: ");
	scanf("%d", &righe_1);
	printf("Inserisci colonne matrice 1: ");
	scanf("%d", &colonne_1);
	printf("Inserisci righe matrice 2: ");
	scanf("%d", &righe_2);
	printf("Inserisci colonne matrice 2: ");
	scanf("%d", &colonne_2);
	
	if(colonne_1 != righe_2)
	{
		printf("Impossibile moltiplicare due matrici\n");
		printf("in cui le colonne della prima sono diverse\n");
		printf("dalle righe della seconda\n");
		printf("Riprovare\n");
		return 1;
	}
		
	double A[righe_1][colonne_1];
	double B[righe_2][colonne_2];
	double C[righe_1][colonne_2];
		
	/* Inizializzazione A */
	for(i = 0; i < righe_1; i++)
	{
		for(j = 0; j < colonne_1; j++)
		{
			A[i][j] = (i+1) * (j+1);
		}
	}
	/* Inizializzazione B */
	for(i = 0; i < righe_2; i++)
	{
		for(j = 0; j < colonne_2; j++)
		{
			B[i][j] = (i+1) * (j+1);
		}
	}
	/* Inizializzazione C */
	for(i = 0; i < righe_1; i++)
	{
		for(j = 0; j < colonne_2; j++)
		{
			C[i][j] = 0.;
		}
	}
		
	/* PRODOTTO MATRICE */
	MATR_PROD(righe_1, colonne_1, colonne_2, A, B, C);
	/* STAMPA MATRICE */
	printf("\nMatrice A \n");
	STAMPA_MATRICE(righe_1, colonne_1, A);
	printf("\nMatrice B \n");
	STAMPA_MATRICE(colonne_1, colonne_2, B);
	printf("\nMatrice C=A*B \n");
	STAMPA_MATRICE(righe_1, colonne_2, C);

	return 0;
} /* main */

/* DICHIARAZIONE DELLA FUNZIONE */

void MATR_PROD(int righe_1, int colonne_1, int colonne_2,
		   double matr_1[righe_1][colonne_1], 
		   double matr_2[colonne_1][colonne_2],
		   double matr_out[righe_1][colonne_2])
{
	int i, j, k;
	
	for(i=0; i < righe_1; i++)
	{
		for(j = 0; j < colonne_2; j++)
		{
			for(k = 0; k < colonne_1; k++)
			{
				matr_out[i][j] += matr_1[i][k] * matr_2[k][j];
			} /* k */
		} /* j */
	}/* i */ 
	
}

void STAMPA_MATRICE(int righe, int colonne, double A[righe][colonne])
{
	int i, j;
	
	for(i=0; i < righe; i++)
	{
		for(j = 0; j < colonne; j++)
		{
			printf("% 10.3lf ", A[i][j]);
		}
		printf("\n");
	} 
}

/* DA USARE IN UN SECONDO MOMENTO */

void MATR_INIT(int righe, int colonne, double A[righe][colonne])
{
	int i, j;
	
	for(i = 0; i < righe; i++)
	{
		for(j = 0; j < colonne; j++)
		{
			A[i][j] = 1. + i + j;
		}
	}	
}

void ZEROS(int righe, int colonne, double A[righe][colonne])
{
	int i, j;
	
	for(i = 0; i < righe; i++)
	{
		for(j = 0; j < colonne; j++)
		{
			A[i][j] = 0.;
		}
	}	
}

/*
 * 	MATR_INIT(righe_1, colonne_1, A);
	MATR_INIT(righe_2, colonne_2, B);
	ZEROS(righe_1, colonne_2, C);
	* */










