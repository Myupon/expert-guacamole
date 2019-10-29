/*
Ex02
Given the maximum level as input, print the respective Pascal's Triangle
memorizing consecutively the different levels in a monodimensional array.
*/

#include <stdio.h>

void main()
{
	// Input
	unsigned int level = 8;		// Maximum level to generate

	// Output
	unsigned int triangle[1024];	// Result: contains the triangle numbers from
					// the lowest to the highest level requested

	unsigned int i;
	unsigned int k = 0;
	
	__asm
	{
		MOV triangle[0], 1
		CMP level, 1
		JL L1
		MOV EAX, 1
		MOV EDX, level
		MOV ECX, 1
		MOV triangle[EAX*4], 1


		DEC EDX
		JNZ L2
	L1: 
	}

	// Print
	printf("Pascal's Triangle of %d levels\n", level);
	for (i = 0; i <= level; i++)
	{
		unsigned int j;
		for (j = 0; j <= i; j++)
			printf("%d ", triangle[k++]);
		printf("\n");
	}
}


