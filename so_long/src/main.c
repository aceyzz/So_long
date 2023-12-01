/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 08:23:02 by cedmulle          #+#    #+#             */
/*   Updated: 2023/12/01 14:26:24 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	init_args(t_game *info, char *av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	if (av[i - 1] != 'r' || av[i - 2] != 'e'
		|| av[i - 3] != 'b' || av[i - 4] != '.')
		return (ft_error(11));
	info->fd = open(av, O_RDONLY);
	if (info->fd == -1)
		return (ft_error(1));
	info->name_map = av;
	info->x = 0;
	info->y = 0;
	info->coin = 0;
	info->nb_killers = 0;
	return (1);
}

int	main(int argc, char *argv[])
{
	t_game	info;

	if (argc == 2)
	{
		if (!init_args(&info, argv[1]) || !parse_map(&info))
			return (1 + ft_free_info(&info));
		launch_screen(&info);
	}
	else
		ft_printf("Usage : <./so_long> <filename.ber>\n");
	return (0);
}
