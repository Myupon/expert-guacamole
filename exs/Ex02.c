/********************************************************************************
*                                                                              *
*                   Architetture dei sistemi di Elaborazione                   *
*                                                                              *
********************************************************************************

Elaborato 2
Descrizione: Dato in input il livello massimo richiesto, restituire il rispettivo
			 triangolo di Tartaglia memorizzando consecutivamente i vari livelli
			 all'interno di un array monodimensionale.

********************************************************************************/

#include <stdio.h>

void main()
{
	// Input
	unsigned int livello = 8;		// livello massimo del triangolo di tartaglia da generare

	// Output
	unsigned int triangolo[1024];	// risultato: il vettore contiene i numeri del 
									// triangolo dal livello 0 al pi・alto richiesto

	unsigned int i;
	unsigned int k = 0;
	
	__asm
	{
		MOV triangolo[0], 1
		CMP livello, 1
		JL L1
		MOV EAX, 1
		MOV EDX, livello
		MOV ECX, 1
		MOV triangolo[EAX*4], 1


		DEC EDX
		JNZ L2
	L1: 
	}

	// Stampa su video
	printf("Triangolo di Tartaglia fino al livello %d\n", livello);
	for (i = 0; i <= livello; i++)
	{
		unsigned int j;
		for (j = 0; j <= i; j++)
			printf("%d ", triangolo[k++]);
		printf("\n");
	}
}


