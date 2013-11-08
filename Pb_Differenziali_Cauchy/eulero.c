/*
* The information in this file is
* Copyright(c) 2012, Gabriele Colosimo, Andrea Nascetti <gabriele.colosimo, andrea.nascetti>@uniroma1.it
* and is subject to the terms and conditions of the
* GNU Lesser General Public License Version 2.1
* The license text is available from
* http://www.gnu.org/licenses/lgpl.html
*/

/* Programma di Eulero: 
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

double f(double t, double y);
double g(double t); 
 
int main()
{
	// Allocazione e inizializzazione delle variabili
	int n = 0, k = 0;
	double t0 = 0., y0 = 0., h = 0.;
	double ti = 0., yi = 0., yi_1=0. /* la nostra y(i+1)*/;
	double err = 0.;

	// Recupero dei dati dati di input
	printf("Inserire il numero n di passi = \n");
	scanf("%d", &n);
 	printf("Inserire il valore di h = \n");
	scanf("%lf", &h);
	printf("Inserire il valore di t0 = \n");
	scanf("%lf", &t0);
	printf("Inserire il valore di y0 = \n");
	scanf("%lf", &y0);
	
	printf("n = %d \t h = % 14.8lf \t t0 = % 14.8lf \t y0 = % 14.8lf\n\n", n, h, t0, y0);
	
	printf(" Indice      t              y           errore\n");
	// Implementazione dell'algoritmo di Eulero
	ti = t0;
	yi = y0;
	
	for (k=1; k<=n; k++)
	{
		yi_1 = yi + h * f(ti,yi);
		// Calcolo dell'errore
		err = g(ti + h) - yi_1;
		// Stampa dei risultati 		
		printf("%4d % 14.8lf % 14.8lf % 14.8lf\n", k, ti + h, yi_1, err);
		// Aggiornamento variabili
		yi = yi_1;
		ti = ti + h;
	}/* for */
	
 	return 0;
}

// Implementazione della funzione f(t,y) del problema di Cauchy 
 double f(double t, double y)
 {
 	return y-t;
 }

// Implementazione della soluzione analitica g(t)
 double g(double t)
 {
 	return exp(t)+t+1;
 }
