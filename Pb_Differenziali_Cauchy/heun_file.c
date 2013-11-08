/*
* The information in this file is
* Copyright(c) 2012, Gabriele Colosimo, Andrea Nascetti <gabriele.colosimo, andrea.nascetti>@uniroma1.it
* and is subject to the terms and conditions of the
* GNU Lesser General Public License Version 2.1
* The license text is available from
* http://www.gnu.org/licenses/lgpl.html
*/

/* Programma di Heum: 
 *
 * Calcola la soluzione numerica di equazioni differenziali del primo ordine
 * con il metodo di Heum esplicito
 * 
 * Funzioni:
 * - f(t,y): termine noto dell’equazione differenziale 
 * - g(t): soluzione analitica del problema di Cauchy
 *
 * Input:
 * - t0, y0: condizione iniziale
 * - h: passo di discretizzazione
 * - n: numero di passi
 *
 * Output:
 * - ti: nodo i-esimo
 * - yi: approssimazione al nodo ti
 *
 */
 
#include <stdio.h>
#include <math.h>

double f(double t,double y);
double g(double t); 
  
 int main()
 {
 
	// Allocazione e inizializzazione delle variabili

	int n,k;
	double t0=0,y0=0,h=0;
	double ti=0,yi=0,err;
	
	FILE *OUT = NULL;

	// Recupero dei dati dati di input
	
	printf("Inserire il numero n di passi = \n");
	scanf("%d", &n);
 	printf("Inserire il valore di h = \n");
	scanf("%lf", &h);
	printf("Inserire il valore di t0 = \n");
	scanf("%lf", &t0);
	printf("Inserire il valore di y0 = \n");
	scanf("%lf", &y0);
	
	printf("n = %d \t h = %14.8lf \t t0 = %14.8lf \t y0 = %14.8lf\n\n",n,h,t0,y0);

	/* Apertura file di output */
	OUT = fopen("Heun_output.txt", "w");
	// Controllo apertura file
	if(OUT == NULL)
	{
		printf("Errore nell'apertura del file\n");
		printf("Riprovare\n");
		return(1);
	} /* if */
	
	// Implementazione dell'algoritmo di Heun

	ti = t0;
	yi = y0;
	
	for (k=1; k<=n; k++)
	{
		yi = yi + 0.5*h*(f(ti,yi) + f(ti+h,yi+h*f(ti,yi)));
		ti = ti + h;
		// Calcolo dell'errore
		err = g(ti)-yi;
		// Stampa dei risultati 		
	    printf("%4d % 14.8lf % 14.8lf % 14.8lf\n", k, ti, yi, err);
		fprintf(OUT, "%4d % 14.8lf % 14.8lf % 14.8lf\n", k, ti, yi, err);
	}
	
	fclose(OUT);
	
 	return 0; 
 }
 
  
// Implementazione della funzione f(t,y) del problema di Cauchy 

 double f(double t,double y)
 {
 	return y-t;
 }
 
// Implementazione della soluzione analitica g(t)

 double g(double t)
 {
 	return exp(t)+t+1;
 }
/*
 double f(double t,double y)
 {
 	return -y+t;
 }
 
// Implementazione della soluzione analitica g(t)

 double g(double t)
 {
 	return 2*exp(-t)+t-1;
 }
*/
