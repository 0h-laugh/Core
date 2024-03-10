/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:06:40 by ojastrze          #+#    #+#             */
/*   Updated: 2024/03/08 17:43:23 by ojastrze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;

	if (dst == NULL)
		return (0);
	dst_len = ft_strlen(dst);
	src_len = ft_strlen((char *)src);
	if (dst_len >= size)
		dst_len = size;
	if (dst_len == size)
		return (dst_len + src_len);
	if (src_len < size - dst_len)
		ft_memcpy(dst + dst_len, src, src_len + 1);
	else
	{
		ft_memcpy(dst + dst_len, src, size - dst_len - 1);
		dst[size - 1] = '\0';
	}
	return (dst_len + src_len);
}
/*
#include <stdio.h>
#include <string.h>

int main()
{
    char dst1[20] = "aaa";
    char src1[] = "bbb";
    size_t size1 = 5;
    size_t result1 = ft_strlcat(dst1, src1, size1);
    printf("Result 1: %zu, Destination 1: \"%s\"\n", result1, dst1);

    char dst2[20] = "aaa";
    char src2[] = "bbb";
    size_t size2 = 3;
    size_t result2 = ft_strlcat(dst2, src2, size2);
    printf("Result 2: %zu, Destination 2: \"%s\"\n", result2, dst2);

    char dst3[20] = "aaa";
    char src3[] = "bbb";
    size_t size3 = 2;
    size_t result3 = ft_strlcat(dst3, src3, size3);
    printf("Result 3: %zu, Destination 3: \"%s\"\n", result3, dst3);

    char dst4[20] = "aaa";
    char src4[] = "bbb";
    size_t size4 = 0;
    size_t result4 = ft_strlcat(dst4, src4, size4);
    printf("Result 4: %zu, Destination 4: \"%s\"\n", result4, dst4);

    char dst5[20] = "";
    char src5[] = "bbb";
    size_t size5 = 5;
    size_t result5 = ft_strlcat(dst5, src5, size5);
    printf("Result 5: %zu, Destination 5: \"%s\"\n", result5, dst5);

    return 0;
}*/
