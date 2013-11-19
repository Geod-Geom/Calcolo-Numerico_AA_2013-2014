/*
* The information in this file is
* Copyright(c) 2012, Gabriele Colosimo, Andrea Nascetti <gabriele.colosimo, andrea.nascetti>@uniroma1.it
* and is subject to the terms and conditions of the
* GNU Lesser General Public License Version 2.1
* The license text is available from
* http://www.gnu.org/licenses/lgpl.html
*/

/*
 * Calcolo della media utilizzando i vettori
 * Dopo aver inserito n numeri da tastiera, il programma
 * ne calcola la media
 */
#include <stdio.h>
double CALCOLO_MEDIA(int num, double a[num]); /* PROTOTIPO */

int main()
{
	int i=0, n=0;
	
	printf("Inserire la dimensione del vettore: ");
	scanf("%d", &n);
	
	double a[n];
	
	/* Lettura dati di input */
	while(i < n)
	{
		printf("Inserire il numero (%2d): ", i);
		scanf("%lf", &a[i]);
		i++;
	} /* while */

	/* Calcolo della media */
	printf("La media dei %d elementi e': %9.5lg\n", n, CALCOLO_MEDIA(n, a));

	return 0;
} /* main */

/* DICHIARAZIONE DELLA FUNZIONE */
double CALCOLO_MEDIA(int num, double a[num])
{
	int i;
	double media=0.0;
	
	for(i=0; i < num; i++)
		media += a[i];
	
	return media/num;
}
