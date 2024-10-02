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
 * multiply - multiplies two positive numbers
 * @num1: first number
 * @num2: second number
 * Return: a pointer to a string that contains the product of num1 and num2
 */
char *multiply(char *num1, char *num2)
{
	int len_num1 = 0, len_num2 = 0;
	int i, j, sum, mul, f, pos_zero = 0;

	while (num1[len_num1])
	{
		len_num1++;
	}
	while (num2[len_num2])
	{
		len_num2++;
	}
	int *res = malloc((len_num1 + len_num2 + 1) * sizeof(int));

	for (i = 0; i < len_num1 + len_num2; i++)
	{
		res[i] = 0;
	}
	for (i = len_num1 - 1; i >= 0; i--)
	{
		for (j = len_num2 - 1; j >= 0; j--)
		{
			mul = (num1[i] - '0') * (num2[j] - '0');
			sum = mul + res[i + j + 1];
			res[i + j + 1] = sum % 10;
			res[i + j] += sum / 10;
		}
	}
	while (pos_zero < len_num1 + len_num2 && res[pos_zero] == 0)
	{
		pos_zero++;
	}
	char *final_res = malloc(len_num1 + len_num2 - pos_zero + 1);

	for (f = pos_zero; f < len_num1 + len_num2; f++)
	{
		final_res[f - pos_zero] = res[f] + '0';
	}
	final_res[len_num1 + len_num2 - pos_zero] = '\0';
	free(res);
	return (final_res);
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
 * main - entry point
 * @argc: number of arguments
 * @argv: array of argument values
 * Return: 0 on success or exit with code 98 on error.
 */
int main(int argc, char *argv[])
{
	if (argc != 3 || !is_digit(argv[1]) || !is_digit(argv[2]))
	{
		print_complete_string("Error");
		exit(98);
	}
	char *res = multiply(argv[1], argv[2]);

	print_complete_string(res);
	free(res);
	return (0);
}
