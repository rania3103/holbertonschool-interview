#include "menger.h"
/**
 * is_empty - check if the cell should be empty or not
 * @row: the indew of the row
 * @col: the index of the col
 * Return: 1 if the cell should be empty otherwise 0
 */
int is_empty(int row, int col)
{
	while (row > 0 || col > 0)
	{
		if (row % 3 == 1 && col % 3 == 1)
			return (1);
		row /= 3;
		col /= 3;
	}
	return (0);
}
/**
 * menger - draws a 2D Menger Sponge
 * @level: the level of the Menger Sponge to draw
 */
void menger(int level)
{
	if (level < 0)
		return;
	int size = pow(3, level);
	int row, col;

	for (row = 0; row < size; row++)
	{
		for (col = 0; col < size; col++)
		{
			if (is_empty(row, col))
				printf(" ");
			else
				printf("#");
		}
		printf("\n");
	}
}
