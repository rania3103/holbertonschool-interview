#include <stdio.h>
#include "sandpiles.h"
/**
 * check_is_stable - checks if the grid is stable
 * @grid: the grid to be checked
 * Return:0 unstable, 1 stable
*/
int check_is_stable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
			{
				return (0);
			}
		}
	}
	return (1);
}
/**
 * toppling_round - topples the grid
 * @grid: the 3*3 grid
*/
void toppling_round(int grid[3][3])
{
	int i, j;

	int unstable = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
			{
				grid[i][j] -= 4;
				if (i > 0)
				{
					grid[i - 1][j] += 1;
				}
				if (i < 2)
				{
					grid[i + 1][j] += 1;
				}
				if (j > 0)
				{
					grid[i][j - 1] += 1;
				}
				if (j < 2)
				{
					grid[i][j + 1] += 1;
				}
				unstable = 1;
			}
		}
	}
	if (unstable)
	{
		toppling_round(grid);
	}
}
/**
 * print_grid_ - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
void print_grid_(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}
/**
 * sandpiles_sum - computes the sum of two sandpiles
 * @grid1:Left 3x3 grid
 * @grid2:Right 3x3 grid
*/
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}
	while (!check_is_stable(grid1))
	{
		printf("=\n");
		print_grid_(grid1);
		toppling_round(grid1);
	}
}
