/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_convert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <ojastrze@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 16:07:05 by ojastrze          #+#    #+#             */
/*   Updated: 2026/02/08 16:07:06 by ojastrze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	convert(char *str)
{
	char	arr[3][4];
	int		i;
	int		j;
	int		k;
	int		size;

	i = 0;
	k = 0;
	size = ft_strlen(str);
	while (i < 3)
	{
		j = 0;
		while (k < size && str[k] != ',' && j < 3)
			arr[i][j++] = str[k++];
		arr[i][j] = '\0';
		if (str[k] == ',')
			k++;
		i++;
	}
	return ((ft_atoi(arr[0]) << 16) | (ft_atoi(arr[1]) << 8) | ft_atoi(arr[2]));
}

void	color_convert(t_game *game)
{
	game->textures.floor_color = convert(game->textures.F);
	game->textures.ceeling_color = convert(game->textures.C);
}
