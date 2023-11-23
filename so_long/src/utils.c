/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:42:29 by cedmulle          #+#    #+#             */
/*   Updated: 2023/11/23 13:22:39 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_free_info(t_game *info)
{
	int	i;

	i = -1;
	while (++i < info->y)
	{
		free(info->map_copy[i]);
		free(info->map[i]);
	}
	if (info->map)
	{
		free(info->map);
		free(info->map_copy);
	}
	return (0);
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
