/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:19:35 by ojastrze          #+#    #+#             */
/*   Updated: 2024/06/26 15:50:02 by ojastrze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static int	calc_arr_size(char const *s, char c)
{
	size_t	arr_size;
	size_t	i;

	arr_size = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			arr_size++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	arr_size++;
	return (arr_size);
}

static void	fill_arr(char const *s, char c, char **arr)
{
	size_t	arr_size;
	size_t	i;
	size_t	j;
	size_t	k;

	arr_size = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			j = 0;
			while (s[i + j] && s[i + j] != c)
				j++;
			arr[arr_size] = (char *)malloc((j + 1) * sizeof(char));
			k = 0;
			j = j + i;
			while (i < j)
				arr[arr_size][k++] = s[i++];
			arr[arr_size++][k] = '\0';
		}
	}
	arr[arr_size] = NULL;
}

char	**ft_split(char const *s, char c)
{
	size_t	arr_size;
	char	**arr;	

	if (s == NULL)
		return (NULL);
	arr_size = calc_arr_size(s, c);
	arr = (char **)malloc(arr_size * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	fill_arr(s, c, arr);
	return (arr);
}
