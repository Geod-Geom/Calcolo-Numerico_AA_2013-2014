/*
* The information in this file is
* Copyright(c) 2012, Gabriele Colosimo, Andrea Nascetti <gabriele.colosimo, andrea.nascetti>@uniroma1.it
* and is subject to the terms and conditions of the
* GNU Lesser General Public License Version 2.1
* The license text is available from
* http://www.gnu.org/licenses/lgpl.html
*/

/* Programma di Runge-Kutta: 
 *
 * Soluzione di un sistema di due equazioni differenziali del primo ordine
 * con il metodo di Runge-Kutta del IV ordine
 * 
 * Funzioni:
 * - f(x, y, z)  
 * - g(x, y, z)
 *
 * Input:
 * - x0, y0, z0: condizione iniziale
 * - h: passo di discretizzazione
 * - n: numero di passi
 *
 * Output:
 * - xi: nodo i-esimo
 * - yi: approssimazione al nodo xi
 *
 */
 
#include <stdio.h>
 
double f(double x, double y, double z);
double g(double x, double y, double z);
   
 int main()
 {
 
	// Allocazione e inizializzazione delle variabili

	int n=0, k=0;
	double x0=0., y0=0., z0, h=0.;
	double xi=0., yi=0., zi=0.;
	
	FILE *OUT = NULL;
	
	// Recupero dei dati dati di input
	
	printf("Inserire il numero n di passi = \n");
	scanf("%d", &n);
 	printf("Inserire il valore di h = \n");
	scanf("%lf", &h);
	printf("Inserire il valore di x0 = \n");
	scanf("%lf", &x0);
	printf("Inserire il valore di y0 = \n");
	scanf("%lf", &y0);
	printf("Inserire il valore di z0 = \n");
	scanf("%lf", &z0);
		
	/* Apertura file di output */
	OUT = fopen("Runge-Kutta_sistema.txt", "w");
	// Controllo apertura file
	if(OUT == NULL)
	{
		printf("Errore nell'apertura del file\n");
		printf("Riprovare\n");
		return(1);
	} /* if */
		
	// Implementazione dell'algoritmo di Runge-Kutta

	xi = x0;
	yi = y0;
	zi = z0;
	
	double k1=0, k2=0, k3=0, k4=0; /* Incrementa funzione y */
	double t1=0, t2=0, t3=0, t4=0; /* Incrementa funzione z */
	
	for (k=1; k<=n; k++)
	{
		k1 = f(xi, yi, zi);
		t1 = g(xi, yi, zi);
		
		k2 = f(xi + 0.5*h, yi + 0.5*h*k1, zi + 0.5*h*t1);
		t2 = g(xi + 0.5*h, yi + 0.5*h*k1, zi + 0.5*h*t1);
		
		k3 = f(xi + 0.5*h, yi + 0.5*h*k2, zi + 0.5*h*t2);
		t3 = g(xi + 0.5*h, yi + 0.5*h*k2, zi + 0.5*h*t2);
		
		k4 = f(xi + h, yi + h*k3, zi + h*t3);
		t4 = g(xi + h, yi + h*k3, zi + h*t3);
	
		yi = yi + h*(k1 + 2.0*k2 + 2.0*k3 + k4)/6.0;
		zi = zi + h*(t1 + 2.0*t2 + 2.0*t3 + t4)/6.0;
		
		xi = xi + h;
		// Stampa dei risultati 		
		fprintf(OUT, "%4d % 14.8lf % 14.8lf % 14.8lf\n", k, xi, yi, zi);
	}	
	
	fclose(OUT);
	
 	return 0;
 }
 
 // Implementazione della funzione f(x, y, z) del problema di Cauchy 

 double f(double x, double y, double z)
 {
 	return z;
 }
 
 // Implementazione della funzione g(x, y, z) del problema di Cauchy 

 double g(double x, double y, double z)
 {
 	return (-2. * 0.1 * z) - y;
 }
 
 
