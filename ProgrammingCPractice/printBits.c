#include <stdio.h>

int countBits(int binNum);
int padBits(int binNum);
void printBin(int binNum, int numBits);

void printBits(int val)
{
	printf("Value as Int: %d\n", val);
	int number = val;
	int i = 1;
	int remainder;
	int bin = 0;

	while(number != 0)
	{
		//printf("Result: %d ResultMod2: %d\n",result, result%2);
		//printf("Counter: %d\n", counter);
		//counter++;
		//result = result/2;
		remainder = number%2;
		number = number/2;
		bin = bin + (remainder*i);
		i = i*10;
	}

	printf("Binary: %d\n", bin);
	printf("There are %d bits in the above number.\n", countBits(bin));
	printf("We need to pad %d bits.\n", 32-countBits(bin));
	bin = padBits(bin);
	//printBin(bin, countBits(bin));


	/*
	printf("Final Counter Value: %d\n",counter);
	int i;
	for (i = 3; i > 0; i--)
	{
		printf("%d", i);
		//printf(bytes[i]);
	}
	printf("\n");
	*/
}
int countBits(int binNum)
{
	int i = 0;
	while(binNum != 0)
	{
		i++;
		binNum = binNum/10;
	}
	return i;
}
int padBits(int binNum)
{
	int numToPad = 32-countBits(binNum);
	int i;
	for(i = numToPad; i > 0; i--)
	{
		if (i%8 == 0 && i != numToPad)
		{
			printf(" ");
		}
		printf("0");
	}
}
void printBin(int binNum, int numBits)
{
	int i;
	for(i = 0; i <= numBits; i++)
	{
		if(i%8 == 0)
		{
			printf(" ");
		}
		printf(binNum / (i * 10));
	}
}
