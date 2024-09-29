/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:15:40 by ojastrze          #+#    #+#             */
/*   Updated: 2024/06/26 15:53:39 by ojastrze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	i;
	size_t	j;
	char	*res;

	res = NULL;
	if (s1 != NULL && set != NULL)
	{
		i = 0;
		j = ft_strlen((char *) s1);
		while (s1[i] && ft_strchr(set, s1[i]))
			i++;
		while (j > i && ft_strchr(set, s1[j - 1]))
			j--;
		if (i >= j)
			return (ft_strdup(""));
		res = (char *)malloc((j - i + 1) * sizeof(char));
		if (!res)
			return (NULL);
		ft_strlcpy(res, &s1[i], j - i + 1);
		res[j - i] = '\0';
	}
	return (res);
}
