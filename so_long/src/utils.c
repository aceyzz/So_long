/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:42:29 by cedmulle          #+#    #+#             */
/*   Updated: 2023/11/27 14:47:26 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	*ft_itoa(int nb)
{
	char	*str;
	int		i;
	int		n;

	n = nb;
	i = 0;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	while (i > 0)
	{
		str[i - 1] = nb % 10 + '0';
		nb /= 10;
		i--;
	}
	return (str);
}

int	ft_error(int error)
{
	if (error == 1)
		ft_printf("File error: ouverture impossible de fichier\n");
	else if (error == 2)
		ft_printf("Map error.\n");
	else if (error == 3)
		ft_printf("Map error: aucune chemin possible.\n");
	else if (error == 4)
		ft_printf("Map error: forme non conforme.\n");
	else if (error == 5)
		ft_printf("Map error: taille non conforme.\n");
	else if (error == 6)
		ft_printf("Map error: les murs doivent être seulement des '1'.\n");
	else if (error == 7)
		ft_printf("Map error: syntaxe ('1', '0', 'E', 'F', 'P' ou 'x').\n");
	else if (error == 8)
		ft_printf("Map error: 1 player, 1 exit, min. 1 item.\n");
	else if (error == 9)
		ft_printf("Malloc error.\n");
	else if (error == 10)
		ft_printf("Map error: item innateignable.\n");
	else if (error == 11)
		ft_printf("File error: extension non reconnue.\n");
	return (0);
}

void	create_tab_killers(t_game *game)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	game->tab_killers = malloc(sizeof(int *) * (game->nb_killers + 1));
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == KILLER)
			{
				game->tab_killers[k] = malloc(sizeof(int) * 2);
				game->tab_killers[k][0] = i;
				game->tab_killers[k][1] = j;
				k++;
			}
			j++;
		}
		i++;
	}
	game->tab_killers[k] = NULL;
}

static void	duplicate_tab(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->map_copy = malloc(sizeof(char *) * (game->y + 1));
	if (!game->map_copy)
		ft_error(9);
	while (i < game->y)
	{
		j = 0;
		game->map_copy[i] = malloc(sizeof(char) * (game->x + 1));
		if (!game->map_copy[i])
			ft_error(9);
		while (j < game->x)
		{
			game->map_copy[i][j] = game->map[i][j];
			j++;
		}
		game->map_copy[i][j] = '\0';
		i++;
	}
	game->map_copy[i] = NULL;
}

void	parse_map_origin(t_game *info)
{
	int	i;

	i = 0;
	info->map = malloc(sizeof(char *) * (info->y + 1));
	if (!info->map)
		ft_error(9);
	while (1)
	{
		info->map[i] = get_next_line(info->fd);
		if (info->map[i] == NULL)
			break ;
		i++;
	}
	duplicate_tab(info);
}
