#include "holberton.h"
/**
 * is_digit - checks if a string contains only digits
 * @str: string to be checked
 * Return: 1 if the string contains only digits otherwise 0
 */
int is_digit(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			return (0);
		}
		i++;
	}
	return (1);
}
/**
 * print_complete_string - prints a complete string
 * @ch: string to be printed
 */
void print_complete_string(char *ch)
{
	int i = 0;

	while (ch[i])
	{
		_putchar(ch[i]);
		i++;
	}
	_putchar('\n');
}
/**
 * main - prints the result of the product of 2 numbers
 * @argc: number of arguments
 * @argv: array of argument values
 * Return: 0 on success or exit with code 98 on error.
 */
int main(int argc, char *argv[])
{
	char *num1, *num2, *result;
	int total_len, len_num1 = 0, len_num2 = 0, i, mul, sum, j, pos_zero = 0;

	if (argc != 3 || !is_digit(argv[1]) || !is_digit(argv[2]))
	{
		print_complete_string("Error");
		exit(98);
	}
	num1 = argv[1], num2 = argv[2];
	while (num1[len_num1])
		len_num1++;
	while (num2[len_num2])
		len_num2++;
	total_len = len_num1 + len_num2 - 2;
	result = (char *)malloc(total_len);
	for (i = 0; i < total_len; i++)
		result[i] = 0;
	for (i = len_num1 - 1; i >= 0; i--)
	{
		for (j = len_num2 - 1; j >= 0; j--)
		{
			mul = (num1[i] - '0') * (num2[j] - '0');
			sum = mul + result[i + j + 1];
			result[i + j + 1] = sum % 10;
			result[i + j] += sum / 10;
		}
	}
	for (i = pos_zero; i < total_len; i++)
		result[i] += '0';
	while (pos_zero < total_len - 1 && result[pos_zero] == '0')
		pos_zero++;
	print_complete_string(result + pos_zero);
	free(result);
	return (0);
}
