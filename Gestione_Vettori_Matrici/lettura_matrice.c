/*
* The information in this file is
* Copyright(c) 2012, Gabriele Colosimo, Andrea Nascetti <gabriele.colosimo, andrea.nascetti>@uniroma1.it
* and is subject to the terms and conditions of the
* GNU Lesser General Public License Version 2.1
* The license text is available from
* http://www.gnu.org/licenses/lgpl.html
*/

/*
 * Esempio di lettura di una matrice da file
 * 
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void LETTURA_MATRICE(int righe,int colonne, double A[righe][colonne],FILE *input);
void STAMPA_MATRICE(int righe, int colonne, double A[righe][colonne]);
void ZEROS_MATRICE(int righe, int colonne, double A[righe][colonne]);

int main()
{
	int n=0,m=0;
	
	/* Lettura parametri di input */
	printf("Inserire il numero di righe n: ");
	scanf("%d", &n);
	printf("Inserire il numero di colonne m: ");
	scanf("%d", &m);
	
	/* Allocazione della matrice A */
    double A[n][m];
    
    /* Inizializzazione di A e B */
    ZEROS_MATRICE(n,m,A);
    
    /* Lettura da file dei valori della matrice A e del vettore B */ 
	FILE *inputA=NULL;
	
	inputA = fopen("matrice.dat", "r");
	if(inputA == NULL)
	{
		printf("Errore nell'apertura del file matrice.dat\n");
		printf("Riprovare\n");
		return(1);
	} /* if */
	
	LETTURA_MATRICE(n,m,A,inputA);
	
	printf("La matrice caricata dal file è:\n");
	STAMPA_MATRICE(n,m,A);	

	return 0;
}


void LETTURA_MATRICE(int righe,int colonne, double A[righe][colonne],FILE *input)
{
	int i,j;
	
	for(i=0; i < righe; i++)
	{
		for(j=0; j < colonne; j++)
		{
		fscanf(input, "%lf", &A[i][j]);
		}
	} 
}

void STAMPA_MATRICE(int righe, int colonne, double A[righe][colonne])
{
	int i, j;
	
	for(i=0; i < righe; i++)
	{
		for(j = 0; j < colonne; j++)
		{
			printf("% 10.5lf ", A[i][j]);
		}
		printf("\n");
	} 
}

void ZEROS_MATRICE(int righe, int colonne, double A[righe][colonne])
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

