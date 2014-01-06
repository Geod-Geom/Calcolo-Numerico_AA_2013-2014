#include <stdio.h>

/* Funzioni per la gestione delle matrici e dei vettori */
void ZEROS_MATRICE(int righe, int colonne, double A[righe][colonne]);
void ZEROS_VETTORE(int num, double vett[num]);
		   
/* Funzione per soluzione di un sistema lineare tri-diagonale nella AX = B con Thomas */
void THOMAS(int num, double A[num][num], double B[num], double X[num]);

/* Funzione f(t0) del problema -- DA IMPLEMENTARE-- */
double F_t0(double x);

/* Funzione per la stampa del Crank_Grafico.plt da inviare con i file della soluzione */
void STAMPA_GRAFICO(double h, int M, int N);

int main()
{
	/* Inserire i valori corretti del problema  */	
	double a = 0., b = 2.; /* Intervallo spaziale */
	double c = 0., d = 0.4; /* Intervallo temporale */
	double h = 0.02; /* Discretizzazione spaziale */
	double k = 0.02; /* Discretizzazione temporale */
	double alpha = 0.5; /* Numero di Courant */
	
	int N = (int)((b-a)/h); /* Numero di nodi */
	int M = (int)((d-c)/k); /* Numero di passi temporali */
		
	double Phi[N+1][2], Vj[N+1], B[N+1], Uj1[N+1];
	double U[N+1][M+1]; //Matrice U dei risultati
	
	/* Inizializzazione delle matrice e dei vettori */
	ZEROS_MATRICE(N+1, M+1, U);  
	ZEROS_VETTORE(N+1,Vj);
	ZEROS_VETTORE(N+1,Uj1);
	ZEROS_VETTORE(N+1,B);	
	
	/* Apertura e controllo del primo file di output */
	FILE *OUT=NULL;
	OUT = fopen("Crank-Nicolson.txt", "w");
	if(OUT == NULL)
	{
		printf("Errore nell'apertura del file\n");
		printf("Riprovare\n");
		return(1);
	}
		
    /* Indici disponibili per la gestione dei for */
	int i,j,jj;
		
	/* Calcolo della condizione iniziale */	
	for(i=0; i <= N; i++)
	{
		Phi[i][0] = a;
		Phi[i][1] = F_t0(Phi[i][0]);
		a += h;
		fprintf(OUT, "% .2lf  % .2lf\n", Phi[i][0], Phi[i][1]);
	}
				
	/* Condizione iniziale */
	for(i=0; i <= N; i++) U[i][0] = Phi[i][1];
		
	/* Condizione al bordo */	
	for(j=0; j <= M; j++) U[0][j] = 0.;
		
	/* Costruzione della matrice A di amplificazione */
	double A[N+1][N+1];	
	ZEROS_MATRICE(N+1,N+1,A);
	
	for(i=0; i <= N; i++)
	{
		A[i][i] = 1.0;
		A[i][i+1] =  0.25*alpha;
		A[i+1][i] = -0.25*alpha;
	}
		
	for(j=0; j < M; j++) // ciclo per la gestione del tempo
	{
			/* Azzeramento dei vettori Vj e B */
			ZEROS_VETTORE(N+1,Vj);
			ZEROS_VETTORE(N+1,B);
			
			/* Calcolo del vettore Vj */						
			Vj[0] = 0.25*alpha*U[0][j];
					
			/* Calcolo del vettore B = A_Trasposta*Uj+0.25*alpha*Vj */	
			for(i=1;i<=N;i++)
			{
				for(jj=1; jj<=N; jj++)
				{
				B[i] += A[jj][i]*U[jj][j];
				}
				B[i] += Vj[i];
			}		
			
			/* Soluzione del sistema lineare A*Uj1 = B con la funzione di Thomas */
			THOMAS(N+1,A,B,Uj1);
			
			/* Copia dei vettore Uj1 nella matrice U dei risultati */
			for(jj=1; jj<= N; jj++) U[jj][j+1] = Uj1[jj];				
	}
	
	/* Stampa dei risultati */
	for(i=0; i <= N; i++)
	{
		for(j=0; j <= M; j++)
			fprintf(OUT, "%lf ", U[i][j]);
		fprintf(OUT, "\n");	
	}		
	fclose(OUT);
		
	STAMPA_GRAFICO(h,M+1,N+1);
	return 0;
}


double F_t0(double x)
{
	double gamma = 9.9;
	if((x <= 3.0/2.0) && (x >= 1.0/2.0))
		return gamma*(1.0/2.0 - x)*(x - 3.0/2.0);
	else
		return 0;
}

void THOMAS(int num, double A[num][num], double B[num], double X[num])
{
	int i;
	double alfa[num];      // Vettore alfa matrice L 
	double u[num], v[num]; // Vettori U e V matrice U
	double y[num];         // Vettore soluzione Y=UX

	ZEROS_VETTORE(num, alfa);
	ZEROS_VETTORE(num, u);
	ZEROS_VETTORE(num, v);
	ZEROS_VETTORE(num, y);
	ZEROS_VETTORE(num, X);
	
    double A_diag[num],A_sup[num],A_inf[num];
	ZEROS_VETTORE(num,A_diag);
	ZEROS_VETTORE(num,A_sup);
	ZEROS_VETTORE(num,A_inf);
	
	A_diag[0] = A[0][0];
	
	for (i=0;i<num;i++)
	{
		A_diag[i] = A[i][i];
		A_sup[i]  = A[i][i+1];
		A_inf[i]  = A[i+1][i];
	}
	
	u[0] = A_diag[0];
	
	for(i=0; i < num-2; i++)
	{
		v[i] = A_sup[i];
	}

	for(i=1; i < num; i++)
	{
		alfa[i] = A_inf[i]/u[i-1];
		u[i] = A_diag[i] - alfa[i] * v[i-1];
	}
	
	/* Soluzione del sistema triangolare inferiore LY = B (dove Y = UX) con
	 * il metodo della sostituzione in avanti */
	y[0] = B[0];
	for(i=1; i < num; i++)
	{
		y[i] = B[i] - alfa[i] * y[i-1];
	}
	
	/* Soluzione del sistema triangolare superiore UX = Y con
	 * il metodo della sostituzione all'indietro */
	X[num-1] = y[num-1] / u[num-1];
	
	for(i=num-2; i >= 0; i--)
	{
		X[i] = (y[i] - v[i] * X[i+1]) / u[i];
	}/* for i */
		
}/* THOMAS */

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

void ZEROS_VETTORE(int num, double vett[num])
{
	int i;
	
	for(i = 0; i < num; i++)
	{
		vett[i] = 0.;
	}	
}

void STAMPA_GRAFICO(double h, int M,int N)
{
	int i=1;
	FILE *OUT=NULL;
	
	OUT = fopen("Crank_Grafico.plt", "w");
	// Controllo apertura file
	if(OUT == NULL)
	{
		printf("Errore nell'apertura del file\n");
		printf("Riprovare\n");
		return;
	} /* if */
	
	fprintf(OUT,"set key outside\n");
	fprintf(OUT, "plot \"Crank-Nicolson.txt\" u ($0*%5.4lf):%d every ::%d w lp t \"t = %3d\"\n", h,i,N,i);
	
	for(i=2; i <= M; i++)
	{
		fprintf(OUT, "replot \"Crank-Nicolson.txt\" u ($0*%5.4lf):%d every ::%d w lp t \"t = %3d\"\n", h,i,N,i);
		fprintf(OUT, "pause 0.1\n");
	}
	fclose(OUT);
}