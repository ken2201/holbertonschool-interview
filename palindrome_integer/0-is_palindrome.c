#include "palindrome.h"

/**
 * is_palindrome - Checks whether or not a given unsigned integer
 *                 is a palindrome
 * @n: The number to be checked
 *
 * Return: 1 if n is a palindrome, 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long reversed = 0;
	unsigned long temp = n;

	while (temp > 0)
	{
		reversed = reversed * 10 + temp % 10;
		temp /= 10;
	}

	return (reversed == n ? 1 : 0);
}
