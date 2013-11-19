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
 * Soluzione del modello preda-predatore utilizzando
 * il metodo di Runge-Kutta IV ordine
 * 
 * Funzioni:
 * - y1(x, y, z)  
 * - y2(x, y, z)
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
 
double eq1(double y1, double y2);
double eq2(double y1, double y2);
   
 int main()
 {
 	// Allocazione e inizializzazione delle variabili

	int n=0, k=0;
	double x0=0., y10=0., y20, h=0.;
	double xi=0., y1i=0., y2i=0.;
	
	FILE *OUT = NULL;
	
	// Recupero dei dati dati di input
	
	printf("Inserire il numero n di passi = \n");
	scanf("%d", &n);
 	printf("Inserire il valore di h = \n");
	scanf("%lf", &h);
	printf("Inserire il valore di y10 = \n");
	scanf("%lf", &y10);
	printf("Inserire il valore di y20 = \n");
	scanf("%lf", &y20);
		
	/* Apertura file di output */
	OUT = fopen("Runge-Kutta_preda_predatore.txt", "w");
	// Controllo apertura file
	if(OUT == NULL)
	{
		printf("Errore nell'apertura del file\n");
		printf("Riprovare\n");
		return(1);
	} /* if */
		
	// Implementazione dell'algoritmo di Runge-Kutta

	xi = x0;
	y1i = y10;
	y2i = y20;
	
	double k1=0, k2=0, k3=0, k4=0;
	double t1=0, t2=0, t3=0, t4=0;
	
	for (k=1; k<=n; k++)
	{
		k1 = eq1(y1i, y2i);
		t1 = eq2(y1i, y2i);
		
		k2 = eq1(y1i + 0.5*h*k1, y2i + 0.5*h*t1);
		t2 = eq2(y1i + 0.5*h*k1, y2i + 0.5*h*t1);
		
		k3 = eq1(y1i + 0.5*h*k2, y2i + 0.5*h*t2);
		t3 = eq2(y1i + 0.5*h*k2, y2i + 0.5*h*t2);
		
		k4 = eq1(y1i + h*k3, y2i + h*t3);
		t4 = eq2(y1i + h*k3, y2i + h*t3);
	
		y1i = y1i + h*(k1 + 2.0*k2 + 2.0*k3 + k4)/6.0;
		y2i = y2i + h*(t1 + 2.0*t2 + 2.0*t3 + t4)/6.0;
		
		xi = xi + h;
		// Stampa dei risultati 		
		fprintf(OUT, "%4d % 14.8lf % 14.8lf % 14.8lf\n", k, xi, y1i, y2i);
	}	
	
	fclose(OUT);
	
 	return 0;
 }
 
 // Implementazione della funzione f(x, y, z) del problema di Cauchy 

 double eq1(double y1, double y2)
 {
	int mu2 = 200;
 	return (1-y2/mu2)*y1;
 }
 
 // Implementazione della funzione g(x, y, z) del problema di Cauchy 

 double eq2(double y1, double y2)
 {
	int mu1 = 300;
 	return -(1-y1/mu1)*y2;
 }
 
 
