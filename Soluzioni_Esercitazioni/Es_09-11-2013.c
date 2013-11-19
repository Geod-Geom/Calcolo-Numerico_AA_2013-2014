/* Programma pre-impostato per la soluzione del problema di Cauchy 
 *
 * Calcola la soluzione numerica di equazioni differenziali del primo ordine
 * con il metodo di Eulero esplicito
 * 
 * Funzioni:
 * - f(t,y): termine noto dell’equazione differenziale 
 * - g(t): soluzione analitica del problema di Cauchy
 *
 * Input:
 * - x0, y0: condizione iniziale
 * - h: passo di discretizzazione
 * - n: numero di passi
 *
 * Output:
 * - xi: nodo i-esimo
 * - yi: approssimazione al nodo xi
 *
 */
 
#include <stdio.h>
#include <math.h>

double f(double t, double y); // F
double g(double t);

void eulero(int n, double h, double t0, double y0);
void heun(int n, double h, double t0, double y0);
void runge_kutta(int n, double h, double t0, double y0);

int main()
{
	//Allocazione delle Variabili
	
	int n=0, method=0;
	double t0 = 0., y0 = 0., h = 0.0, tmax = 0.0;
	
	//Lettura dei dati di input	
	printf("Inserire il numero di matricola n = \n");
	scanf("%d",&n);
	
	n=n%100+50;
	
	/*
	printf("Inserire h = \n");
	scanf("%lf",&h);
	
	printf("Inserire t0 = \n");
	scanf("%lf",&t0);
		
	printf("Inserire y0 = \n");
	scanf("%lf",&y0);
	*/
	
	t0 = 0.0;
	tmax = 5.0;
	y0 = 1.0;	
	h = (tmax/n);
	
	printf("n = %d, t [%3.1lf,%3.1lf], y0 = %lf, h = %lf\n", n,t0,tmax,y0,h);
	
	printf("Scegliere metodo: 1 eulero 2 heun 3 runge\n");
	scanf("%d", &method);
	
	switch(method)
	{
		case 1:
			eulero(n,h,t0,y0);
			break;
			
		case 2:
			heun(n,h,t0,y0);
			break;

		case 3:
			runge_kutta(n,h,t0,y0);
			break;
			
		default:
			printf("Errore nessun metodo selezionato\n");	
	}
	return 0;
}

void eulero(int n, double h, double t0, double y0)
{
	FILE *link;
	link = fopen("risultati_eulero.txt","w");
	
	int k=0;
	double ei = 0., yi = 0., ti = 0., yi_1=0., ti_1=0.;
	
	ti=t0;
	yi=y0;
	
	for (k=1;k<=n;k++ )
	{
		yi_1 = yi +h*f(ti,yi);
		ti_1= ti +h;
		ei = g(ti_1)- yi_1;
		
		printf("%d \t %10.6lf \t %14.8lf \t %8.4le\n", k, ti_1,yi_1,ei);
		fprintf(link, "%d \t %10.6lf \t %14.8lf \t %8.4le\n", k, ti_1,yi_1,ei);

		yi=yi_1;	
		ti=ti_1;		
	}
	fclose(link);
}

void heun(int n, double h, double t0, double y0)
{
	FILE *link;
	link = fopen("risultati_heun.txt","w");
	
	int k=0;
	double ei = 0., yi = 0., ti = 0., yi_1=0., ti_1=0.;
	
	ti=t0;
	yi=y0;
	
	for (k=1;k<=n;k++ )
	{
		yi_1 = yi + 0.5*h*(f(ti,yi) + f(ti+h,yi+h*f(ti,yi)));
 		ti_1= ti +h;
		ei = g(ti_1)- yi_1;
		
		printf("%d \t %10.6lf \t %14.8lf \t %8.4le\n", k, ti_1,yi_1,ei);
		fprintf(link, "%d \t %10.6lf \t %14.8lf \t %8.4le\n", k, ti_1,yi_1,ei);

		yi=yi_1;		
		ti=ti_1;		
	}
	fclose(link);
}

void runge_kutta(int n, double h, double t0, double y0)
{
	FILE *link;
	link = fopen("risultati_runge-kutta.txt","w");
	
	int k=0;
	double ei = 0., yi = 0., ti = 0., yi_1=0., ti_1=0.;
	double k1=0.,k2=0.,k3=0.,k4=0.;
	
	ti=t0;
	yi=y0;
	
	for (k=1;k<=n;k++ )
	{
		k1 = f(ti,yi);
		k2 = f(ti + 0.5*h, yi + 0.5*h*k1);
		k3 = f(ti + 0.5*h, yi + 0.5*h*k2);
		k4 = f(ti + h, yi + h*k3);
	
		yi_1 = yi + h*(k1 + 2.0*k2 + 2.0*k3 + k4)/6.0;
 		ti_1= ti +h;
		ei = g(ti_1)- yi_1;
		
		printf("%d \t %10.6lf \t %14.8lf \t %8.4le\n", k, ti_1,yi_1,ei);
		fprintf(link, "%d \t %10.6lf \t %14.8lf \t %8.4le\n", k, ti_1,yi_1,ei);

		yi=yi_1;		
		ti=ti_1;		
	}
	fclose(link);
}


double f(double t, double y)
{
	return -y-5*exp(-t)*sin(5*t);
}

double g(double t)
{
	return exp(-t)*cos(5*t);
}




