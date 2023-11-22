/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 08:23:02 by cedmulle          #+#    #+#             */
/*   Updated: 2023/11/22 16:49:43 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int argc, char **argv)
{
	char	**map;
	int		i;

	i = 0;
	if (argc == 2)
	{
		map = get_map(argv[1]);
		if (!map)
			return (1);
		while (map[i])
		{
			ft_printf("%s", map[i]);
			i++;
		}
	}
	return (0);
}
