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
			return (0);
		i++;
	}
	return (1);
}
/**
 * print_zero - prints character 0 with new line
 */
void print_zero(void)
{
	_putchar('0');
	_putchar('\n');
}
/**
 * print_error - prints error and exit with code 98
 */
void print_error(void)
{
	char *ch = "Error";
	int i;

	for (i = 0; ch[i]; i++)
		_putchar(ch[i]);
	_putchar('\n');
	exit(98);
}
/**
 * _len - returns length of a string
 * @ch:string
 * Return: length of string
 */
int _len(char *ch)
{
	int len = 0;

	while (ch[len] != '\0')
		len++;
	return (len);
}
/**
 * main - prints the result of the product of 2 numbers
 * @argc: number of arguments
 * @argv: array of argument values
 * Return: 0 on success or exit with code 98 on error.
 */
int main(int argc, char *argv[])
{
	char *num1, *num2;
	int total_len, len_num1, len_num2, i,
	mul, sum, j, *result, pos_zero = 0;

	if (argc != 3 || !is_digit(argv[1]) || !is_digit(argv[2]))
		print_error();
	num1 = argv[1], num2 = argv[2];
	len_num1 = _len(num1);
	len_num2 = _len(num2);
	total_len = len_num1 + len_num2;
	result = malloc(total_len * sizeof(int));
	if (result == NULL)
		print_error();
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
	while (pos_zero < total_len && result[pos_zero] == 0)
		pos_zero++;
	if (pos_zero == total_len)
		print_zero();
	else
	{
		for (i = pos_zero; i < total_len; i++)
			_putchar(result[i] + '0');
		_putchar('\n');
	}
	free(result);
	return (0);
}
