/*
* The information in this file is
* Copyright(c) 2012, Gabriele Colosimo, Andrea Nascetti <gabriele.colosimo, andrea.nascetti>@uniroma1.it
* and is subject to the terms and conditions of the
* GNU Lesser General Public License Version 2.1
* The license text is available from
* http://www.gnu.org/licenses/lgpl.html
*/

/*
 * Programma per il calcolo della retta di regressione:
 *  Y = a0 + a1*X
 *  Input: file "dati.dat"
 *  Output: a0,a1
 */ 
 
#include <stdio.h>
#include <math.h>
               
int main()
{
	int n,i;

	/* Lettura parametri di input */
	printf("Inserire il numero di dati n: ");
	scanf("%d", &n);
	
	FILE *input=NULL;
	input = fopen("dati.dat","r");
	
	if(input == NULL)
	{
		printf("Errore nell'apertura del file di input\n\n");
		printf("Riprovare\n");
		return 1;
	}
	
	double X[n];
	double Y[n];
	
	// Lettura dei dati di input	
	for (i=0;i<n;i++)
	{
		fscanf(input,"%lf %lf",&X[i],&Y[i]);
		printf("%10.6lf %10.6lf\n",X[i],Y[i]);
	}
	
	//Calcolo della retta di regressione
	
	double s0=0,s1=0,s2=0,v0=0,v1=0;
	double a0=0,a1=0;
	
	s0=n;
	
	for (i=0;i<n;i++)
	{
		s1 += X[i];
		s2 += X[i]*X[i];
		v0 += Y[i];
		v1 += X[i]*Y[i];
	}
	
	double den = s0*s2-s1*s1;
	a0 = (v0*s2-v1*s1) / den;
	a1 = (s0*v1-s1*v0) / den;
	
	printf("a0 = %15.10lf\n",a0);	
	printf("a1 = %15.10lf\n",a1);
		
	return 0;
}