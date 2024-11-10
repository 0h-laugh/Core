/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaf <olaf@student.1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 15:36:34 by olaf              #+#    #+#             */
/*   Updated: 2024/09/29 15:40:32 by olaf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
	{
		write(2, "Usage: ./fdf <map in .fdf format>\n", 35);
		return (1);
	}
	if (parse_file(&data, av[1]) == -1)
		return (-1);
	generate_map(&data);
	generate_iso_view(data.map);
	if (start_mlx(&data) == -1)
		return (-1);
	return (0);
}
