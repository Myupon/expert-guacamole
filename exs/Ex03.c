/********************************************************************************
*                                                                              *
*                   Architetture dei sistemi di Elaborazione                   *
*                                                                              *
********************************************************************************

Elaborato 3
Descrizione: Dato un array di bit, restituire le posizioni dei soli bit
			 uguali a 1.

********************************************************************************/

#include <stdio.h>

void main()
{
	// Input
	unsigned char vet[] = { 0xAA,0xFC,0x09 };	//Array di byte
												//(da considerare come una sequenza di bit)
	unsigned short int len = 19;				//Lunghezza (numero di bit)

	// Output
	short posizioni[1024]; //Posizioni dei soli bit con valore 1

	__asm
	{
		
	}

	// Stampa su video
	{
		int i = 0;
		while (i <= len && posizioni[i] != -1)
		{
			printf("%d\n", posizioni[i++]);
		}
	}
}

