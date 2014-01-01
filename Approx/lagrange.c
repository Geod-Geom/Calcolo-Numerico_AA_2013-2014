/*
* The information in this file is
* Copyright(c) 2012, Gabriele Colosimo, Andrea Nascetti <gabriele.colosimo, andrea.nascetti>@uniroma1.it
* and is subject to the terms and conditions of the
* GNU Lesser General Public License Version 2.1
* The license text is available from
* http://www.gnu.org/licenses/lgpl.html
*/

/*
 * Programma per il calcolo dell'interpolazione con i Polinomi di Lagrange:
 *  
 *  Input: nodi Xi,Yi tabulati in un file "dati.dat"
 *  	        Xc: posizione dove calcolare il valore approx
 *  Output:     Yc(X)
 */ 
 
#include <stdio.h>
#include <math.h>
               
int main()
{
	int n,i,k,j;
	double Xc=0,Yc=0;

	/* Lettura parametri di input */
	printf("Inserire il numero di dati n: ");
	scanf("%d", &n);
	
	FILE *input=NULL;
	input = fopen("dati3.dat","r");
	
	if(input == NULL)
	{
		printf("Errore nell'apertura del file di input\n\n");
		printf("Riprovare\n");
		return 1;
	}
	
	double X[n];
	double Y[n];
	double l[n];
	
	/* Lettura dei dati di input */
	for (i=0;i<n;i++)
	{
		fscanf(input,"%lf %lf",&X[i],&Y[i]);
		printf("%10.6lf %10.6lf\n",X[i],Y[i]);
	}
	
	printf("\nInserire il valore della X nel quale calcolare il valore interpolato: ");
	scanf("%lf", &Xc);	
	
	/* Calcolo dei coefficienti di Lagrange li */
	
	for (k=0;k<n;k++)
	{
		l[k]=1.0;
		for (j=0;j<n;j++)
		{
			if (j != k)
			{
				l[k]*= (Xc-X[j])/(X[k]-X[j]);
			}
			
		}
	}
	
	for (i=0;i<n; i++)
	{
		Yc += Y[i]*l[i];
	}
	
	printf("\n Il valore della Yc = %15.8lf\n",Yc);
	
	return 0;
	
}
	
