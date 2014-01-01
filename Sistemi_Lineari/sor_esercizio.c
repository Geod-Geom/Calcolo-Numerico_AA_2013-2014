/*
* The information in this file is
* Copyright(c) 2012, Gabriele Colosimo, Andrea Nascetti <gabriele.colosimo, andrea.nascetti>@uniroma1.it
* and is subject to the terms and conditions of the
* GNU Lesser General Public License Version 2.1
* The license text is available from
* http://www.gnu.org/licenses/lgpl.html
*/

/*
 * Soluzione di un sistema lineare con il metodo del sovrarilassamento (S.O.R.)
 *
 * AX = B
 *
 * Input:
 * - n: dimensioni del sistema lineare
 * - A(n,n): matrice dei coefficienti viene fornita tramite un file "matriceA.dat"
 * - B(n): vettore dei termini noti viene fornito tramite un file "vettoreB.dat"
 * - e: accuratezza richiesta nell’approssimazione
 * Output:
 * - X(n,n): soluzione approssimata 
 * - num_iter: numero di iterazioni
 * - err_k: differenza tra le ultime due approssimazioni in norma 1  
 * 
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void LETTURA_MATRICE(int righe,int colonne, double A[righe][colonne],FILE *input);
void STAMPA_MATRICE(int righe, int colonne, double A[righe][colonne]);

void ZEROS_MATRICE(int righe, int colonne, double A[righe][colonne]);
void ZEROS_VETTORE(int num, double V[num]);

double NORMA_N_VETTORE(int num, double a[num], double ordine_norma);

int main()
{
	int i=0,j=0;
	int N=0;    /* Numero di equazioni */
	double e=0.;
	double omega = 0.; /* Fattore di rilassamento */
	
	/* Lettura parametri di input */
	printf("Inserire il numero di equazioni N: ");
	scanf("%d", &N);
	printf("Inserire il fattore di rilassamento omega: ");
	scanf("%lf", &omega);
	if(omega > 2. || omega < 0.)
	{
		printf("Errore: per averre convergenza del metodo, il fattore di rilassamento deve essere compreso tra 0.0 e 2.0\n");
		printf("Riprovare\n");
		return 1;
	}
	printf("Inserire la soglia epsilon e: ");
	scanf("%lf", &e);
	
	/* Allocazione della matrice A e dei vettore B e X del sistema lineare */
    double A[N][N];
    double B[N][1];
    double X0[N];
    double V[N];
    double X[N];
    double errore[N];
    /* Inizializzazione di A e B */
    ZEROS_MATRICE(N,N,A);
    ZEROS_MATRICE(N,1,B);
    ZEROS_VETTORE(N,X0);
    ZEROS_VETTORE(N,V);
    ZEROS_VETTORE(N,X);
    ZEROS_VETTORE(N,errore);    
    
    /* Lettura da file dei valori della matrice A e del vettore B */ 
	FILE *inputA=NULL;
	FILE *inputB=NULL;
	
	inputA = fopen("matriceA.dat", "r");
	if(inputA == NULL)
	{
		printf("Errore nell'apertura del file matriceA.dat\n");
		printf("Riprovare\n");
		return(1);
	} /* if */
	
	inputB = fopen("vettoreB.dat", "r");
    if(inputB == NULL)
	{
		printf("Errore nell'apertura del file vettoreB.dat\n");
		printf("Riprovare\n");
		return(1);
	} /* if */
	
	LETTURA_MATRICE(N,N,A,inputA);
	LETTURA_MATRICE(N,1,B,inputB);
	
	printf("La matrice A:\n");
	STAMPA_MATRICE(N,N,A);	
    printf("Il vettore B:\n");
	STAMPA_MATRICE(N,1,B);	
	
	double err_k = 1000;
	int num_iter = 0;

/*  ---------------PARTE MANCANTE---------------------
 * 
 * inserire tutte le operazioni necessarie per calcolare la soluzione 
 * del sistema lineare con il metodo di S.O.R.
 *
 * riferimento pagina 59 slide Sistemi Lineari Prof. Pitolli
 */
	
	printf("La soluzione è:\n");
	for (i=0;i<N;i++) printf("x%d = %12.8lf\n",i,X0[i]);
	printf("Il numero di iterazione effettuate è: %d\n",num_iter);
	printf("La norma uno del vettore errore è % .12lf\n:", err_k);
	
	return 0;
}/* main */

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

void ZEROS_VETTORE(int num, double V[num])
{
	int i;
	
	for(i = 0; i < num; i++)
	{
			V[i] = 0.;
	}	
}

double NORMA_N_VETTORE(int num, double a[num], double ordine_norma)
{
	int i;
	double norma = 0.;
	
	for(i=0; i < num; i++)
	{
		norma += pow(fabs(a[i]), ordine_norma);
	}
		
	return pow(norma, 1./ordine_norma);
}

