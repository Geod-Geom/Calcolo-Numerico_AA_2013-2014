/* Programma: MaxMin
 *
 * Il programma stampa il massimo e il minimo dei tipi di dati
 * che verranno usati frequentemente nel corso (int, long int, float, 
 * double, long double)
 * 
 * Compilare con:
 * 	gcc -o ES3_MaxMin ES3_MaxMin.c
 */

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{ 
	printf("Dimensione [bytes] di un int: %30lu\n", sizeof(int));
	printf("Valore massimo per un intero (\"INT_MAX\"): %30d\n", INT_MAX);
	printf("Il numero intero successivo (\"INT_MAX + 1\"): %27d\n", INT_MAX + 1);
	printf("Valore minimo per un intero (\"INT_MIN\"): %31d\n", INT_MIN);
	printf("Il numero intero inferiore (\"INT_MIN - 1\"): %28d\n\n", INT_MIN - 1);
	
	printf("Dimensione [bytes] di un long int: %25lu\n", sizeof(long int));
	printf("Valore massimo per un intero (\"LONG_MAX\"): %30ld\n", LONG_MAX);
	printf("Il numero intero successivo (\"LONG_MAX + 1\"): %27ld\n", LONG_MAX + 1);
	printf("Valore minimo per un intero (\"LONG_MIN\"): %31ld\n", LONG_MIN);
	printf("Il numero intero inferiore (\"LONG_MIN - 1\"): %28ld\n\n", LONG_MIN - 1);
	
	printf("Dimensione [bytes] di un float: %28lu\n", sizeof(float));
	printf("Valore massimo per un float (\"FLT_MAX\"): %31g\n", FLT_MAX);
	printf("Il float superiore (\"FLT_MAX + 1\"): %36g\n", FLT_MAX + 1);
	printf("Valore minimo per un float (\"FLT_MIN\"): %32g\n", FLT_MIN);
	printf("Il float inferiore (\"FLT_MIN - 1\"): %36g\n", FLT_MIN - 1);
	printf("Numero di cifre significative di un float %30d\n\n", FLT_DIG);	
	
	printf("Dimensione [bytes] di un double: %27lu\n", sizeof(double));
	printf("Valore massimo per un double (\"DBL_MAX\"): %30lg\n", DBL_MAX);
	printf("Il double superiore (\"DBL_MAX + 1\"): %35lg\n", DBL_MAX + 1);
	printf("Valore minimo per un double (\"DBL_MIN\"): %31lg\n", DBL_MIN);
	printf("Il double inferiore (\"DBL_MIN - 1\"): %35lg\n", DBL_MIN - 1);
	printf("Numero di cifre significative di un double %29d\n\n", DBL_DIG);	
	
	printf("Dimensione [bytes] di un long double: %23lu\n", sizeof(long double));
	printf("Valore massimo per un double (\"LDBL_MAX\"): %29Lg\n", LDBL_MAX);
	printf("Il double superiore (\"LDBL_MAX + 1\"): %34Lg\n", LDBL_MAX + 1);
	printf("Valore minimo per un double (\"LDBL_MIN\"): %30Lg\n", LDBL_MIN);
	printf("Il double inferiore (\"LDBL_MIN - 1\"): %34Lg\n", LDBL_MIN - 1);
	printf("Numero di cifre significative di un long double %24d\n\n", LDBL_DIG);	
	
	return 0;
}
