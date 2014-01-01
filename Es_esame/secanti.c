/*
* The information in this file is
* Copyright(c) 2012, Gabriele Colosimo, Andrea Nascetti <gabriele.colosimo, andrea.nascetti>@uniroma1.it
* and is subject to the terms and conditions of the
* GNU Lesser General Public License Version 2.1
* The license text is available from
* http://www.gnu.org/licenses/lgpl.html
*/

/*
 * Soluzione di Eq. Non Lineari con il metodo 
 * delle Secanti
 */ 

#include <stdio.h>
#include <math.h>

double f(double x);                  /* Funzione di cui si cercano gli zeri */

int main()
{
	int N_max = 10;                  /* Numero massimo delle iterazioni */
	int N = 0;                       /* Numero di iterazioni */
	double a = 0., b = 0.;           /* Estremi intervallo di integrazione */
	double err1 = 0., err2 = 0.;     /* Due modi di valutazione dell'errore */
	double err_max = 0.;             /* Errore massimo accettabile */
	double x0 = 0.;                  /* Approssimazione iniziale 0 */
	double x1 = 0.;                  /* Approssimazione iniziale 1 */
	double xk = 0.;                  /* Soluzione k-sima */
	
	/* Lettura parametri di input */
	printf("Intervallo inferiore a: ");
	scanf("%lf", &a);
	printf("Intervallo superiore b: ");
	scanf("%lf", &b);
	printf("Errore massimo accettabile: ");
	scanf("%lf", &err_max);
	printf("Approssimazione iniziale x0: ");
	scanf("%lf", &x0);
	printf("Approssimazione iniziale x1: ");
	scanf("%lf", &x1);
	
	
/*  ---------------PARTE MANCANTE---------------------
 * 
 * inserire tutte le operazioni necessarie per calcolare 
 * la radice X delle eq.non lineare con il metodo delle secanti
 *
 */
		
	return 0; 
}/* main */

double f(double x) 
{
	return exp(x) + (0.435 / x) * (exp(x) - 1) - 1.564;
}

