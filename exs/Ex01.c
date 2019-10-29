/*
Ex01
Given an array of pointers to string (every cell of the vector containing the 32-bit
address of the first character of the string), find the first substring occurrence
in each string of the vector.
*/

#include "stdafx.h"

void main()
{
	// Input
	char* strings[] =	{
							"C Exercise","Number One",
							"Hercules","Have Mercy"
						};							//Array of pointers to string
	int num = sizeof(strings) / sizeof(strings[0]);	//Array strings count
	char subStr[] = "erc";							//Substring to look for

	// Output
	int pos[256];	//Positions in which the substring has been found

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
	L2: MOV pos[EBX], EDX
		INC EBX
		CMP EBX, num
		JL L4
	}

	// Print
	{
		int i;
		for (i = 0; i<num; i++)
		{
			printf("Substring Position = %d of string [%d]\n", pos[i], i);
		}
	}
	getchar();
}
