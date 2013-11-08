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
 
// Implementazione della funzione f(t,y) del problema di Cauchy 

 double f(double x,double y)
 {
 	return y-x;
 }
 
// Implementazione della soluzione analitica g(t)

 double g(double t)
 {
 	return exp(t)+t+1;
 }
 
 int main()
 {
 
	// Allocazione e inizializzazione delle variabili

	int n,k;
	double t0=0,y0=0,h=0;
	double ti=0,yi=0,err;

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
	
	// Implementazione dell'algoritmo di Eulero

	ti = t0;
	yi = y0;
	
	for (k=1; k<=n; k++)
	{
		yi = yi + 0.5*h*(f(ti,yi) + f(ti+h,yi+h*f(ti,yi)));
		ti = ti + h;
		// Calcolo dell'errore
		err = g(ti)-yi;
		// Stampa dei risultati 		
		printf("t%d \t= %14.8lf \t y%d \t= %14.8lf \t e=%14.8lf\n", k,ti,k,yi,err);
	}
 	return 0; 
 }