/*
* The information in this file is
* Copyright(c) 2012, Gabriele Colosimo, Andrea Nascetti <gabriele.colosimo, andrea.nascetti>@uniroma1.it
* and is subject to the terms and conditions of the
* GNU Lesser General Public License Version 2.1
* The license text is available from
* http://www.gnu.org/licenses/lgpl.html
*/

/*
 *  Es. per il calcolo della retta di regressione:
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
	
/*  ---------------PARTE MANCANTE---------------------
 * 
 * inserire tutte le operazioni necessarie per calcolare 
 * la retta di regressione a partire dai dati immagazzinati in un file 
 * di input "dati.dat" 
 *
 */
		
	return 0;
}