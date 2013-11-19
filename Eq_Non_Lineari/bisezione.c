/*
* The information in this file is
* Copyright(c) 2012, Gabriele Colosimo, Andrea Nascetti <gabriele.colosimo, andrea.nascetti>@uniroma1.it
* and is subject to the terms and conditions of the
* GNU Lesser General Public License Version 2.1
* The license text is available from
* http://www.gnu.org/licenses/lgpl.html
*/


/*
 * Soluzione di Eq. Non Lineari con il metodo della bisezione
 * 
 */ 

#include <stdio.h>
#include <math.h>

double f(double x);

int main()
{
	int N = 0;                      /* Numero delle iterazioni */
	double a = 0., b = 0., e = 0.;  /* Estremi intervallo di integrazione */
	double xi=0.;
	
	/* Lettura parametri di input */
	printf("Intervallo inferiore a: ");
	scanf("%lf", &a);
	printf("Intervallo superiore b: ");
	scanf("%lf", &b);
    printf("Valore di precisione e: ");
	scanf("%lf", &e);
	
	double err=1000.0;
	
	while (fabs(err) > e && N<1000) 
	{
	    err = xi;
		xi = a+(b-a)/2.0;
		
		if (f(a)*f(xi)<0.0) b = xi;
		else if (f(xi)*f(b)<0.0) a = xi;
		else 
		{
			printf("Raggiunto il numero massimo di 1000 iterazioni\n");
			return 0;
		}	
 
        err = xi - err;
		N++;
	}
	
	printf("\n La radice nell'intervallo selezionato è: %lf\n", xi);
	printf("\n Numero di iterazioni: %d\n", N);
	
	return 0; 
	
}

double f(double x) 
{
	return exp(-x/4.)*cos(x);
}
