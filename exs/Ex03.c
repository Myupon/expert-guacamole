/*
Ex03
Given a bit array only print the positions of the bits set to 1.
*/

#include <stdio.h>

void main()
{
	// Input
	unsigned char vect[] = { 0xAA,0xFC,0x09 };	//Byte Array
							//(to be considered as bit sequence)
	unsigned short int len = 19;			//Length (bit count)

	// Output
	short pos[1024]; //Positions of the bits set to 1

	__asm
	{
		
	}

	// Print
	{
		int i = 0;
		while (i <= len && pos[i] != -1)
		{
			printf("%d\n", pos[i++]);
		}
	}
}

