#include "shell.h"

/**
 * interactive - returns true if shell is interactive mode
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
interactive(info_t *info): The function checks if the shell is in interactive mode by using the isatty() function to determine if the standard input is a terminal and checking the file descriptor readfd in the info structure to be less than or equal to 2 (which typically refers to standard input, output, and error). It returns 1 if it's in interactive mode and 0 otherwise.

}

/**
 * is_delim - checks if character is a delimeter
 * return: 1 if true, 0 if false
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
is_delim(char c, char *delim): The function checks if a given character c is a delimiter by iterating through the characters in the delim string and comparing them to c. If a match is found, it returns 1; otherwise, it returns 0.
}


/**
 * _isalpha - checks for alphabetic character
 */

int _isalpha(int c)
{
_isalpha(int c): The function checks  a given character c is an alphabetic character (either uppercase or lowercase). It uses ASCII values to determine if c falls within the range of alphabetic characters ('a' to 'z' or 'A' to 'Z') and returns 1 if it's an alphabetic character and 0 otherwise.



	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - converts a string to an integer
 */

int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);

