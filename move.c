#include "so_long.h"

void points(char ***map)
{
	int		i;
	int		j;

	i = -1;
	while ((*map)[++i] != NULL)
	{
		j = -1;
		while ((*map)[i][++j] != '\0')
		{
			if ((*map)[i][j] == 'C')
				(*img()).points++;
		}
	}
}

int	move_up(char ***map)
{
	int		i;
	int		j;

	i = -1;
	while ((*map)[++i] != NULL)
	{
		j = -1;
		while ((*map)[i][++j] != '\0')
		{
			while (((*map)[i][j] == 'P' && (*map)[i - 1][j] == '0') || ((*map)[i][j] == 'P' && (*map)[i - 1][j] >= '2' && (*map)[i - 1][j] <= '5'))
			{
				(*map)[i][j] = '2';
				(*map)[i - 1][j] = 'P';
				i--;
			}
			if ((*map)[i][j] == 'P' && (*map)[i - 1][j] == 'C')
			{
				(*map)[i][j] = '2';
				(*map)[i - 1][j] = 'P';
				(*img()).points--;
				i--;
				i--;
			}
			if ((*map)[i][j] == 'P' && (*map)[i - 1][j] == 'E' && (*img()).points == 0 )
			{
				exit(1);
			}
		}
	}
	return (0);
}

int	move_left(char ***map)
{
	int		i;
	int		j;

	i = -1;
	while ((*map)[++i] != NULL)
	{
		j = -1;
		while ((*map)[i][++j] != '\0')
		{
			while (((*map)[i][j] == 'P' && (*map)[i][j - 1] == '0') || ((*map)[i][j] == 'P' && (*map)[i][j - 1] >= '2' && (*map)[i][j - 1] <= '5'))
			{
				(*map)[i][j] = '2';
				(*map)[i][j - 1] = 'P';
				j--;
			}
			if ((*map)[i][j] == 'P' && (*map)[i][j - 1] == 'C')
			{
				(*map)[i][j] = '2';
				(*map)[i][j - 1] = 'P';
				(*img()).points--;
				i--;
			}
			if ((*map)[i][j] == 'P' && (*map)[i][j - 1] == 'E' && (*img()).points == 0 )
			{
				exit(1);
			}
		}
	}
	return (0);
}

int	move_right(char ***map)
{
	int		i;
	int		j;

	i = -1;
	while ((*map)[++i] != NULL)
	{
		j = -1;
		while ((*map)[i][++j] != '\0')
		{
			while (((*map)[i][j] == 'P' && (*map)[i][j + 1] == '0') || ((*map)[i][j] == 'P' && (*map)[i][j + 1] >= '2' && (*map)[i][j + 1] <= '5'))
			{
				(*map)[i][j] = '2';
				(*map)[i][j + 1] = 'P';
				j++;
			}
			if ((*map)[i][j] == 'P' && (*map)[i][j + 1] == 'C')
			{
				(*map)[i][j] = '2';
				(*map)[i][j + 1] = 'P';
				(*img()).points--;
				i--;
			}
			if ((*map)[i][j] == 'P' && (*map)[i][j + 1] == 'E' && (*img()).points == 0 )
			{
				exit(1);
			}
		}
	}
	return (0);
}

int	move_down(char ***map)
{
	int		i;
	int		j;

	i = -1;
	while ((*map)[++i] != NULL)
	{
		j = -1;
		while ((*map)[i][++j] != '\0')
		{
			while (((*map)[i][j] == 'P' && (*map)[i + 1][j] == '0') || ((*map)[i][j] == 'P' && (*map)[i + 1][j] >= '2' && (*map)[i + 1][j] <= '5'))
			{
				(*map)[i][j] = '2';
				(*map)[i + 1][j] = 'P';
				i++;
			}
			if ((*map)[i][j] == 'P' && (*map)[i + 1][j] == 'C')
			{
				(*map)[i][j] = '2';
				(*map)[i + 1][j] = 'P';
				(*img()).points--;
				i--;
			}
			if ((*map)[i][j] == 'P' && (*map)[i + 1][j] == 'E' && (*img()).points == 0 )
			{
				exit(1);
			}
		}
	}
	return (0);
}
