#include <stdio.h>

void ZEROS(int righe, int colonne, double A[righe][colonne]);
double F_t0(double x);
void stampa_animazione(double h);

int main()
{
	double a = 0., b = 2.; /* Intervallo spaziale */
	double c = 0., d = 1.; /* Intervallo temporale */
	double h = 0.04; /* Discretizzazione spaziale */
	double k = 0.02; /* Discretizzazione temporale */
	double alpha = 0.5; /* NUmero di Courant */
	
	int N = (int)(b-a)/h; /* Numero di nodi */
	int M = (int)(d-c)/k; /* Numero di passi temporali */
	
	printf("N = %d; M = %d\n", N, M);
		
	double Phi[N+1][2];
	int i;
	FILE *OUT=NULL;
	
	OUT = fopen("Upwind.txt", "w");
	// Controllo apertura file
	if(OUT == NULL)
	{
		printf("Errore nell'apertura del file\n");
		printf("Riprovare\n");
		return(1);
	} /* if */
		
	/* Costruzione della condizione iniziale */	
	for(i=0; i <= N; i++)
	{
		Phi[i][0] = a;
		Phi[i][1] = F_t0(Phi[i][0]);
		a += h;
		fprintf(OUT, "% .2lf  % .2lf\n", Phi[i][0], Phi[i][1]);
	}
	
	double U[N+1][M+1];
	
	/* Inizializzazione matrice */
	ZEROS(N, M, U);
	
	int j;
	
	/* Condizione iniziale */
	for(i=0; i <= N; i++)
		U[i][0] = Phi[i][1];
		
	/* Condizione al bordo */	
	for(j=0; j <= M; j++)
		U[0][j] = 0.;
	
	
	for(j=0; j < M; j++)
	{
		for(i=1; i <= N; i++)
		{
			U[i][j+1] = (1 - alpha)*U[i][j] + alpha*U[i-1][j];
		}
	}
	
	for(i=0; i <= N; i++)
	{
		for(j=0; j <= M; j++)
			fprintf(OUT, "%lf ", U[i][j]);
		fprintf(OUT, "\n");	
	}	
	
	fclose(OUT);
	
	stampa_animazione(h);
	
	return 0;
}


double F_t0(double x)
{
	if((x <= 3.0/2.0) && (x >= 1.0/2.0))
		return (1.0/2.0 - x)*(x - 3.0/2.0);
	else
		return 0;
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

void stampa_animazione(double h)
{
	int i;
	FILE *OUT=NULL;
	
	OUT = fopen("Upwind_gif.plt", "w");
	// Controllo apertura file
	if(OUT == NULL)
	{
		printf("Errore nell'apertura del file\n");
		printf("Riprovare\n");
		return;
	} /* if */
	
	//fprintf(OUT, "set terminal tgif animate delay 50\n");
	//fprintf(OUT, "set output \"upwind.gif\"\n");
	
	for(i=1; i <= 50; i++)
	{
		fprintf(OUT, "plot \"Upwind.txt\" u ($0*%5.4lf):%d every ::51 w lp t \"Instante t = %3d\"\n", h,i,i);
		fprintf(OUT, "pause 0.1\n");
	}
	fclose(OUT);
}