/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_killers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 19:35:12 by cedmulle          #+#    #+#             */
/*   Updated: 2023/11/28 10:08:19 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* the killers are located on the map with KILLER 'x'character. */
/* Their numbers are set in the game->nb_killers variable */
/* theses functions moves all the killers on a FLOOR '0' character */
/* it verify the next FLOOR character, and move onto it */

#include "../inc/so_long.h"

static void	move_right(t_game *game, int i, int j)
{
	if (game->map[i][j + 1] == FLOOR)
	{
		game->map[i][j + 1] = KILLER;
		game->map[i][j] = FLOOR;
	}
}

static void	move_left(t_game *game, int i, int j)
{
	if (game->map[i][j - 1] == FLOOR)
	{
		game->map[i][j - 1] = KILLER;
		game->map[i][j] = FLOOR;
	}
}

static void	move_down(t_game *game, int i, int j)
{
	if (game->map[i + 1][j] == FLOOR)
	{
		game->map[i + 1][j] = KILLER;
		game->map[i][j] = FLOOR;
	}
}

static void	move_up(t_game *game, int i, int j)
{
	if (game->map[i - 1][j] == FLOOR)
	{
		game->map[i - 1][j] = KILLER;
		game->map[i][j] = FLOOR;
	}
}

void	move_all_killers(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->y)
	{
		j = 0;
		while (j < game->x)
		{
			if (game->map[i][j] == KILLER)
			{
				if (floor(rand() % 4) == 0)
					move_right(game, i, j);
				else if (floor(rand() % 4) == 1)
					move_left(game, i, j);
				else if (floor(rand() % 4) == 2)
					move_down(game, i, j);
				else if (floor(rand() % 4) == 3)
					move_up(game, i, j);
			}
			j++;
		}
		i++;
	}
}
