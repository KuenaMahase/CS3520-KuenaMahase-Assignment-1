//Kuena Mahase 202000020 CS3520 Assignment 1
//Number : 59598785/69426317
//email: kuenamahase1101@gmail.com


#include <stdio.h>
#include <math.h>
#include <stdbool.h>

//declaration of functions
int SquareprimeNumber();
int ReversePrimeNum();
int Palindrome();
int Reversedroots();

//declaration of arrays
int SquarePrimeNum[1000000];
int reverseSquarePrime[1000000];
int non_palindrome[1000000];
int palindrome[1000000];
int reversedRoots[1000000];
int NONreversedRoots[1000000];

int num, square, rem, b = 0, r = 0,a = 0;

int SquareprimeNumber( )
{
	// prime is declared as false term
	bool prime = false; 
	//test for prime numbers
	for ( num = 0; num <= 3500; num++)
	{	
		if ( num == 0 || num == 1) //if numbers in the loop consist of 1 and 0, they are not prime numbers
		{
			continue;
		}	
		prime = true;	
	//consider prime to be true 
		for ( int i = 2; i <= num/2; i++)
		{
			if ( num % i == 0)     // if the remainder when dividing a number by a number less than half of it is zero.
			{
				prime = false;     //number is not prime.
				break;
			}	
		}
		
		if (prime)		//but if number is prime , that is leaves a remainder when divided by numbers less than half of it, the number is prime.
		{
			square = num*num; //squaring the prime number
			SquarePrimeNum[a] = square;
			a++;
		}	
	}
}

int ReversePrimeNum()
{
	SquareprimeNumber();
	
	int c = 0;
	while( c < a )
		{
			int result = 0;
			int	d = SquarePrimeNum[c];
			for( ; d != 0; )
			{
				rem = d % 10; //to attain the remainder when dividing squared prime numbers by 10,this extracts the last digit of the square number
				result = result*10 + rem;  //multiply the remainder by 10 to shift its place value, making the remainder the first digit on the right 
				d = d/10; //to reduce the place value of the squarenumber,but now it is without the last digit
			}
			reverseSquarePrime[r] = result;
			
			r++;
			c++;		
		}				
}

int y = 0,e = 0;
int Palindrome()
{
	ReversePrimeNum();
	while (y < a)
	{
		if ( SquarePrimeNum[y] == reverseSquarePrime[y])  //if square prime number is equal to reverse square prime number
		{
			palindrome[y] = reverseSquarePrime[y];        //then it is a palindrome
		}
		else											//else,
		{
			non_palindrome[e] = reverseSquarePrime[y];	// it is not a palindrome
			e++;
		}
		y++;	
	}
}

int Reversedroots()
{
	Palindrome();
	int v = 0, k = 0, g = 0, x = 1;
	
	for ( v = 0 ; v < e; v++)
	{
		int r = sqrt(non_palindrome[v]);
		if ( non_palindrome[v] == r*r )	//if not palindromes are equal to the square of square roots of non palindromes
		{
			{
				if( ( r != 0)&&( r != 1)&&( r % 2 != 0)&&( r % 3 != 0)&&(r % 5 != 0)&&(r % 7 != 0)) //if square roots of non palindromes are prime
				{	
					reversedRoots[k] = non_palindrome[v];	//then not palindromes are reversible prime squares and stores them in an array
					g++;
					k++;
					x++;
				}	
				else 
					NONreversedRoots[k] = non_palindrome[v];			
			}
		}
	}
 	
    if ( g = 10 )  //count upto 10
	{
		printf("\n reversible prime squares  are : \n");
    	for ( int t = 0; t < g; t++)
		{
			printf(" %d \n", reversedRoots[t]);	 	//displays only 10 reversible prime squares
		}
	}
}

int main ()
{
	Reversedroots();
	
	return 0;
}
