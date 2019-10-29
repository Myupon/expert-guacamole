/********************************************************************************
*                                                                              *
*                   Architetture dei sistemi di Elaborazione                   *
*                                                                              *
********************************************************************************

Elaborato 1
Descrizione: Dato un array di puntatori a stringa (ogni cella del vettore contiene
			 l'indirizzo a 32 bit del primo carattere della stringa), cercare la
			 prima occorrenza di una sottostringa all'interno di ogni stringa del
			 vettore.

********************************************************************************/

#include "stdafx.h"

void main()
{
	// Input
	char* strings[] =	{
							"Elaborato di Architetture","139",
							"L'Arco del cerchio","L'arco di trionfo"
						};							//Array di puntatori a stringa
	int num = sizeof(strings) / sizeof(strings[0]);	//Il numero di stringhe nell'array
	char subStr[] = "Arc";							//La sottostringa da cercare

	// Output
	int posizioni[256];	//Posizioni in cui ・stata trovata la sottostringa

	__asm
	{
		XOR EBX, EBX
	L4: XOR EDX, EDX
	L3: XOR ESI, ESI
		MOV EAX, strings[EBX]
	L1: MOV CL, subStr[ESI]
		CMP CL, 0
		JE L2
		CMP [EAX+ESI], CL
		INC ESI
		JE L1
		INC EAX
		JMP L3
	L2: MOV posizioni[EBX], EDX
		INC EBX
		CMP EBX, num
		JL L4
	}

	// Stampa su video
	{
		int i;
		for (i = 0; i<num; i++)
		{
			printf("Sottostringa in posizione=%d della stringa[%d]\n", posizioni[i], i);
		}
	}
	getchar();
}
