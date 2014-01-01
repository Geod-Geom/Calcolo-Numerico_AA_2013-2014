/*
* The information in this file is
* Copyright(c) 2012, Gabriele Colosimo, Andrea Nascetti <gabriele.colosimo, andrea.nascetti>@uniroma1.it
* and is subject to the terms and conditions of the
* GNU Lesser General Public License Version 2.1
* The license text is available from
* http://www.gnu.org/licenses/lgpl.html
*/

/*
 * Soluzione di un sistema lineare con il metodo di Jacobi
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
	double e=0;
	
	/* Lettura parametri di input */
	printf("Inserire il numero di equazioni N: ");
	scanf("%d", &N);
	printf("Inserire la soglia epsilon e: ");
	scanf("%lf", &e);
	
	/* Allocazione della matrice A e dei vettore B e X del sistema lineare */
    double A[N][N];
    double B[N][1];
    double X0[N];
    double X[N];
    double errore[N];
    /* Inizializzazione di A e B */
    ZEROS_MATRICE(N,N,A);
    ZEROS_MATRICE(N,1,B);
    ZEROS_VETTORE(N,X0);
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
	
	double err_k = 10000.00;
	int num_iter = 0;
	
	while (err_k > e && num_iter < 100)
	{
		num_iter ++;
		
		/* Ciclo for per il calcolo della soluzione X per ogni iterazione */		
		for(i=0;i<N;i++)
		{
			for(j=0;j<i;j++) X[i] += A[i][j]*X0[j];
			for(j=i+1;j<N;j++) X[i] += A[i][j]*X0[j];
			
			X[i]=(-X[i]+B[i][0])/A[i][i];

		}		
		
		/* Ciclo per il calcolo del vettore errore_k e salvataggio della soluzione */
		for(i=0;i<N;i++)
		{
			errore[i]= X[i]-X0[i];
			X0[i]=X[i];
			X[i]=0.0;
		}
		
		err_k = NORMA_N_VETTORE(N,errore,1.0);

	}
	
	printf("La soluzione è:\n");
	for (i=0;i<N;i++) printf("x%d = %12.8lf\n",i,X0[i]);
	printf("Il numero di iterazione effettuate è: %d\n",num_iter);
	printf("La norma uno del vettore errore è %lf\n:", err_k);
	
	
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

